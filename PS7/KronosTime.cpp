// Copyright 2022 Anson Cheang
#include <iostream>
#include <fstream>
#include <string>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include <boost/regex.hpp>

using namespace std;  // NOLINT
using namespace boost;  // NOLINT

using boost::gregorian::date;
using boost::gregorian::from_simple_string;
using boost::gregorian::date_period;
using boost::gregorian::date_duration;

using boost::posix_time::ptime;
using boost::posix_time::time_duration;

int main(int argc, const char* argv[]) {
    int lines_scan = 1;

    string fileName(argv[1]);
    string output_name = fileName + ".rpt";
    string output = "";
    int amount = 0;

    string D;

    ptime begin;
    ptime end;

    date date1;
    date date2;

    time_duration time_diff;

    // format = 2014-01-26 09:55:07: (log.c.166) server started
    // [] for rance {}for repitition
    string start_string = "([0-9]{4})-([0-9]{2})-([0-9]{2}) ";
    start_string += "([0-9]{2}):([0-9]{2}):([0-9]{2}): \\(log\\.c\\.166\\) ";
    start_string += "server started";

    // format = 2014-01-26 09:58:04.362:INFO:oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080 NOLINT
    string end_string = "([0-9]{4})-([0-9]{2})-([0-9]{2}) ";
    end_string += "([0-9]{2}):([0-9]{2}):([0-9]{2}).([0-9]{3}):INFO:oejs.";
    end_string += "AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080";  // NOLINT

    regex start_regex(start_string);
    regex end_regex(end_string);

    smatch sm;

    string line;
    ifstream file(fileName.c_str());
    ofstream out(output_name.c_str());

    bool already = false;

    while (getline(file, line)) {
        output.clear();

        if (lines_scan > 1 && regex_search(line, sm, start_regex) && already == false && amount != 0) {  // NOLINT
            output ="\n";
        }

        if (already == true && regex_search(line, sm, start_regex)) {
            output += "**** Incomplete boot ****\n\n";
        }

        if (regex_search(line, sm, start_regex)) {
            D = sm[1] + "-" + sm[2] + "-" + sm[3];
            // cout << D << endl;
            date1 = date(from_simple_string(D));

            begin = ptime(date1, time_duration(stoi(sm[4]), stoi(sm[5]), stoi(sm[6]))); //NOLINT
            output += "=== Device boot ===\n";
            output += to_string(lines_scan) + "(" + fileName + "): ";
            output += sm[1] + "-" + sm[2] + "-" + sm[3] + " " + sm[4] + ":" + sm[5] + ":" + sm[6]; //NOLINT
            output += " Boot Start\n";

            already = true;
            amount++;
        }

        if (regex_search(line, sm, end_regex) && already == true) {
            D = sm[1] + "-" + sm[2] + "-" + sm[3];
            // cout << D << endl;
            date2 = date(from_simple_string(D));

            end = ptime(date2, time_duration(stoi(sm[4]), stoi(sm[5]), stoi(sm[6]))); //NOLINT

            output += to_string(lines_scan) + "(" + fileName + "): ";
            output += sm[1] + "-" + sm[2] + "-" + sm[3] + " " + sm[4] + ":" + sm[5] + ":" + sm[6]; //NOLINT
            output += " Boot Completed\n";

            time_diff = end - begin;

            output += "\tBoot Time: ";
            output += to_string(time_diff.total_milliseconds()) + "ms\n";

            already = false;
        }
        lines_scan++;
        out << output;
    }
    file.close();

    // out << output;
    out.close();

    return 0;
}

// CopyRight 2022 Anson Cheang, and Andy Nguyen

#include <iostream>
#include <algorithm>
#include <cmath>
#include "EDistance.h"

using namespace std; //NOLINT

/* accepts the two strings to be compared, and allocates any
 data structures necessary into order to do the work
 (e.g., the N×M matrix).*/
EDistance::EDistance(string input_N, string input_M) {
    // n = row, m = column
    n = input_N;
    m = input_M;
}

/* returns the penalty for aligning chars a and b
 (this will be a 0 or 1)*/
int EDistance::penalty(char a, char b) {
    if (a == b) {
        return 0;
    } else {
        return 1;
    }
}

// returns the minimum of the three arguments
int EDistance::min(int a, int b, int c) {
    return std::min({a, b, c});
}

/* populates the matrix based on having the two strings, and returns
 the optimal distance (from the [0][0] cell of the matrix when done).*/
int EDistance::optDistance() {
    int r = n.length();
    int c = m.length();
    int indel = 2;
    int match, del, insert;

    for (int i = 0; i <= c; i++) {
        vector<int> temp;
        matrix.push_back(temp);

        for (int j = 0; j <= r; j++) {
            matrix.at(i).push_back(0);
        }
    }

    for (int i = 0; i <= c; i++) {
        matrix.at(i).at(r) = (c - i) * indel;
    }

    for (int i = 0; i <= r; i++) {
        matrix.at(c).at(i) = (r - i) * indel;
    }

    for (int i = c - 1; i >= 0; i--) {
        for (int j = r - 1; j >= 0; j--) {
            match = matrix.at(i + 1).at(j + 1) + penalty(m.at(i), n.at(j));
            del = matrix.at(i + 1).at(j) + indel;
            insert = matrix.at(i).at(j + 1) + indel;
            matrix.at(i).at(j) = min(match, del, insert);
        }
    }
    return matrix.at(0).at(0);
}

/* traces the matrix and returns a string that can be printed to display
 the actual alignment. In general, this will be a multi-line string — i.e.,
 with embedded \n's.*/
string EDistance::alignment() {
    int indel = 2;
    string retStr;

    int i = 0;
    int j = 0;
    int r = n.length();
    int c = m.length();

    while (i < c || j < r) {
        if (i < c && j < r && matrix.at(i).at(j) == matrix.at(i + 1).at(j + 1) + penalty(m[i], n[j])) { //NOLINT
            retStr = retStr + n[j] + " " + m[i] + " " + to_string(penalty(m[i], n[j])) + "\n"; //NOLINT
            i++;
            j++;
        } else if (i < c && matrix.at(i).at(j) == matrix.at(i + 1).at(j) + indel) { //NOLINT
            retStr = retStr + "-" + " " + m[i] + " " + "2" + "\n";
            i++;
        } else if (j < r && matrix.at(i).at(j) == matrix.at(i).at(j + 1) + indel) { //NOLINT
            retStr = retStr + n[j] + " " + "-" + " " + "2" + "\n";
            j++;
        }
    }
    return retStr;
}

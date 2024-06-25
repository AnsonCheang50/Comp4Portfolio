#ifndef FibLFSR_H_
#define FibLFSR_H_
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class FibLFSR {
public:
FibLFSR(string seed);   // constructor to create LFSR with
                        // the given initial seed
int step();             // simulate one step and return the
                        // new bit as 0 or 1
int generate(int k);    // simulate k steps and return
                        // k-bit integer
friend ostream& operator<<(ostream& out, FibLFSR CurrentBits);
private:
vector<int> list;
};

#endif
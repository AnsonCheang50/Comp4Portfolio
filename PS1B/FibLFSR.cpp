/**
* FibLFSR.cpp - To run the FubLFSR class, in which they constructor, step(),
* and generator(), essentially using Linear feedback shift register
*
* Date 1/24/22 - 1/31/22
*
* Created by: Anson Cheang
*
*/

#include "FibLFSR.h"
#include <vector>
#include <string>
#include <cmath>

using namespace std;

FibLFSR::FibLFSR(string seed)
{
    string Pbit;
    for(int i = 0; i < static_cast <int> (seed.length()); i++)
    {
        Pbit = seed[i];
        list.push_back(stoi(Pbit, 0, 10));
        
    }
}

int FibLFSR::step()
{
    int size = static_cast <int> (list.size());
    int RBit = list[0] ^ list[2] ^ list[3] ^ list[5];
    for(int i = 0; i < size - 1; i++)
    {
        list[i] = list[i+1];
    }

    list[size - 1] = RBit;

    return RBit;
}

int FibLFSR::generate(int k)
{
    if(k > 32 || k < 0)
    {
        throw out_of_range("The value inputted isn't within the range of 0 - 32");
    }
    int RBit;
    int total = 0;
    for(int i = 0; i < k; i++)
    {
        RBit = step();
        total = total + pow(2, k-i-1) * RBit;
    }

    return total;
}

ostream& operator<<(ostream& out, FibLFSR CurrentBits)
{
    vector<int>::iterator it;
    for(it = CurrentBits.list.begin(); it != CurrentBits.list.end(); it++)
    {
        out << *it;
    }
    return out;
}
// Copyright 2022 Anson Cheang, and Andy Nguyen
#ifndef _HOME_IIFORCE_BADNAME_COMP4_PS6_RANDWRITER_H_
#define _HOME_IIFORCE_BADNAME_COMP4_PS6_RANDWRITER_H_

#include <iostream>
#include <string>
#include <map>

using namespace std; //NOLINT

class RandWriter {
 public:
// create a Markov model of order k from given text
RandWriter(string text, int k);  // Assume that text has length at least k.
// -------------------------------------------------------------------
int orderK() const;  // order k of Markov model
// -------------------------------------------------------------------
// number of occurrences of kgram in text
int freq(string kgram) const;  // throw an exception if kgram is not of
// length k
// -------------------------------------------------------------------
// number of times that character c follows kgram
// if order=0, return num of times char c appears
// (throw an exception if kgram is not of length k)
int freq(string kgram, char c) const;
// -------------------------------------------------------------------
// random character following given kgram
// (Throw an exception if kgram is not of length k.
// Throw an exception if no such kgram.)
char kRand(string kgram);
// -------------------------------------------------------------------
// generate a string of length L characters
// by simulating a trajectory through the corresponding
// Markov chain. The first k characters of the newly
// generated string should be the argument kgram.
// Throw an exception if kgram is not of length k.
// Assume that L is at least k.
string generate(string kgram, int L);
// -------------------------------------------------------------------
friend ostream& operator<<(ostream& out, RandWriter& markov);
// overload the stream insertion operator and display
// the internal state of the Markov Model. Print out
// the order, the alphabet, and the frequencies of
// the k-grams and k+1-grams.

 private:
string alphabet; //NOLINT
int order;
map<string, map<char, int>> RM;
};

ostream& operator<<(ostream& out, RandWriter& markov);

#endif  // _HOME_IIFORCE_BADNAME_COMP4_PS6_RANDWRITER_H_

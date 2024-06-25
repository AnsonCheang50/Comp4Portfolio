// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

//test.cpp
//updated 1/30/22-1/31/22
//updated by Anson Cheang



#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <sstream>
#include <string>

#include "FibLFSR.h"


BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  
  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
}

BOOST_AUTO_TEST_CASE(testCase2) {
  
  FibLFSR l2("0000000000000000");
  BOOST_REQUIRE_THROW(l2.generate(33), out_of_range);
  BOOST_REQUIRE_THROW(l2.generate(-1), out_of_range);
}

BOOST_AUTO_TEST_CASE(testCase3) {
  FibLFSR l("1100110011001100");
  stringstream ss;
  ss << l;
  BOOST_REQUIRE_EQUAL(ss.str(), "1100110011001100");
  ss.str("");
  l.generate(5);
  ss << l;
  BOOST_REQUIRE_EQUAL(ss.str(), "1001100110000000");
  
}


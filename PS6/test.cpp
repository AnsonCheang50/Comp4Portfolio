// Copyright 2022 Anson Cheang
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include "RandWriter.h"

#include <iostream>
#include <sstream>
#include <string>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(order0) {
  BOOST_REQUIRE_NO_THROW(RandWriter("gagggagaggcgagaaa", 0));

  RandWriter mm("gagggagaggcgagaaa", 0);

  BOOST_REQUIRE(mm.orderK() == 0);
  BOOST_REQUIRE(mm.freq("") == 17);
  BOOST_REQUIRE_THROW(mm.freq("t"), std::runtime_error);

  BOOST_REQUIRE(mm.freq("", 'g') == 9);
  BOOST_REQUIRE(mm.freq("", 'a') == 7);
  BOOST_REQUIRE(mm.freq("", 'c') == 1);
  BOOST_REQUIRE(mm.freq("", 'x') == 0);
}

BOOST_AUTO_TEST_CASE(order1) {
  RandWriter mm("gagggagaggcgagaaa", 1);

  BOOST_REQUIRE_THROW(mm.freq(""), std::runtime_error);

  BOOST_REQUIRE(mm.freq("a") == 7);
  BOOST_REQUIRE(mm.freq("g") == 9);
  BOOST_REQUIRE(mm.freq("c") == 1);

  BOOST_REQUIRE(mm.freq("a", 'a') == 2);
  BOOST_REQUIRE(mm.freq("a", 'c') == 0);
  BOOST_REQUIRE(mm.freq("a", 'g') == 5);

  BOOST_REQUIRE_NO_THROW(mm.kRand("a"));

  BOOST_REQUIRE_THROW(mm.kRand("t"), std::runtime_error);

  BOOST_REQUIRE_THROW(mm.kRand("tt"), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(order2) {
  RandWriter mm("gagggagaggcgagaaa", 2);

  BOOST_REQUIRE_NO_THROW(mm.freq("aa"));
  BOOST_REQUIRE_THROW(mm.freq("", 'g'), std::runtime_error);

  BOOST_REQUIRE(mm.freq("aa") == 2);
  BOOST_REQUIRE(mm.freq("aa", 'a') == 1);
}

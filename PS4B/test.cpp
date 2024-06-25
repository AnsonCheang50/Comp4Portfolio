// Copyright 2022 Anson Cheang
// test.cpp
// updated 1/30/22-1/31/22
// updated by Anson Cheang

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include "CircularBuffer.h"
#include "StringSound.h"

#include <iostream>
#include <sstream>
#include <string>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {
    BOOST_REQUIRE_THROW(StringSound l(0), std::invalid_argument);
    BOOST_REQUIRE_THROW(StringSound l2(-1), std::invalid_argument);
    BOOST_REQUIRE_NO_THROW(StringSound l3(5));
    StringSound l3(5);
    BOOST_REQUIRE_THROW(l3.tic(), std::runtime_error);
    BOOST_REQUIRE_THROW(l3.sample(), std::runtime_error);
    l3.pluck();
    BOOST_REQUIRE_NO_THROW(l3.tic());
    BOOST_REQUIRE_NO_THROW(l3.sample());
}

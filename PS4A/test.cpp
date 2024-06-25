// Copyright 2022 Anson Cheang
// test.cpp
// updated 1/30/22-1/31/22
// updated by Anson Cheang

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include "CircularBuffer.h"

#include <iostream>
#include <sstream>
#include <string>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {
    BOOST_REQUIRE_THROW(CircularBuffer l(0), std::invalid_argument);

    CircularBuffer l2(5);
    BOOST_REQUIRE(l2.isFull() == false);
    BOOST_REQUIRE(l2.isEmpty() == true);
    BOOST_REQUIRE_THROW(l2.dequeue(), std::runtime_error);
    BOOST_REQUIRE_THROW(l2.peek(), std::runtime_error);

    l2.enqueue(1);
    l2.enqueue(2);
    l2.enqueue(3);
    BOOST_REQUIRE(l2.isFull() == false);
    BOOST_REQUIRE(l2.isEmpty() == false);
    l2.enqueue(4);
    l2.enqueue(5);

    BOOST_REQUIRE_THROW(l2.enqueue(6), std::runtime_error);
    BOOST_REQUIRE(l2.peek() == 1);
    BOOST_REQUIRE(l2.size() == 5);
    BOOST_REQUIRE(l2.isFull() == true);
    BOOST_REQUIRE(l2.isEmpty() == false);
    BOOST_REQUIRE(l2.dequeue() == 1);
    BOOST_REQUIRE(l2.peek() == 2);
    BOOST_REQUIRE(l2.size() == 4);
}

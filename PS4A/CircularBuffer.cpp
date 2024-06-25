// Copyright 2022 Anson Cheang
#include "CircularBuffer.h"
#include <iostream>
#include <string>

CircularBuffer::CircularBuffer(size_t capacity) {
    std::string message =
    "CircularBuffer constructor: capacity must be greater than zero";
    if (capacity < 1) {
        throw std::invalid_argument(message);
    }
    maxCapacity = capacity;
}

size_t CircularBuffer::size() {
    return list.size();
}

bool CircularBuffer::isEmpty() {
    if (list.size() != 0) {
        return false;
    } else {
        return true;
    }
}

bool CircularBuffer::isFull() {
    if (list.size() != maxCapacity) {
        return false;
    } else {
        return true;
    }
}

void CircularBuffer::enqueue(int16_t x) {
    if (list.size() >= maxCapacity) {
        throw std::runtime_error("enqueue: can't enqueue to a full ring");
    }
    list.push_back(x);
}

int16_t CircularBuffer::dequeue() {
    if (list.size() <= 0) {
        throw std::runtime_error("dequeue: can't dequeue an empty ring");
    }
    int16_t val = list.front();
    list.pop_front();
    return val;
}

int16_t CircularBuffer::peek() {
    if (list.size() <= 0) {
        throw std::runtime_error("peek: can't peek an empty ring");
    }
    return list[0];
}

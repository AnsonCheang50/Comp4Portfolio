// Copyright 2022 Anson Cheang
#ifndef _HOME_IIFORCE_BADNAME_COMP4_PS4A_CIRCULARBUFFER_H_
#define _HOME_IIFORCE_BADNAME_COMP4_PS4A_CIRCULARBUFFER_H_

#include <stdint.h>
#include <cstdlib>
#include <deque>

class CircularBuffer {
 public:
CircularBuffer(size_t capacity);  // create an empty ring buffer,
// with given max capacity
size_t size();  // return number of items currently in the buffer
bool isEmpty();  // is the buffer empty (size equals zero)?
bool isFull();  // is the buffer full (size equals capacity)?
void enqueue(int16_t x);  // add item x to the end
int16_t dequeue();  // delete and return item from the front
int16_t peek();  // return (but do not delete) item from the front

 private:
std::deque<int16_t> list;
size_t currentSize;
size_t maxCapacity;
};

#endif  // _HOME_IIFORCE_BADNAME_COMP4_PS4A_CIRCULARBUFFER_H_

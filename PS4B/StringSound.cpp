// Copyright 2022 Anson Cheang

// This class is used to create the sound used by KSGuitarSim.cpp

#include "StringSound.h"
#include <time.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <random>
#include <chrono> //NOLINT

#define SAMPLING_RATE 44100

StringSound::StringSound(double frequency) {
    if (frequency <= 0) {
        throw std::invalid_argument(
            "StringSound(double frequency) : cant accept values of 0 or lower");
    }
    size_t _size = ceil(SAMPLING_RATE/frequency);
    _cb = new CircularBuffer(_size);
    _time = 0;
}

StringSound::StringSound(std::vector <sf::Int16> init) {
    _cb = new CircularBuffer(init.size());
    std::vector<sf::Int16>::iterator p;
    p = init.begin();
    while (p != init.end()) {
        _cb->enqueue(*p);
        p++;
    }
    _time = 0;
}

StringSound::~StringSound() {
    delete _cb;
    _cb = nullptr;
}

void StringSound::pluck() {
    if (_cb->size() <= 0) {
        while (!_cb->isEmpty()) {
            _cb->dequeue();
        }
    }

    unsigned int secret = std::chrono::system_clock::now().time_since_epoch().count();//NOLINT
    std::mt19937 gen(secret);
    while (!_cb->isFull()) {
      // generate random number
      std::uniform_int_distribution<int16_t> dist(-32768, 32767);
      _cb->enqueue(dist(gen));
      }
}

void StringSound::tic() {
    if (!(_cb->isFull())) {
        throw std::runtime_error("Tic() : The list isn't full");
    }
    // size_t size = _cb->size();
    sf::Int16 val1 = _cb->dequeue();
    sf::Int16 val2 = _cb->peek();
    sf::Int16 new_val = .996 * ((val1 + val2) / 2);

    _cb->enqueue(new_val);

    _time++;
}

sf::Int16 StringSound::sample() {
    if (_cb->isEmpty()) {
        throw std::runtime_error("sample() : _cb is empty");
    }
    sf::Int16 sample = _cb->peek();

    return sample;
}

int StringSound::time() {
    return _time;
}

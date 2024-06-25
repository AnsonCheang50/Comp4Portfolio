// Copyright 2022 Anson Cheang
#ifndef _HOME_IIFORCE_BADNAME_COMP4_PS4B_STRINGSOUND_H_
#define _HOME_IIFORCE_BADNAME_COMP4_PS4B_STRINGSOUND_H_

#include "CircularBuffer.h"
#include <stdint.h>
#include <iostream>
#include <cstdlib>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class StringSound {
 public:
explicit StringSound(double frequency);
explicit StringSound(std::vector <sf::Int16> init);
StringSound (const StringSound &obj) = delete;  // no copy const
~StringSound();
void pluck();
void tic();
sf::Int16 sample();
int time();
 private:
CircularBuffer * _cb;
int _time;
};

#endif  // _HOME_IIFORCE_BADNAME_COMP4_PS4B_STRINGSOUND_H_

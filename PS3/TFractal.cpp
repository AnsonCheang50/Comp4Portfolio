// Copyright 2022 Anson Cheang
/**
* TFractal.cpp - essentially the main function, 
which calls upon the recursive function to create 
each new triangle and draw them out in different color
*
* Date 2/22/22 - 2/28/22
*
* Created by: Anson Cheang
*
*/
#include "Triangle.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// using namespace std;

void fTree(sf::RenderWindow& window, Triangle ET, double size, int depth);

int main(int argc, char* argv[]) {
    /*double windowSize = atoi(argv[1]);
    double currentSize = atoi(argv[1]);
    for(int i = 1; i < atoi(argv[2]); i++)
    {
        currentSize = (sqrt(3)/4) * pow(currentSize, 2);
        currentSize = currentSize/4;
        currentSize = currentSize * 4/sqrt(3);
        currentSize = sqrt(currentSize);
        windowSize += currentSize;
    }*/

    sf::RenderWindow window(sf::VideoMode(700, 700), "Input");
    double height = sqrt(3)/2*atoi(argv[1]);
    sf::Vector2f position;
    position.x = (700/2) - atoi(argv[1])/2;
    position.y = (700/2) - (height/2);
    Triangle triangle(atoi(argv[1]), position, 'n');

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        fTree(window, triangle, atoi(argv[1]), atoi(argv[2]));
        // window.draw(triangle);
        window.display();
    }

    return 0;
}

void fTree(sf::RenderWindow& window, Triangle ET, double size, int depth) {
    window.draw(ET);
    if (depth > 0) {
        sf::Vector2f position = ET.getP1();
        size = size/2;
        position.y = position.y - size * sqrt(3) / 2;
        position.x = position.x - size/2;
        Triangle T1(size, position, 'g');
        fTree(window, T1, size, depth - 1);
        // position = ET.getP2();
        Triangle T2(size, ET.getP2(), 'r');
        fTree(window, T2, size, depth - 1);
        position = ET.getP3();
        position.x = position.x - size;
        Triangle T3(size, position, 'b');
        fTree(window, T3, size, depth - 1);
    }
}

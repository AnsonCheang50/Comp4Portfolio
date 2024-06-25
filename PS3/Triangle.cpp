// Copyright 2022 Anson Cheang
/**
* Triangle.cpp - as an implementation to create a new triangle object to store every point
and draw out the triangle at a moments notice
*
* Date 2/22/22 - 2/28/22
*
* Created by: Anson Cheang
*
*/
#include "Triangle.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// using namespace std;


Triangle::Triangle(double val, sf::Vector2f position, char color) {
    size = val;
    sf::Vector2f point1 = position, point2 = position;
    point1.x = point1.x + val;
    point2.x = (position.x + point1.x)/2;
    point2.y = point2.y + sqrt(3)/2 * val;
    P1 = position;
    P2 = point1;
    P3 = point2;
    shape.setPointCount(3);
    shape.setPoint(0, position);
    shape.setPoint(1, point1);
    shape.setPoint(2, point2);
    shape.setOutlineThickness(1);
    if (color == 'g') {
        shape.setOutlineColor(sf::Color::Green);
    } else if (color == 'r') {
        shape.setOutlineColor(sf::Color::Red);
    } else if (color == 'b') {
        shape.setOutlineColor(sf::Color::Blue);
    } else {
        shape.setOutlineColor(sf::Color::Black);
    }
}

sf::Vector2f Triangle::getP1() {
    return P1;
}

sf::Vector2f Triangle::getP2() {
    return P2;
}

sf::Vector2f Triangle::getP3() {
    return P3;
}

void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}

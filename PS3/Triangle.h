// Copyright 2022 Anson Cheang
#ifndef _HOME_IIFORCE_BADNAME_COMP4_PS3_TRIANGLE_H_  // Triangle_H_
#define _HOME_IIFORCE_BADNAME_COMP4_PS3_TRIANGLE_H_  // Triangle_H_

#include <string>
#include <cstdlib>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Triangle : public sf::Drawable{
 public:
Triangle(double val, sf::Vector2f position, char color);
sf::Vector2f getP1();
sf::Vector2f getP2();
sf::Vector2f getP3();

 private:
void draw(sf::RenderTarget& target, sf::RenderStates states) const;
double size;
sf::Vector2f P1;
sf::Vector2f P2;
sf::Vector2f P3;
sf::ConvexShape shape;
};


#endif  // _HOME_IIFORCE_BADNAME_COMP4_PS3_TRIANGLE_H_

#ifndef CelestialBody_H_
#define CelestialBody_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class CelestialBody : public sf::Drawable
{
public:

CelestialBody(double val);
void createImage();

CelestialBody(double posX, double posY, double Xvel, double Yvel, double Imass, string _filename);
friend istream& operator>>(istream& instream, CelestialBody& planet);
friend ostream& operator<<(ostream& out, CelestialBody planet);

void setPos(sf::Vector2f Pos);
void setVel(sf::Vector2f Vel);
void setImagePos();
double getXPos();
double getYPos();
double getMass();
double getXVel();
double getYVel();

private:

void draw(sf::RenderTarget& target, sf::RenderStates states) const;
double XPosition;
double YPosition;
double XVelocity;
double YVelocity;
double Mass;
double scale;
string filename;
sf::Image image;
sf::Texture texture;
sf::Sprite sprite;
};


istream& operator>>(istream& instream, CelestialBody& planet);
ostream& operator<<(ostream& out, CelestialBody planet);

#endif
/**
* CelestialBody.cpp - an implementation to create each celestial body 
* 1 at a time, and also place them into the correct location
* for drawing. plus draw each one individually, and overode >> operator
*
* Date 2/14/22 - 2/22/22
*
* Created by: Anson Cheang
*
*/

#include "CelestialBody.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

CelestialBody::CelestialBody(double val)
{
    scale = val;
    XPosition = 0;
    YPosition = 0;
    XVelocity = 0;
    YVelocity = 0;
    Mass = 0;
    filename = "";
}


void CelestialBody::createImage()
{
    if(!image.loadFromFile(filename))
    {
        exit(-1);
    }

    texture.loadFromImage(image);

    sprite.setTexture(texture);
    sf::Vector2u size = image.getSize();
    sprite.setOrigin(static_cast<int>(size.x)/2, static_cast<int>(size.y)/2);
    sprite.setPosition(sf::Vector2f(XPosition*scale + 350, YPosition*scale + 350));
}

CelestialBody::CelestialBody(double posX, double posY, double Xvel, double Yvel, double Imass, string _filename)
{
    XPosition = posX;
    YPosition = posY;
    XVelocity = Xvel;
    YVelocity = Yvel;
    Mass = Imass;
    filename = _filename;

    if(!image.loadFromFile(filename))
    {
        exit(-1);
    }

    texture.loadFromImage(image);

    sprite.setTexture(texture);
    sf::Vector2u size = image.getSize();
    sprite.setOrigin(static_cast<int>(size.x)/2, static_cast<int>(size.y)/2);
    sprite.setPosition(sf::Vector2f(posX, posY));
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

istream& operator>>(istream& instream, CelestialBody& planet)
{
    instream >> planet.XPosition >> planet.YPosition >> planet.XVelocity >> planet.YVelocity >> planet.Mass >> planet.filename;
    return instream;
}

void CelestialBody::setPos(sf::Vector2f Pos)
{
    XPosition = Pos.x;
    YPosition = Pos.y;
}

void CelestialBody::setVel(sf::Vector2f Vel)
{
    XVelocity = Vel.x;
    YVelocity = Vel.y;
}

double CelestialBody::getXPos()
{
    return XPosition;
}

double CelestialBody::getYPos()
{
    return YPosition;
}

double CelestialBody::getMass()
{
    return Mass;
}

void CelestialBody::setImagePos()
{
    //double CX = (Pos.x - XPosition) * scale;
    //double CY = (Pos.y - YPosition) * scale;
    sprite.setPosition(sf::Vector2f(XPosition*scale + 350, YPosition*scale + 350));
    //cout << XPosition*scale + 350 << ", " << YPosition*scale + 350 << endl;
    //XPosition = Pos.x;
    //YPosition = Pos.y;
}

double CelestialBody::getXVel()
{
    return XVelocity;
}

double CelestialBody::getYVel()
{
    return YVelocity;
}


ostream& operator<<(ostream& out, CelestialBody planet)
{
    out << planet.XPosition << "  " << planet.YPosition << "  " << planet.XVelocity << "  " 
        << planet.YVelocity << "  " << planet.Mass << "  " << planet.filename << endl;
    return out;
}
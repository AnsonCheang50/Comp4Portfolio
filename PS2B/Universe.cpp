/**
* Universe.cpp - as an implementation to store every CelestialBody object
* in order to have them created, and draw them out, essentially storage
* and also to do the physics to make each individual particle move in rotation
*
* Date 2/14/22 - 2/22/22
*
* Created by: Anson Cheang
*
*/

#include "Universe.h"
#include <cmath>

Universe::Universe(int size)
{
    //double posX, posY, Xvel, Yvel, Imass;
    double radius, scale;
    galaxySize = size;
    //string filename;
    cin >> radius;
    maxR = radius;
    scale = 350/radius;
    //double scaledXPos, scaledYPos;
    for(int i = 0; i < size; i++)
    {
        galaxy.push_back(make_unique<CelestialBody>(scale));
        cin >> *(galaxy[i]);
        galaxy[i]->createImage();
        //cin >> posX >> posY >> Xvel >> Yvel >> Imass >> filename;
        //scaledXPos = posX*scale + 350;
        //scaledYPos = posY*scale + 350;
        //galaxy.push_back(make_unique<CelestialBody>(scaledXPos, scaledYPos, Xvel, Yvel, Imass, filename));
    }
}

void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int i = 0; i < galaxySize; i++)
    {
        target.draw(*(galaxy[i]), states);
    }
}

void Universe::step(double second)
{
    sf::Vector2f netForce;
    sf::Vector2f Accelleration;
    sf::Vector2f velocity;
    sf::Vector2f p;
    double CX, CY;
    double radius;
    double grav = 6.67e-11;
    double force;
    for(int i = 0; i < galaxySize; i++)
    {
        netForce.x = 0;
        netForce.y = 0;
        for(int j = 0; j < galaxySize; j++)
        {
            if(i != j)
            {
                CX = galaxy[i]->getXPos()-galaxy[j]->getXPos();
                CY = galaxy[i]->getYPos()-galaxy[j]->getYPos();
                radius = sqrt(pow(CX, 2) + pow(CY, 2));
                force = (grav * galaxy[i]->getMass() * galaxy[j]->getMass())/pow(radius, 2);
                netForce.x += force * (CX/radius);
                netForce.y += force * (CY/radius);
            }
        }
        Accelleration.x = netForce.x/galaxy[i]->getMass();
        Accelleration.y = netForce.y/galaxy[i]->getMass();

        velocity.x = galaxy[i]->getXVel() + second * Accelleration.x;
        velocity.y = galaxy[i]->getYVel() + second * Accelleration.y;
        galaxy[i]->setVel(velocity);

        p.x = galaxy[i]->getXPos() + -(second * velocity.x);
        p.y = galaxy[i]->getYPos() + -(second * velocity.y);
        galaxy[i]->setPos(p);
        galaxy[i]->setImagePos();
    }
}

ostream& operator<<(ostream& out, const Universe& space)
{
    out << space.galaxySize << endl;
    out << space.maxR << endl;
    for(int i = 0; i < space.galaxySize; i++)
    {
        out << *(space.galaxy[i]);
    }
    return out;
}
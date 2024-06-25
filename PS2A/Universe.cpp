/**
* Universe.cpp - as an implementation to store every CelestialBody object
* in order to have them created, and draw them out, essentially storage
*
* Date 2/7/22 - 2/14/22
*
* Created by: Anson Cheang
*
*/

#include "Universe.h"

Universe::Universe(int size)
{
    //double posX, posY, Xvel, Yvel, Imass;
    double radius, scale;
    galaxySize = size;
    //string filename;
    cin >> radius;
    scale = 350/radius;
    //double scaledXPos, scaledYPos;
    for(int i = 0; i < size; i++)
    {
        galaxy.push_back(make_unique<CelestialBody>(scale));
        cin >> *(galaxy[i].get());
        galaxy[i].get()->createImage();
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
        target.draw(*(galaxy[i].get()), states);
    }
}
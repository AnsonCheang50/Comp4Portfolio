#ifndef Universe_H_
#define Universe_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "CelestialBody.h"

using namespace std;

class Universe : public sf::Drawable
{
public:
    Universe(int size);
private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    int galaxySize;
    vector<unique_ptr <CelestialBody>> galaxy;
};

#endif
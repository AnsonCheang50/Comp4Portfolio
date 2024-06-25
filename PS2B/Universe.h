#ifndef Universe_H_
#define Universe_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "CelestialBody.h"

using namespace std;

class Universe : public sf::Drawable
{
public:
    Universe(int size);
    void step(double seconds);
    friend ostream& operator<<(ostream& out, const Universe& Galaxy);
private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    int galaxySize;
    double maxR;
    vector<unique_ptr<CelestialBody> > galaxy;
};

ostream& operator<<(ostream& out, const Universe& Galaxy);

#endif
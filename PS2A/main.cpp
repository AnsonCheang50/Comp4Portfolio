/**
* main.cpp - as a base to run the program
*
* Date 2/7/22 - 2/14/22
*
* Created by: Anson Cheang
*
*/

/*#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>*/
#include "CelestialBody.h"
#include "Universe.h"

using namespace std;

int main(int argc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "Input");
    sf::Image image;
    if(!image.loadFromFile("starfield.jpg"))
    {
        return -1;
    }
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::Vector2u size = image.getSize();
    sprite.setScale((1+700/size.x),(1+700/size.y));
    
    int amount;

    cin >> amount;

    Universe space(amount);

    while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
            {
				window.close();
            }
		}

		window.clear();
        window.draw(sprite);
        window.draw(space);
		window.display();
	}

    return 0;
}
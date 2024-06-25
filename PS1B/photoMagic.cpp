/**
* photoMagic.cpp - Essentially to encode and decode an image using the FibLFSR
* that was programmed back in ps1a as an assignment
*
* Date 2/1/22 - 2/7/22
*
* Created by: Anson Cheang
*
*/

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.h"

// transforms image using FibLFSR
void transform( sf::Image&, FibLFSR*);

// display an encrypted copy of the picture, using the LFSR
// to do the encryption
int main(int argc, char* argv[])
{
    sf::Image image1;
    FibLFSR encryptionCode(argv[3]);
	if (!image1.loadFromFile(argv[1]))
    {
		return -1;
    }

	sf::Vector2u size = image1.getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Input");

	sf::Texture texture;
	texture.loadFromImage(image1);

	sf::Sprite sprite;
	sprite.setTexture(texture);

    transform(image1, &encryptionCode);
    
    sf::Vector2u size2 = image1.getSize();
	sf::RenderWindow window2(sf::VideoMode(size2.x, size2.y), "Output");

	sf::Texture texture2;
	texture2.loadFromImage(image1);

	sf::Sprite sprite2;
	sprite2.setTexture(texture2);

    while (window1.isOpen() && window2.isOpen()) 
    {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            {
                window1.close();
            }
        }
        while (window2.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
            {
                window2.close();
            }
        }
        window1.clear();
        window1.draw(sprite);
        window1.display();
        window2.clear();
        window2.draw(sprite2);
        window2.display();
    }

    if (!image1.saveToFile(argv[2]))
	{
        return -1;
    }

    return 0;
}

void transform( sf::Image& image, FibLFSR* encryptionCode)
{
    sf::Color p;
	sf::Vector2u size = image.getSize();

	// create photographic negative image of upper-left 200 px square
	for (int x = 0; x < static_cast<int>(size.x); x++) {
		for (int y = 0; y < static_cast<int>(size.y); y++) {
			p = image.getPixel(x, y);
			p.r = p.r ^ encryptionCode->generate(8);
			p.g = p.g ^ encryptionCode->generate(8);
			p.b = p.b ^ encryptionCode->generate(8);
			image.setPixel(x, y, p);
		}
	}
}
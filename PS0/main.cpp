/**
* main.cpp - testing out sfml, making them move and using the window
*
* Date 1/19/22 - 1/24/22
*
* Created by: Anson Cheang
*
*/

#include <SFML/Graphics.hpp>

int main()
{
	float Gx = 10.f, Gy = 10.f;
	sf::RenderWindow window(sf::VideoMode(900, 800), "Hello World!");

	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(15);

	sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

	sf::Texture texture;
	if(!texture.loadFromFile("sprite.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite sprite(texture);

	sprite.setScale(sf::Vector2f(.3, .3));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		shape.move(Gx, Gy);
		if(shape.getPosition().x >= 600.f)
		{
			Gx = -10.f;
			Gy = -10.f;
		}
		else if (shape.getPosition().x <= 0.f)
		{
			Gx = 10.f;
			Gy = 10.f;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite.getPosition().x > 0.f)
		{
			sprite.move(-10.f, 0.f);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sprite.getPosition().x < 600.f)
		{
			sprite.move(10.f, 0.f);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sprite.getPosition().y < 600.f)
		{
			sprite.move(0.f, 10.f);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sprite.getPosition().y > 0.f)
		{
			sprite.move(0.f, -10.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			sprite.rotate(90);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			sprite.setScale(sf::Vector2f(.3, -.3));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			sprite.setScale(sf::Vector2f(.3, .3));
		}

		window.clear();
		window.draw(shape);
		window.draw(sprite);
		window.display();
	}

	return 0;
}

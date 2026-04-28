#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Player.h"
#include "Ennemi.h"
#include <vector>

int main() {

	sf::RenderWindow window( sf::VideoMode( { 1600, 1000 } ), "SFML works!" );
	sf::CircleShape shape( 40.f );
	shape.setFillColor( sf::Color::Green );
	sf::Texture texture(ASSETS_PATH"rat.png");
	sf::Texture cheeseT(ASSETS_PATH"rat.png");
	sf::CircleShape s1(40.f);
	s1.setPosition({400.f,400.f});
	sf::Clock ennemiClock;
	sf::Font font("../../ARIAL.TTF");
	sf::Text text(font);
	Player rat(texture);
	sf::U8StringCharTraits::int_type health = rat.getHealth();
	Ennemi* ennemy = new Ennemi(0.1f,cheeseT,rat.getSprite());
	ennemy->setSpawn(s1);
	bool isAlive = true;



	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}



		//if(rat.getGlobalBounds().findIntersection(shape.getGlobalBounds()))
		// {
		// 	isAlive = false;
		// }
		window.clear();
		rat.renderPlayer(window);
		if (isAlive)
		{
			ennemy->renderEnnemy(window);
			ennemy->setDirection(rat.getSprite());
			ennemy->moveEnnemy();
		}
		rat.displayHealth(window);
		window.display();
		rat.movePlayer();





	}
}

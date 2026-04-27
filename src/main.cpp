#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Ennemi.h"
#include <vector>

int main() {

	sf::RenderWindow window( sf::VideoMode( { 1600, 1000 } ), "SFML works!" );
	sf::CircleShape* shape = new sf::CircleShape( 40.f );
	sf::CircleShape s1(40.f);
	s1.setPosition({400.f,400.f});
	shape->setFillColor( sf::Color::Green );
	sf::Texture texture(ASSETS_PATH "rat_copy.PNG");
	sf::Texture cheeseT(ASSETS_PATH "rat_copy.PNG");
	sf::Clock ennemiClock;
	Player rat(texture);
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


		if (ennemy != nullptr) {
			if(rat.getGlobalBounds().findIntersection(ennemy->getGlobalBounds()))
			{
				isAlive = false;
				ennemy = nullptr;
				std::cout << rat.reduceHealth() << '\n';
			}
		}

		window.clear();
		rat.renderPlayer(window);
		if (isAlive)
		{
			ennemy->renderEnnemy(window);
			ennemy->setDirection(rat.getSprite());
			ennemy->moveEnnemy();
		}
		window.display();
		rat.movePlayer();



	}
}

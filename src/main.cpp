#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

int main() {
	sf::RenderWindow window( sf::VideoMode( { 800, 800 } ), "Labyrinth of STL" );
	Player joueur;
	bool isAlive = true;

	sf::CircleShape shape( 40.f );
	shape.setFillColor( sf::Color::Green );

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}
		if(joueur.getGlobalBounds().findIntersection(shape.getGlobalBounds()))
		{
			isAlive = false;
		}
		window.clear();
		joueur.movements();
		window.draw( joueur );
		if (isAlive)
		{
			window.draw( shape );
		}
		window.display();

	}
}

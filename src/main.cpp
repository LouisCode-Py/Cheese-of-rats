#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

int main() {
	sf::RenderWindow window( sf::VideoMode( { 800, 800 } ), "SFML works!" );
	//sf::Texture texture("rat.jpg");
	//Player joueur(texture);
	Player joueur;

	sf::CircleShape shape( 40.f );
	shape.setFillColor( sf::Color::Green );

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		window.clear();
		joueur.movements();
		window.draw( joueur );
		window.draw( shape );
		window.display();

	}
}

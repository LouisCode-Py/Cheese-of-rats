#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Ennemi.h"
#include <vector>

int main() {

	sf::RenderWindow window( sf::VideoMode( { 1600, 1000 } ), "SFML works!" );
	sf::CircleShape shape( 40.f );
	shape.setFillColor( sf::Color::Green );
	sf::Texture texture("../../rat.jpg");
	sf::Texture cheeseT("../../rat.jpg");
	sf::Clock ennemiClock;
	Player rat(texture);
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
		rat.RenderPlayer(window);
		window.display();
		// if (isAlive)
		// {
		// 	window.draw( shape );
		// }




		rat.movePlayer();





	}
}

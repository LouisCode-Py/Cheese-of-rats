#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Player.h"
#include "Ennemi.h"
#include <vector>
#include "Wave.h"

int main() {

	sf::RenderWindow window( sf::VideoMode( { 1600, 1000 } ), "SFML works!" );
	sf::CircleShape shape( 40.f );
	shape.setFillColor( sf::Color::Green );
	sf::Texture texture("../../rat.png");
	sf::Texture cheeseT("../../rat.png");
	sf::Clock ennemiClock;
	sf::Font font("../../ARIAL.TTF");
	sf::Text text(font);
	Player rat(texture);
	bool isAlive = true;
	Wave wave(1.f);
	std::vector<Ennemi*> ennemiQueue;
	wave.makeTheQueue(0.001f,cheeseT,rat.getSprite(),1);
	ennemiQueue =  wave.PassQueue();
	int n=0;
	int waves = 1;

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

		if (ennemiQueue.empty()) {
			waves++;
			wave.makeTheQueue(0.001f,cheeseT,rat.getSprite(),1);
			ennemiQueue = wave.PassQueue();
			n =0;
		}
		window.clear();
		text.setString("wave:"+ std::to_string(waves));
		rat.RenderPlayer(window);
		window.draw (shape);
		window.draw(text);
		shape.setPosition({500.f,500.f});

		if (!ennemiQueue.empty()) {
			for (int i = 0; i < n; i++) {
				window.draw(ennemiQueue[i]->getSprite());
				ennemiQueue[i]->moveEnnemi();

			}
		}
		window.display();
		// if (isAlive)
		// {
		// 	window.draw( shape );
		// }

		rat.movePlayer();

		if (wave.ifSpawnable(ennemiClock)) {
			ennemiQueue[n]->setSpawn(shape);
			sf::Vector2f position = rat.getSprite().getPosition();
			ennemiQueue[n]->setDirection(position);
			ennemiQueue[n]->startClock();
			n++;
		}

		std::cout<<ennemiQueue[n]->getTimeEllapseds()<<std::endl;

		if (!ennemiQueue.empty()) {
		auto it = ennemiQueue.begin();
		for (int i = 0; i < n; i++) {

			if (ennemiQueue[n]->checkfordeath()) {
				ennemiQueue.erase(it);
				n--;
			}
			std::advance(it,1);
		}
		}
	}
}
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Player.h"
#include "Ennemi.h"
#include "Wave.h"
#include <vector>


int main() {
	sf::RenderWindow window( sf::VideoMode( { 1600, 1000 } ), "SFML works!" );
	sf::CircleShape shape( 40.f );
	shape.setFillColor( sf::Color::Green );
	sf::Texture texture(ASSETS_PATH "rat_copy.png");
	sf::Texture cheeseT(ASSETS_PATH "cheese.png");
	sf::CircleShape s1(40.f);
	s1.setPosition({400.f,400.f});
	sf::Clock ennemiClock;
	sf::Font font(ASSETS_PATH "arial.ttf");
	sf::Text text(font);
	Player rat(texture,font);
	Wave wave(1.f);
	int n = 0;
	bool iswavefinish = false;

	std::vector<Ennemi*> waveEnnemy;
	wave.makeTheQueue(0.001f,cheeseT,rat.getSprite(),1);
	for (size_t i = 0; i < wave.getQueuesize();i++) {
		waveEnnemy.push_back(wave.PassQueue(i));
	}

	for (size_t i = 0; i < waveEnnemy.size();i++) {
		waveEnnemy[i]->setclockToStop();
	}


	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		//game update

		if (wave.ifSpawnable(ennemiClock)) {
			waveEnnemy[n]->setIsSpawn(true);
			waveEnnemy[n]->startClock();
			waveEnnemy[n]->setSpawn(s1);
			waveEnnemy[n]->setDirection(rat.getPlayerPosition());
			n++;
		}

		auto it = waveEnnemy.begin();
		for (size_t i=0; i < waveEnnemy.size();i++) {
			if (rat.playerGotHit(waveEnnemy[i])) {
				waveEnnemy.erase(it);
				n--;
			} else if (waveEnnemy[i]->checkfordeath()) {
				waveEnnemy.erase(it);
				n--;
			}
			std::advance(it,1);
		}

		window.clear();

		//game render
		for (size_t i = 0; i < waveEnnemy.size();i++) {
			if (waveEnnemy[i]->getIsSpawn()) {
				waveEnnemy[i]->renderEnnemy(window);
				waveEnnemy[i]->moveEnnemy();
			}
		}

		rat.renderPlayer(window);
		//rat.displayHealth(window);
		window.display();

		//move thing

		rat.movePlayer();





	}
}

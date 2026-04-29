#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Player.h"
#include "Ennemi.h"
#include "Wave.h"
#include <vector>
#include <random>


int main() {

	sf::RenderWindow window( sf::VideoMode( { 1600, 1000 } ), "SFML works!" );
	sf::CircleShape shape( 40.f );
	shape.setFillColor( sf::Color::Green );
	sf::Texture texture(ASSETS_PATH "rat_copy.png");
	sf::Texture cheeseT(ASSETS_PATH "cheese.png");
	std::vector<sf::CircleShape> spawns;
	sf::CircleShape s1(40.f);
	sf::CircleShape s2(40.f);
	sf::CircleShape s3(40.f);
	sf::CircleShape s4(40.f);
	sf::CircleShape s5(40.f);
	sf::CircleShape s6(40.f);
	s1.setPosition({100.f,100.f});
	s2.setPosition({1500.f,100.f});
	s3.setPosition({100.f,500.f});
	s4.setPosition({1500.f,500.f});
	s5.setPosition({100.f,800.f});
	s6.setPosition({1500.f,800.f});
	spawns.push_back(s1);
	spawns.push_back(s2);
	spawns.push_back(s3);
	spawns.push_back(s4);
	spawns.push_back(s5);
	spawns.push_back(s6);
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,5);
	auto whichToSpawn = std::bind ( distribution, generator );



	sf::Clock ennemiClock;
	sf::Font font(ASSETS_PATH "arial.ttf");
	sf::Text text(font);
	//ajouter sprite du fond d'ecran/abilitees + implementer window pour afficher le background
	Player rat(texture,font,texture);
	sf::Text textWave(font);
	Wave wave(1.f);
	int n = 0;
	int n2 = 0;
	int waves = 0;
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

		textWave.setString("wave"+std::to_string(waves));
		textWave.setPosition({200.f,50.f});
		if (iswavefinish) {
			wave.makeTheQueue(0.001f,cheeseT,rat.getSprite(),1);
			for (size_t i = 0; i < wave.getQueuesize();i++) {
				waveEnnemy.push_back(wave.PassQueue(i));
			}

			for (size_t i = 0; i < waveEnnemy.size();i++) {
				waveEnnemy[i]->setclockToStop();
			}
			iswavefinish = false;
		}

		if (wave.ifSpawnable(ennemiClock) && n < waveEnnemy.size()) {
			int result = whichToSpawn();
			waveEnnemy[n]->setIsSpawn(true);
			waveEnnemy[n]->startClock();
			waveEnnemy[n]->setSpawn(spawns[result]);
			waveEnnemy[n]->setDirection(rat.getPlayerPosition());
			n++;
		}

		if (!waveEnnemy.empty()) {
			auto it = waveEnnemy.begin();
			for (size_t i=0; i < waveEnnemy.size();i++) {
				if (rat.playerGotHit(waveEnnemy[i])) {
					delete waveEnnemy[i];
					it = waveEnnemy.erase(it);
				} else if (waveEnnemy[i]->checkfordeath()) {
					delete waveEnnemy[i];
					it = waveEnnemy.erase(it);
				}
				std::advance(it,1);
			}
		}

		window.clear();

		//game render
		if (!waveEnnemy.empty()) {
			for (size_t i = 0; i < waveEnnemy.size();i++) {
				if (waveEnnemy[i]->getIsSpawn()) {
					waveEnnemy[i]->renderEnnemy(window);
					waveEnnemy[i]->moveEnnemy();
				}
			}
		}
		rat.renderPlayer(window);
		rat.displayHealth(window);
		window.draw(textWave);
		window.display();

		//move thing

		rat.movePlayer();

		if (waveEnnemy.empty()) {
			waveEnnemy.clear();
			iswavefinish = true;
			wave.deleteQueue();
			n = 0;
			waves++;
		}

		for (size_t i = 0; i < waveEnnemy.size(); i++) {
			if (waveEnnemy[i]->getIsSpawn()) {
				n2++;
			}
		}
		n = n2;
		n2 = 0;
	}
}
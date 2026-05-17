#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Player.h"
#include "Ennemi.h"
#include "Wave.h"
#include "Object.h"
#include <vector>
#include <random>
#include <fstream>
#include <chrono>
#include <queue>

int main() {
	sf::RenderWindow window( sf::VideoMode( { 1600, 1000 } ), "Labyrinth of STL" );
	sf::CircleShape shape( 40.f );
	shape.setFillColor( sf::Color::Green );
	sf::Texture texture(ASSETS_PATH "rat_copy.png");
	sf::Texture placeHolder(ASSETS_PATH "Placeholder.png");
	sf::Texture cheeseT(ASSETS_PATH "cheese.png");
	sf::Texture backGround(ASSETS_PATH "cheesBackground.png");
	sf::Texture backGroundShop(ASSETS_PATH "shop.png");
	std::vector<sf::CircleShape> spawns;
	sf::CircleShape s1(40.f);
	sf::CircleShape s2(40.f);
	sf::CircleShape s3(40.f);
	sf::CircleShape s4(40.f);
	sf::CircleShape s5(40.f);
	sf::CircleShape s6(40.f);
	sf::CircleShape s7(40.f);
	s1.setPosition({100.f,100.f});
	s2.setPosition({1500.f,100.f});
	s3.setPosition({100.f,500.f});
	s4.setPosition({1500.f,500.f});
	s5.setPosition({100.f,800.f});
	s6.setPosition({1500.f,800.f});
	s7.setPosition({100.f,600.f});
	spawns.push_back(s1);
	spawns.push_back(s2);
	spawns.push_back(s3);
	spawns.push_back(s4);
	spawns.push_back(s5);
	spawns.push_back(s6);
	spawns.push_back(s7);
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,6);
	auto whichToSpawn = std::bind ( distribution, generator );
	sf::Sprite backSprite(backGround);
	sf::Vector2u textureSize = backGround.getSize();
	sf::Vector2u windowSize = window.getSize();
	backSprite.setScale({static_cast<float>(windowSize.x) / textureSize.x,static_cast<float>(windowSize.y) / textureSize.y});
	sf::Sprite backSpriteShop(backGroundShop);
	sf::Vector2u textureSizeShop = backGroundShop.getSize();
	backSpriteShop.setScale({static_cast<float>(windowSize.x) / textureSize.x,static_cast<float>(windowSize.y) / textureSize.y});


	sf::Clock ennemiClock;
	sf::Font font(ASSETS_PATH "arial.ttf");
	sf::Text text(font);
	//ajouter sprite du fond d'ecran/abilitees + implementer window pour afficher le background
	Player rat(texture,font,texture);
	sf::Text textWave(font);
	Wave wave(0.1f);
	int n = 0;
	int n2 = 0;
	int waves = 0;
	bool iswavefinish = false;
	std::queue<std::vector<Object*>> listofObject;
	sf::Vector2f objectPositions[] = {{297.4f,580.f},{476.8f,530.f},{636.8f,490.f},{816.53f,480.f},};


	std::vector<Ennemi*> waveEnnemy;
	wave.makeTheQueue(0.001f,cheeseT,rat.getSprite(),1);
	for (size_t i = 0; i < wave.getQueuesize();i++) {
		waveEnnemy.push_back(wave.PassQueue(i));
	}

	for (size_t i = 0; i < waveEnnemy.size();i++) {
		waveEnnemy[i]->setclockToStop();
	}

	for (size_t i = 0; i < 5;i++) {
		std::vector<Object*> miniListofObject;
		for (size_t i = 0; i < 4;i++) {
			miniListofObject.push_back(new Object(generator,placeHolder));
		}
		listofObject.push(miniListofObject);
		miniListofObject.clear();
	}

	auto start = std::chrono::high_resolution_clock::now();

	while ( window.isOpen() ) {

		while (!iswavefinish) {
			while ( const std::optional event = window.pollEvent() )
			{
				if ( event->is<sf::Event::Closed>() )
					window.close();
			}
			//game update

			textWave.setString("wave"+std::to_string(waves));
			textWave.setPosition({200.f,50.f});
			// if (iswavefinish) {
			// 	wave.makeTheQueue(0.001f,cheeseT,rat.getSprite(),1);
			// 	for (size_t i = 0; i < wave.getQueuesize();i++) {
			// 		waveEnnemy.push_back(wave.PassQueue(i));
			// 	}
			//
			// 	for (size_t i = 0; i < waveEnnemy.size();i++) {
			// 		waveEnnemy[i]->setclockToStop();
			// 	}
			// }

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
			window.draw(backSprite);
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

			if (rat.isDead()) {
				auto end = std::chrono::high_resolution_clock::now();
				std::chrono::duration<float> elapsed = end - start;
				rat.saveData(waves,elapsed);
				window.close();
			}
		}
		sf::Clock clocktime;
		for (size_t i = 0; i < listofObject.front().size(); i++) {
			listofObject.front()[i]->setPosition(objectPositions[i]);
		}
		while (iswavefinish) {
			while ( const std::optional event = window.pollEvent() )
			{
				if ( event->is<sf::Event::Closed>() )
					window.close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				for (size_t i = 0; i < listofObject.front().size(); i++) {
					sf::Vector2f mousePosition(static_cast<float>(sf::Mouse::getPosition().x), static_cast<float>(sf::Mouse::getPosition().y));
					if (listofObject.front()[i]->getGlobalBounds().contains(mousePosition) && rat.getCats() > listofObject.front()[i]->getCost()) {
						rat.pushObject(listofObject.front()[i]);
					}
				}
			}
			window.clear();
			window.draw(backSpriteShop);
			rat.renderPlayer(window);
			for (size_t i = 0; i < listofObject.front().size(); i++) {
				if (!listofObject.front()[i]->getIsBought()) {
					listofObject.front()[i]->renderObject(window);
				}
			}
			window.display();
			rat.movePlayer();
			if (clocktime.getElapsedTime().asSeconds() >= 1.0f) {
				std::cout<<	rat.getSprite().getPosition().x << ":"<<rat.getSprite().getPosition().y<<std::endl;
				clocktime.restart();
			}
		}
	}
	sf::RenderWindow resultsWindow( sf::VideoMode( { 1600, 1000 } ), "Results" );
	while ( resultsWindow.isOpen() )
	{
		while ( const std::optional event = resultsWindow.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				resultsWindow.close();
		}

		resultsWindow.clear();
		rat.displayStats(resultsWindow);
		resultsWindow.display();



	}
}
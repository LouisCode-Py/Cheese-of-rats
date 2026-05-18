//
// Created by Babin on 4/24/2026.
//

#ifndef CMAKESFMLPROJECT_PLAYER_H
#define CMAKESFMLPROJECT_PLAYER_H
#include "Abilities.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Graphics.hpp"
#include "Ennemi.h"
#include <vector>
#include <chrono>
#include <sstream>
#include "Object.h"


class Player{
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(_playerSprite, states);
    }

    sf::Text _catNumberText;

    sf::Font _font;
    sf::Text _healthText;
    sf::Text _scoreText;
    sf::Text _quitText;
    sf::Texture _playerTexture;
    int _catNumber;
    sf::Vector2f _playerPosition;
    int _healthPoints;
    int _maxHealthPoints;
    sf::Sprite _playerSprite;
    std::stringstream _ss;
    std::vector<Object*> _object;
    int _healtmodified;
    double _speedmodifier;
    sf::Vector2f _sizeModifier;

public:
    Player(sf::Texture& texture, sf::Font font, sf::Texture& image);

    const sf::Sprite& getSprite() const;

    void movePlayer();
    void renderPlayer(sf::RenderWindow& window);

    sf::Vector2f getPlayerPosition() const;
    sf::FloatRect getGlobalBounds() const;

    int reduceHealth();
    bool playerGotHit(Ennemi* ennemy);
    int getHealth();
    int getMaxHealth();
    void displayHealth(sf::RenderWindow& window);
    void displayStats(sf::RenderWindow& resultsWindow);
    // float getSpeed();
    // sf::Vector2f getCurrentSize();
    void hasBoughtItem(Object* object);
    bool isDead();
    void saveData(int waves, std::chrono::duration<float> timeElapsed);
    void quit(sf::RenderWindow& window);
    void renderMoney(sf::RenderWindow& window);
    void addMoney(double globalModifier);
    void addHealth();
    void pushObject(Object* object);
    int getCats();
    void setPlayerBeforeWave();
};


#endif //CMAKESFMLPROJECT_PLAYER_H
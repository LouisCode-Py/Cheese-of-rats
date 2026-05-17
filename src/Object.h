//
// Created by loulo on 2026-05-15.
//

#ifndef CMAKESFMLPROJECT_OBJECT_H
#define CMAKESFMLPROJECT_OBJECT_H

#include <SFML/Graphics.hpp>
#include <random>

class Object {
private:
    sf::Vector2f _sizeModifier;
    int _healthModifier;
    float _speedModifier;
    std::default_random_engine _generator;
    sf::Sprite _objectSprite;
    int _cost;
    bool _isbought;

public:
    Object(std::default_random_engine& generator,sf::Texture& texture);
    sf::Vector2f getSizeModifier();
    int getHealthModifier();
    float getSpeedModifier();
    int getCost();

    sf::FloatRect getGlobalBounds() const;
    void renderObject(sf::RenderWindow& window);
    void setPosition(sf::Vector2f position);
    void isBought();
    bool getIsBought();
};



#endif //CMAKESFMLPROJECT_OBJECT_H

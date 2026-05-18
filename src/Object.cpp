//
// Created by loulo on 2026-05-15.
//

#include "Object.h"

Object::Object(std::default_random_engine& generator,sf::Texture& texture): _generator(generator),_objectSprite(texture) {
    this->_generator = generator;
    std::uniform_real_distribution<float> distribution(0.1f,0.5f);
    // auto modifier = std::bind(distribution,this->_generator);
    this->_healthModifier = round(distribution(_generator)*10);
    this->_speedModifier = distribution(_generator);
    this-> _cost = round(distribution(_generator)*30);
    this->_sizeModifier = {static_cast<float>(distribution(_generator)),static_cast<float>(distribution(_generator))};
    this-> _isbought = false;
    this->_isUsed = false;

}

int Object::getHealthModifier() {
    return this->_healthModifier;
}

sf::Vector2f Object::getSizeModifier() {
    return this->_sizeModifier;
}

float Object::getSpeedModifier() {
    return this->_speedModifier;
}

void Object::renderObject(sf::RenderWindow &window) {
    window.draw(this->_objectSprite);
}

sf::FloatRect Object::getGlobalBounds() const {
    return _objectSprite.getGlobalBounds();
}

void Object::setPosition(sf::Vector2f position) {
    this->_objectSprite.setPosition(position);
}

int Object::getCost() {
    return this->_cost;
}

bool Object::getIsBought() {
    return this->_isbought;
}

void Object::isBought() {
    this-> _isbought = true;
}

bool Object::getIsUsed() {
    return this->_isUsed;
}

void Object::isUsed() {
    this-> _isUsed = true;
}


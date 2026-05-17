//
// Created by loulo on 2026-05-15.
//

#include "Object.h"

Object::Object(std::default_random_engine& generator,sf::Texture& texture):_objectSprite(texture) {
    this->_generator = generator;
    std::uniform_real_distribution<float> distribution(0.1,0.5);
    auto modifier = std::bind(this->_generator);
    this->_healthModifier = modifier();
    this->_speedModifier = modifier();
    this-> _cost = round(modifier()*40);
    this->_sizeModifier = {static_cast<float>(modifier()),static_cast<float>(modifier())};
    this-> _isbought = false;

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
    return; this->_isbought;
}

void Object::isBought() {
    this-> _isbought = true;
}

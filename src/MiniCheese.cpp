#include "MiniCheese.h"

void MiniCheese::setDirection(sf::Vector2f position) {
    this-> _directionX = position.x;
    this-> _directionY = position.y;
}


void MiniCheese::moveEnnemy() {
    this-> _ennemySprite.move({(this->_directionX),(this->_directionY)});
}


#include "BigCheese.h"


void BigCheese::moveEnnemy() {
    this->_ennemySprite.move({(this->_directionX) * this->_speed*0.5f, (this->_directionY) * this->_speed*0.5f});
}

void BigCheese::setDirection(sf::Vector2f position) {
    this->_directionY = position.y - this->_y;
    this->_directionX = position.x - this->_x;
}

std::string BigCheese::getTypeEnnemi() {
    return "big";
}

#include "Ennemi.h"
#include <cmath>

Ennemi::Ennemi(float speed, const sf::Texture& texture, const sf::Sprite& player) : _ennemySprite(texture)
{
    setSpeed(speed);
    this->_x = 0.f;
    this->_y = 0.f;
    this ->_directionX = 0.f;
    this-> _directionY = 0.f;
    setIsnotReturn(false);
}




void Ennemi::setDirection(const sf::Sprite &player) {
    this->_directionY =   player.getPosition().y - this->_y ;
    this->_directionX =   player.getPosition().x - this->_x ;

}

void Ennemi::setSpawn(const sf::CircleShape &spawn) {
      this->_y = spawn.getPosition().y;
      this->_x = spawn.getPosition().x;
        setEnnemy(spawn.getPosition().x,spawn.getPosition().y);

}


void Ennemi::setSpeed(float speed) {
    this->_speed = speed;
}

void Ennemi::moveEnnemy() {
    float hypotenus = sqrt(pow(_directionX,2)+pow(_directionY,2));
    this-> _ennemySprite.move({(this->_directionX/hypotenus)*_speed,(this->_directionY/hypotenus)*_speed});
}



void Ennemi::setEnnemy(float x, float y) {
    _ennemySprite.setPosition({x,y});
}

void Ennemi::renderEnnemy(sf::RenderWindow &window) {
    window.draw(getSprite());
}

bool Ennemi::getIsnotReturn() {
    return this->_isnotreturn;
}

const sf::Sprite &Ennemi::getSprite() const {
    return this->_ennemySprite;
}

void Ennemi::setIsnotReturn(bool isReturn) {
    this->_isnotreturn = isReturn;
}

sf::FloatRect Ennemi::getGlobalBounds() {
    return _ennemySprite.getGlobalBounds();
}

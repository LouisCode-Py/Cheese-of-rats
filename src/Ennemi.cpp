#include "Ennemi.h"
#include <cmath>

Ennemi::Ennemi(float speed, const sf::Texture& texture, const sf::Sprite& player) : _EnnemieSprite(texture)
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
        setEnnemi(spawn.getPosition().x,spawn.getPosition().y);

}


void Ennemi::setSpeed(float speed) {
    this->_speed = speed;
}

void Ennemi::moveEnnemi() {
    float hypotenus = sqrt(pow(_directionX,2)+pow(_directionY,2));
    this-> _EnnemieSprite.move({(this->_directionX/hypotenus)*_speed,(this->_directionY/hypotenus)*_speed});
}



void Ennemi::setEnnemi(float x, float y) {
    _EnnemieSprite.setPosition({x,y});
}

void Ennemi::RenderEnnemi(sf::RenderWindow &window) {
    window.draw(getSprite());
}

bool Ennemi::getIsnotReturn() {
    return this->_isnotreturn;
}

const sf::Sprite &Ennemi::getSprite() const {
    return this->_EnnemieSprite;
}

void Ennemi::setIsnotReturn(bool isReturn) {
    this->_isnotreturn = isReturn;
}

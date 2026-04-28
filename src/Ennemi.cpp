#include "Ennemi.h"
#include <cmath>
#include <_mingw_mac.h>

Ennemi::Ennemi(float speed, const sf::Texture& texture, const sf::Sprite& player) : _EnnemieSprite(texture)
{
    setSpeed(speed);
    this->_x = 0.f;
    this->_y = 0.f;
    this ->_directionX = 0.f;
    this-> _directionY = 0.f;
    this->_timeToDie = 2.f;

}




void Ennemi::setDirection(sf::Vector2f position) {
    this->_directionY =  position.y - this->_y ;
    this->_directionX =  position.x - this->_x ;

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
    this-> _EnnemieSprite.move({(_directionX)*_speed,(_directionY)*_speed});
}



void Ennemi::setEnnemi(float x, float y) {
    _EnnemieSprite.setPosition({x,y});
}

void Ennemi::RenderEnnemi(sf::RenderWindow &window) {
    window.draw(getSprite());
}



const sf::Sprite &Ennemi::getSprite() const {
    return this->_EnnemieSprite;
}

void Ennemi::startClock() {
    this->_clock.restart();
}

bool Ennemi::checkfordeath() {
    if (_clock.getElapsedTime().asSeconds() >= _timeToDie) {
        return true;
    }

    return false;
}

float Ennemi::getTimeEllapseds() {
    return this->_clock.getElapsedTime().asSeconds();
}

#include "Ennemi.h"
#include <cmath>

Ennemi::Ennemi(float speed, const sf::Texture& texture, const sf::Sprite& player) : _ennemySprite(texture)
{
    setSpeed(speed);
    this->_x = 0.f;
    this->_y = 0.f;
    this ->_directionX = 0.f;
    this-> _directionY = 0.f;
    this->_timeToDie = 2.f;
    this->_clock;
    this->_isSpawn = false;

}




void Ennemi::setDirection(sf::Vector2f position) {
    this->_directionY =  position.y - this->_y ;
    this->_directionX =  position.x - this->_x ;

}

void Ennemi::setSpawn(const sf::CircleShape &spawn) {
      this->_y = spawn.getPosition().y;
      this->_x = spawn.getPosition().x;
        _ennemySprite.setPosition({spawn.getPosition().x,spawn.getPosition().y});

}


void Ennemi::setSpeed(float speed) {
    this->_speed = speed;
}

void Ennemi::moveEnnemy() {
    //float hypotenus = sqrt(pow(_directionX,2)+pow(_directionY,2)); eventuelemment
    this-> _ennemySprite.move({(_directionX)*_speed,(_directionY)*_speed});
}

void Ennemi::renderEnnemy(sf::RenderWindow &window) {
    window.draw(getSprite());
}



const sf::Sprite &Ennemi::getSprite() const {
    return this->_ennemySprite;
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

sf::FloatRect Ennemi::getGlobalBounds() {
    return _ennemySprite.getGlobalBounds();
}

void Ennemi::setclockToStop() {
    this->_clock.stop();
}

bool Ennemi::getIsSpawn() {
    return this->_isSpawn;
}

void Ennemi::setIsSpawn(bool n) {
    this->_isSpawn = n;
}

void Ennemi::hitPlayer() {

}

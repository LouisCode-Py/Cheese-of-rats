//
// Created by Babin on 4/24/2026.
//

#include "Player.h"

Player::Player( const sf::Texture& texture)
    : _playerSprite(texture)
{
    _catNumber = 0;
    _healthPoints = 0;
}

float Player::getPositionX() const{
    return _playerSprite.getPosition().x;
}

float Player::getPositionY() const{
    return _playerSprite.getPosition().y;
}

const sf::Sprite &Player::getSprite() const {
    return this->_playerSprite;
}

void Player::RenderPlayer( sf::RenderWindow& window) {
    window.draw(getSprite());
}

void Player::movePlayer() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        _playerSprite.move({0.1f,0.1f});
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        _playerSprite.move({-0.1f,0.1f});
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        _playerSprite.move({-0.1f,-0.1f});
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        _playerSprite.move({0.1f,-0.1f});
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        _playerSprite.move({0.f,-0.1});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        _playerSprite.move({0.f,0.1});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        _playerSprite.move({-0.1,0.f});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        _playerSprite.move({0.1,0.f});
    }
}


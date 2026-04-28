//
// Created by Babin on 4/24/2026.
//

#include "Player.h"


Player::Player( const sf::Texture& texture)
    : _playerSprite(texture),
    _fonts(ASSETS_PATH "arial.ttf"),
    _healthText(_fonts)
{
    _playerPosition = {800.f,500.f};
    _playerSprite.setPosition(_playerPosition);
    _catNumber = 0;
    _healthPoints = 10;
    _healthText.setCharacterSize(24);
    _healthText.setFillColor(sf::Color::Green);
    _healthText.setPosition({10.f, 10.f});
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

void Player::renderPlayer( sf::RenderWindow& window) {
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
        _playerSprite.move({0.f,-0.1f});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        _playerSprite.move({0.f,0.1f});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        _playerSprite.move({-0.1f,0.f});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        _playerSprite.move({0.1f,0.f});
    }
}

sf::Vector2f Player::getPlayerPosition() const {
    return _playerSprite.getPosition();
}

sf::FloatRect Player::getGlobalBounds() const {
    return _playerSprite.getGlobalBounds();
}

int Player::reduceHealth() {
    _healthPoints -= 1;
    return _healthPoints;
}

bool Player::playerGotHit(Ennemi* ennemy) {
    if (_playerSprite.getGlobalBounds().findIntersection(ennemy->getGlobalBounds())) {
        this->reduceHealth();
        return true;
    }
    return false;
}

int Player::getHealth() {
    return _healthPoints;
}

void Player::displayHealth(sf::RenderWindow& window) {
    _healthText.setString("Health: " + std::to_string(this->getHealth()));
    window.draw(_healthText);
}

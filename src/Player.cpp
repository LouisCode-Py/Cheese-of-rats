//
// Created by Babin on 4/24/2026.
//

#include "Player.h"
#include <iostream>

Player::Player(const sf::Texture texture)
    : _playerSprite(texture)
{
    _catNumber = 0;
    _healthPoints = 10;
    _playerTexture.loadFromFile("");
    _playerSprite.setPosition({200,200});
    _playerPosition = {200,200};
}

Player::Player()
    : _playerSprite(_playerTexture)
{
    if (!_playerTexture.loadFromFile(ASSETS_PATH "rat.jpg")) {
        std::cout << "Failed to load texture!" << std::endl;
    } else {
        std::cout << "Texture loaded successfully!" << std::endl;
    }
    _catNumber = 0;
    _healthPoints = 10;
    _playerTexture.loadFromFile(ASSETS_PATH "rat_copy.PNG");
    _playerSprite.setTexture(_playerTexture);
    _playerSprite.setPosition({200,200});
    _playerPosition = {200,200};
    _playerSprite.setScale({3.f,3.f});
}

void Player::move(sf::Vector2f offset) {
    _playerSprite.move(offset);
    _playerPosition = _playerSprite.getPosition();
}

sf::FloatRect Player::getGlobalBounds() const {
    return _playerSprite.getGlobalBounds();
}


void Player::movements() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        _playerSprite.move({0.1f,0.1f});;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        _playerSprite.move({-0.1f,0.1f});;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        _playerSprite.move({-0.1f,-0.1f});;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        _playerSprite.move({0.1f,-0.1f});;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        _playerSprite.move({0.f,-0.1});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        _playerSprite.move({0.f,0.1});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        _playerSprite.move({-0.1f,0.f});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        _playerSprite.move({0.1f,0.f});
    }
}

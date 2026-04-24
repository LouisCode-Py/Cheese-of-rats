//
// Created by Babin on 4/24/2026.
//

#include "Player.h"

Player::Player(const sf::Texture texture)
    : _playerSprite(texture)
{
    _catNumber = 0;
    _healthPoints = 10;
    _playerTexture.loadFromFile("");
    _playerSprite.setPosition({200,200});
    _playerPosition = _
}

Player::Player()
    : _playerSprite(_playerTexture)
{
    _catNumber = 0;
    _healthPoints = 10;
    _playerTexture.loadFromFile("../../rat.png");
}

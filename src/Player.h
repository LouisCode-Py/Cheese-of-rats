//
// Created by Babin on 4/24/2026.
//

#ifndef CMAKESFMLPROJECT_PLAYER_H
#define CMAKESFMLPROJECT_PLAYER_H
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"


class Player {
private:
    sf::Texture _playerTexture;
    int _catNumber;
    //double _playerPosition;

    int _healthPoints;
    sf::Sprite _playerSprite;
public:
    Player(sf::Texture texture);
    Player();
};


#endif //CMAKESFMLPROJECT_PLAYER_H
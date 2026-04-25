//
// Created by Babin on 4/24/2026.
//

#ifndef CMAKESFMLPROJECT_PLAYER_H
#define CMAKESFMLPROJECT_PLAYER_H
#include <SFML/Graphics.hpp>


class Player : public sf::Drawable {
private:

    sf::Sprite _playerSprite;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_playerSprite, states);
    }
    sf::Texture _playerTexture;
    int _catNumber;
    sf::Vector2f _playerPosition;

    int _healthPoints;
public:
    Player(sf::Texture texture);
    Player();

    void move(sf::Vector2f offset);
    void movements();
};


#endif //CMAKESFMLPROJECT_PLAYER_H
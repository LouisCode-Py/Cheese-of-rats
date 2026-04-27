//
// Created by Babin on 4/24/2026.
//

#ifndef CMAKESFMLPROJECT_PLAYER_H
#define CMAKESFMLPROJECT_PLAYER_H
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Graphics.hpp"


class Player {
  //  : public sf::Drawable
private:
    sf::Texture _playerTexture;
    int _catNumber;
    sf::Vector2f _playerPosition;
    int _healthPoints;
    sf::Sprite _playerSprite;
    sf::RenderWindow _window;

public:
    Player(const sf::Texture& texture);

    float getPositionX() const;
    float getPositionY() const;
    const sf::Sprite& getSprite() const;

    void movePlayer();
    void renderPlayer(sf::RenderWindow& window);

    sf::Vector2f getPlayerPosition() const;
    sf::FloatRect getGlobalBounds() const;
    int reduceHealth();
};


#endif //CMAKESFMLPROJECT_PLAYER_H
//
// Created by Babin on 4/24/2026.
//

#ifndef CMAKESFMLPROJECT_PLAYER_H
#define CMAKESFMLPROJECT_PLAYER_H
#include "Abilities.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Graphics.hpp"
#include "Ennemi.h"


class Player : public Abilities{
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_playerSprite, states);
    }
    sf::Font _font;
    sf::Text _healthText;
    sf::Texture _playerTexture;
    int _catNumber;
    sf::Vector2f _playerPosition;
    int _healthPoints;
    sf::Sprite _playerSprite;
    //sf::RenderWindow _window;
public:
    Player(sf::Texture& texture, sf::Font font, sf::Texture& image);

    const sf::Sprite& getSprite() const;

    void movePlayer();
    void renderPlayer(sf::RenderWindow& window);

    sf::Vector2f getPlayerPosition() const;
    sf::FloatRect getGlobalBounds() const;
    int reduceHealth();
    bool playerGotHit(Ennemi* ennemy);
    int getHealth();
    void displayHealth(sf::RenderWindow& window);
    float getSpeed() override;
    sf::Vector2f getCurrentSize() override;
};


#endif //CMAKESFMLPROJECT_PLAYER_H
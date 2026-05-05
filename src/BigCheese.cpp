//
// Created by loulo on 2026-04-29.
//

#include "BigCheese.h"
#include "MiniCheese.h"

void BigCheese::deatheffect(float speed,const sf::Texture& texture,const sf::Sprite& player) {
    minis(speed,texture,player);
}

Ennemi *BigCheese::minis(float speed, const sf::Texture &texture, const sf::Sprite &player) {
    return new MiniCheese(speed, texture, player);
}

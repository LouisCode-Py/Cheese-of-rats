//
// Created by loulo on 2026-04-29.
//

#ifndef CMAKESFMLPROJECT_MINICHEESE_H
#define CMAKESFMLPROJECT_MINICHEESE_H
#include "Ennemi.h"


class MiniCheese:public Ennemi{
public:
    MiniCheese(float speed,const sf::Texture& texture,const sf::Sprite& player):Ennemi(speed, texture,player){}
    void setDirection(sf::Vector2f position) override;
    void moveEnnemy() override;
};



#endif //CMAKESFMLPROJECT_MINICHEESE_H

#ifndef CMAKESFMLPROJECT_BIGCHEESE_H
#define CMAKESFMLPROJECT_BIGCHEESE_H
#include "src/Ennemi.h"
#include "src/MiniCheese.h"


class BigCheese:public Ennemi{
public:
    BigCheese(float speed,const sf::Texture& texture,const sf::Sprite& player):Ennemi(speed, texture,player){}
    void Deatheffect(float speed,const sf::Texture& texture,const sf::Sprite& player);
    Ennemi* minis(float speed,const sf::Texture& texture,const sf::Sprite& player);
};



#endif //CMAKESFMLPROJECT_BIGCHEESE_H

#ifndef CMAKESFMLPROJECT_BIGCHEESE_H
#define CMAKESFMLPROJECT_BIGCHEESE_H
#include "Ennemi.h"
#include "MiniCheese.h"


class BigCheese:public Ennemi{
public:
    BigCheese(float speed,sf::Texture& texture,const sf::Sprite& player):Ennemi(speed, texture,player){}
    void deatheffect(float speed,sf::Texture& texture,const sf::Sprite& player,std::vector<Ennemi*> &waveEnnemy,int position) override;
    void moveEnnemy() override;
    void setDirection(sf::Vector2f position) override;
};



#endif //CMAKESFMLPROJECT_BIGCHEESE_H

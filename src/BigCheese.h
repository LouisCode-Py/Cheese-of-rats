#ifndef CMAKESFMLPROJECT_BIGCHEESE_H
#define CMAKESFMLPROJECT_BIGCHEESE_H
#include "Ennemi.h"



class BigCheese:public Ennemi{
public:
    BigCheese(float speed,const sf::Texture& texture,const sf::Sprite& player):Ennemi(speed, texture,player){}
    void moveEnnemy() override;
    void setDirection(sf::Vector2f position) override;
    std::string getTypeEnnemi() override;
};



#endif //CMAKESFMLPROJECT_BIGCHEESE_H

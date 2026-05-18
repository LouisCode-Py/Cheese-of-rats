//
// Created by loulo on 2026-04-29.
//

#include "BigCheese.h"
#include "MiniCheese.h"

void BigCheese::deatheffect(float speed,sf::Texture& texture,const sf::Sprite& player,std::vector<Ennemi*>& waveEnnemy,int position) {
    for (size_t i = 0; i<6;i++) {
        sf::Vector2f direction[6] ={{1.f,1.f},{1.f,-1.f},{-1.f,1.f},{-1.f,-1.f},{1.f,0.f},{-1.f,0.f},};
        waveEnnemy.push_back(new MiniCheese(speed,texture,player));
        waveEnnemy.back()->setDirection(direction[i]);
        waveEnnemy.back()->setSpawn(waveEnnemy[position]->getSprite().getPosition());
    }
}

void BigCheese::moveEnnemy() {
    this-> _ennemySprite.move({(this->_directionX)*this->_speed,(this->_directionY)*this->_speed});
}

void BigCheese::setDirection(sf::Vector2f position) {
    this->_directionY =  position.y - this->_y ;
    this->_directionX =  position.x - this->_x ;
}


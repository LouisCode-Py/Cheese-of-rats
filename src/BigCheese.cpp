#include "BigCheese.h"
//#include "MiniCheese.h"

void BigCheese::deatheffect(float speed, const sf::Texture &texture, const sf::Sprite &player,
                    std::vector<Ennemi *> &waveEnnemy, int position, sf::RenderWindow &window) {
    // for (size_t i = 0; i < 6; i++) {
    //     sf::Vector2f direction[6] = {{1.f, 1.f}, {1.f, -1.f}, {-1.f, 1.f}, {-1.f, -1.f}, {1.f, 0.f}, {-1.f, 0.f},};
    //     waveEnnemy.push_back(new MiniCheese(speed, texture, player));
    //     waveEnnemy.back()->setDirection(direction[i]);
    //     waveEnnemy.back()->setSpawn(waveEnnemy[position]->getSprite().getPosition());
    //     setIsSpawn(true);
    //     waveEnnemy.back()->setclockToStop();
    //     waveEnnemy.back()->startClock();
    // }
}

void BigCheese::moveEnnemy() {
    this->_ennemySprite.move({(this->_directionX) * this->_speed*0.5f, (this->_directionY) * this->_speed*0.5f});
}

void BigCheese::setDirection(sf::Vector2f position) {
    this->_directionY = position.y - this->_y;
    this->_directionX = position.x - this->_x;
}

std::string BigCheese::typeEnnemi() {
    return "big";
}

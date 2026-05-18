#include "Wave.h"
#include <random>

#include "BigCheese.h"

Wave::Wave(float spawnTime,std::default_random_engine generator):_generator(generator) {
    setSpawnTime(spawnTime);
}

void Wave::setSpawnTime(float spawnTime) {
    this->_spawnTime = spawnTime;
}

void Wave::makeTheQueue(float speed,sf::Texture& texture, const sf::Sprite& player,float globalDifficulty,int wave) {
    std::uniform_int_distribution distribution(50,100);
    std::uniform_int_distribution<int> disributionforbigcheese(1,6);
    int numberOfEnnemi = distribution(this->_generator) + round(50*globalDifficulty);
    for (int i = 0; i<numberOfEnnemi;i++) {
        if (disributionforbigcheese(this->_generator) != 6 || wave <5) {
            this->_ennemiQueue.push_back(new Ennemi(speed,texture,player));
        } else {
            this->_ennemiQueue.push_back(new BigCheese(speed,texture,player));
        }
    }
}

bool Wave::ifSpawnable(sf::Clock& ennemiClock) {
    if (ennemiClock.getElapsedTime().asSeconds() >= this->_spawnTime) {
        ennemiClock.restart();
        return true;
    }

    return false;
}

Ennemi* Wave::PassQueue(int n) {
    return this-> _ennemiQueue[n];
}

size_t Wave::getQueuesize() {
   return this->_ennemiQueue.size();
}

void Wave::deleteQueue() {
    this->_ennemiQueue.clear();

}

// Wave::~Wave(){
// }

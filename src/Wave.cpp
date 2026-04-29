#include "Wave.h"
#include <random>
#include <_mingw_mac.h>

Wave::Wave(float spawnTime) {
    setSpawnTime(spawnTime);
}

void Wave::setSpawnTime(float spawnTime) {
    this->_spawnTime = spawnTime;
}

void Wave::setGenerator(std::default_random_engine generator) {
    this-> _generator = generator;
}

void Wave::makeTheQueue(float speed, const sf::Texture& texture, const sf::Sprite& player,float globalDifficulty) {
    std::uniform_int_distribution distribution(5,10);
    int numberOfEnnemi = distribution(this->_generator);
    for (int i = 0; i<numberOfEnnemi;i++) {
        this->_ennemiQueue.push_back(new Ennemi(speed,texture,player));
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

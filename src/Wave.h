#include <vector>
#include <random>
#include "Ennemi.h"
#include <SFML/System.hpp>

#ifndef CMAKESFMLPROJECT_WAVE_H
#define CMAKESFMLPROJECT_WAVE_H



class Wave {
private:
    std::vector<Ennemi*> _ennemiQueue;
    float _spawnTime;
    std::default_random_engine _generator;
public:
    Wave(float spawnTime);
    void setSpawnTime(float spawnTime);
    void setGenerator(std::default_random_engine generator);
    void makeTheQueue(float speed, const sf::Texture& texture, const sf::Sprite& player, float globalDifficulty);
    Ennemi* PassQueue(int n);
    bool ifSpawnable(sf::Clock& ennemiClock);
    size_t getQueuesize();
    void deleteQueue();
   // ~Wave();
};



#endif //CMAKESFMLPROJECT_WAVE_H
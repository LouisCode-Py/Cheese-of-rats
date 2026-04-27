#include <queue>
#include <random>
#include "Ennemi.h"

#ifndef CMAKESFMLPROJECT_WAVE_H
#define CMAKESFMLPROJECT_WAVE_H



class Wave {
private:
    std::queue<Ennemi*> _ennemiQueue;
    float _spawnTime;
    std::default_random_engine _generator;
public:
    Wave(float spawnTime);
    void setSpawnTime(float spawnTime);
    void setGenerator(std::default_random_engine generator);
    void makeTheQueue(float speed, const sf::Texture& texture, const sf::Sprite& player, float globalDifficulty);
    std::queue<Ennemi*> PassQueue();
    bool ifSpawnable();
    ~Wave();
};



#endif //CMAKESFMLPROJECT_WAVE_H

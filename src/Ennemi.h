#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <cmath>

#ifndef CHEESE_OF_RATS_ENNEMI_H
#define CHEESE_OF_RATS_ENNEMI_H



class Ennemi {
private:
    float _timeToDie;
    sf::Clock _clock;
    sf::Texture _EnnemieTexture;
    sf::Sprite _EnnemieSprite;
    float _speed;
    float _x,_y;
    float _directionX,_directionY;
public:
    Ennemi(float speed,const sf::Texture& texture,const sf::Sprite& player);

    void setSpeed(float speed);
    void setDirection(sf::Vector2f position);
    void setSpawn(const sf::CircleShape& spawn);
    void moveEnnemi();
    void setEnnemi(float x, float y);
    void RenderEnnemi(sf::RenderWindow& window);
    void startClock();
    bool checkfordeath();
    const sf::Sprite& getSprite() const;
    float getTimeEllapseds();


};



#endif //CHEESE_OF_RATS_ENNEMI_H

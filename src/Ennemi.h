#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <cmath>

#ifndef CHEESE_OF_RATS_ENNEMI_H
#define CHEESE_OF_RATS_ENNEMI_H



class Ennemi {
private:
    sf::Time _timeToDie;
    sf::Texture _EnnemieTexture;
    sf::Sprite _EnnemieSprite;
    float _speed;
    float _x,_y;
    float _directionX,_directionY;
    bool _isnotreturn;
public:
    Ennemi(float speed,const sf::Texture& texture,const sf::Sprite& player);

    void setSpeed(float speed);
    void setDirection(const sf::Sprite& player);
    void setSpawn(const sf::CircleShape& spawn);
    void moveEnnemi();
    void setEnnemi(float x, float y);
    void RenderEnnemi(sf::RenderWindow& window);
    bool getIsnotReturn();
    const sf::Sprite& getSprite() const;
    void setIsnotReturn(bool isReturn);


};



#endif //CHEESE_OF_RATS_ENNEMI_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <cmath>

#ifndef CHEESE_OF_RATS_ENNEMI_H
#define CHEESE_OF_RATS_ENNEMI_H

class Ennemi {
protected:
    float _timeToDie;
    sf::Clock _clock;
    // sf::Texture _ennemyTexture;
    sf::Sprite _ennemySprite;
    float _speed;
    float _x, _y;
    float _directionX, _directionY;
    bool _isSpawn;

public:
    Ennemi(float speed, const sf::Texture &texture, const sf::Sprite &player);

    void setSpeed(float speed);

    virtual void setDirection(sf::Vector2f position);

    void setSpawn(const sf::Vector2f &spawn);

    virtual void moveEnnemy();

    void renderEnnemy(sf::RenderWindow &window);

    void startClock();

    bool checkfordeath();

    const sf::Sprite &getSprite() const;

    float getTimeEllapseds() const;

    sf::FloatRect getGlobalBounds() const;

    void setclockToStop();

    bool getIsSpawn() const;

    void setIsSpawn(bool n);

    void hitPlayer();

    virtual std::string getTypeEnnemi();
};

#endif //CHEESE_OF_RATS_ENNEMI_H

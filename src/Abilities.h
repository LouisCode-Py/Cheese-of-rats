//
// Created by Babin on 4/29/2026.
//

#ifndef CMAKESFMLPROJECT_ABILITIES_H
#define CMAKESFMLPROJECT_ABILITIES_H

#include <SFML/Graphics.hpp>


class Abilities : public sf::Drawable {
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_image, states);
    }
    sf::Vector2f _sizeModifier;
    int _healthModifier;
    float _speedModifier;
    sf::Sprite _image;

public:
    Abilities(sf::Texture& image);
    float selectSpeed();
    void selectHealth();
    sf::Vector2f selectSize();
    void renderAbilities(sf::RenderWindow& window);
    const sf::Sprite getImage() const;

    virtual float getSpeed() = 0;
    virtual sf::Vector2f getCurrentSize() = 0;
};


#endif //CMAKESFMLPROJECT_ABILITIES_H
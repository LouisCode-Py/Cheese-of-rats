//
// Created by Babin on 4/29/2026.
//

#include "Abilities.h"

Abilities::Abilities(sf::Texture& image)
    : _image(image)
{
    _healthModifier = 0;
    _sizeModifier = {0,0};
    _speedModifier = 0;
}

float Abilities::selectSpeed() {
    _speedModifier += 0.001;
    return _speedModifier;
}

void Abilities::selectHealth() {
    //gives 1 health back for now
    _healthModifier++;

}

sf::Vector2f Abilities::selectSize() {
    _sizeModifier.y += 0.1f;
    _sizeModifier.x += 0.1f;
    return _sizeModifier;
}

const sf::Sprite Abilities::getImage() const {
    return _image;
}

void Abilities::renderAbilities(sf::RenderWindow &window) {
    window.draw( getImage() );
}

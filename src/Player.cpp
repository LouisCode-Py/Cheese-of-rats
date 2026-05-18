//
// Created by Babin on 4/24/2026.
//

#include "Player.h"
#include <fstream>
#include <chrono>


Player::Player( sf::Texture& texture, sf::Font font, sf::Texture& image)
    : _playerTexture(image),
    _playerSprite(texture),
    _healthText(font),
    _scoreText(font),
    _quitText(font),
    _catNumberText(font)
{
    _playerPosition = {800.f,500.f};
    _playerSprite.setPosition(_playerPosition);
    _catNumber = 0;
    _healthPoints = 30;
    _maxHealthPoints = _healthPoints;
    _healthText.setCharacterSize(24);
    _healthText.setFillColor(sf::Color::Green);
    _healthText.setPosition({10.f, 10.f});
    _quitText.setFillColor(sf::Color::Red);
    _quitText.setPosition({1400.f,950.f});
    _catNumberText.setFillColor(sf::Color::Red);
    _catNumberText.setPosition({1300.f,950.f});
    _speedmodifier = 1;
    _sizeModifier = {3.f,3.f};
    _playerSprite.setScale(_sizeModifier);
}

const sf::Sprite &Player::getSprite() const {
    return this->_playerSprite;
}

void Player::renderPlayer( sf::RenderWindow& window) {
    window.draw(getSprite());
}

void Player::movePlayer() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        _playerSprite.move({0.1f,0.1f});
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        _playerSprite.move({-0.1f,0.1f});
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        _playerSprite.move({-0.1f,-0.1f});
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        _playerSprite.move({0.1f,-0.1f});
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        _playerSprite.move({0.f,-0.2f});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        _playerSprite.move({0.f,0.2f});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        _playerSprite.move({-0.2f,0.f});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        _playerSprite.move({0.2f,0.f});
    }
}

sf::Vector2f Player::getPlayerPosition() const {
    return _playerSprite.getPosition();
}

sf::FloatRect Player::getGlobalBounds() const {
    return _playerSprite.getGlobalBounds();
}

int Player::reduceHealth() {
    _healthPoints -= 1;
    return _healthPoints;
}

bool Player::playerGotHit(Ennemi* ennemy) {
    if (_playerSprite.getGlobalBounds().findIntersection(ennemy->getGlobalBounds())) {
        this->reduceHealth();
        return true;
    }
    return false;
}

int Player::getHealth() {
    return _healthPoints;
}

void Player::displayHealth(sf::RenderWindow& window) {
    _healthText.setString("Health: " + std::to_string(this->getHealth()));
    window.draw(_healthText);
}

// sf::Vector2f Player::getCurrentSize() {
//     return _sizeModifier;
// }
//
// float Player::getSpeed() {
//     return _speedModifier;
// }

void Player::pushObject(Object *object) {
    this->_object.push_back(object);
}

bool Player::isDead() {
    if (_healthPoints <= 0) {
        return true;
    } else {
        return false;
    }
}

void Player::saveData(int waves, std::chrono::duration<float> timeElapsed) {

    std::ifstream reader(ASSETS_PATH "savedData.csv");
    std::string content, line;
    bool empty = true;
    if (reader.is_open()) {
        empty = false;
        std::getline(reader, line);
        while (std::getline(reader, line)) {
            if (line == "Past game scores:") {

            } else {
                content += line + "\n";
            }
        }
    }
    std::ofstream writer(ASSETS_PATH "savedData.csv");
    if (writer.is_open()) {
        writer << "Current score:" << '\n';
        writer << "Waved survived: " << waves << '\n';
        writer << "Time elapsed: " << timeElapsed.count() << '\n';
        if (!empty) {
            writer << "Past game scores:" << '\n';
            writer << content;
        }
        writer.close();
    }
    std::ifstream reader2(ASSETS_PATH "savedData.csv");
    std::string content2, line2;
    if (reader2.is_open()) {
        std::getline(reader2, line2);
        while (std::getline(reader2, line2)) {
            content2 += line2 + "\n";
        }
        _ss << content2;
    }
}

void Player::displayStats(sf::RenderWindow& resultsWindow) {
    std::ifstream reader(ASSETS_PATH "savedData.csv");
    std::string content, line;
    _scoreText.setString(this->_ss.str());
    resultsWindow.draw(_scoreText);
}

int Player::getCats() {
    return this->_catNumber;
}


void Player::quit(sf::RenderWindow& window) {
    _quitText.setString("Press Q to quit");
    window.draw(_quitText);
}

void Player::renderMoney(sf::RenderWindow &window) {
    _catNumberText.setString("Cat money : " + std::to_string(this->_catNumber));
    window.draw(_catNumberText);
}

void Player::addMoney(double globalModifier) {
    this->_catNumber += 10 + round(1*globalModifier);
}

void Player::hasBoughtItem(Object *object) {
    _catNumber -= object->getCost();
}

void Player::addHealth() {
    this->_healthPoints = _maxHealthPoints;
}

int Player::getMaxHealth() {
    return this->_maxHealthPoints;
}

void Player::setPlayerBeforeWave() {
    for (size_t i = 0; i < _object.size();i++) {
        if (!_object[i]->getIsUsed()) {
            this->_maxHealthPoints+= _object[i]->getHealthModifier();
            this->_speedmodifier+=_object[i]->getSpeedModifier();
            this->_sizeModifier -= _object[i]->getSizeModifier();
            if (_sizeModifier.x > 1.f && _sizeModifier.y > 1.f) {
                this->_playerSprite.setScale(_sizeModifier);
            } else {
                this->_playerSprite.setScale({1.f,1.f});
            }
        }
    }
}

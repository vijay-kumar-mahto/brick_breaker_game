#include "Brick.h"

Brick::Brick(float x, float y, int strength) 
    : hitPoints(strength) {
    shape.setSize(sf::Vector2f(80, 30));
    shape.setPosition(x, y);
    shape.setOrigin(40, 15);
    shape.setFillColor(strength == 1 ? sf::Color::Green : sf::Color::Blue);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);
}

void Brick::draw(sf::RenderWindow& window) const { // Added const
    window.draw(shape);
}

sf::FloatRect Brick::getBounds() const {
    return shape.getGlobalBounds();
}

bool Brick::hit() {
    hitPoints--;
    if (hitPoints == 1) shape.setFillColor(sf::Color::Green);
    return hitPoints <= 0;
}

bool Brick::isDestroyed() const {
    return hitPoints <= 0;
}

sf::Vector2f Brick::getPosition() const {
    return shape.getPosition();
}
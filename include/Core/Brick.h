#ifndef BRICK_H
#define BRICK_H

#include <SFML/Graphics.hpp>

class Brick {
public:
    Brick(float x, float y, int strength);
    void draw(sf::RenderWindow& window) const; // Added const
    sf::FloatRect getBounds() const;
    bool hit();
    bool isDestroyed() const;
    sf::Vector2f getPosition() const;

private:
    sf::RectangleShape shape;
    int hitPoints;
};

#endif
#ifndef POWERUP_H
#define POWERUP_H

#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"

class PowerUp {
public:
    enum class Type { SpeedBoost, PaddleSize };
    
    PowerUp(sf::Vector2f position, Type type);
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window) const; // Added const
    sf::FloatRect getBounds() const;
    void applyEffect(Paddle& paddle, Ball& ball);
    bool isExpired() const;

private:
    sf::RectangleShape shape;
    Type powerUpType;
    float fallSpeed;
    float lifetime;
};

#endif
#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle {
public:
    Paddle(float x, float y);
    void update(sf::Time deltaTime, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    void reset();
    void applyPowerUp(float duration, float multiplier);

private:
    sf::RectangleShape shape;
    float speed;
    float baseWidth;
    float powerUpTimer;
    float powerUpMultiplier;
};

#endif
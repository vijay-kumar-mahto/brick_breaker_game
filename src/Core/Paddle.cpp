#include "Paddle.h"

Paddle::Paddle(float x, float y) 
    : speed(500.0f)
    , baseWidth(100.0f)
    , powerUpTimer(0.0f)
    , powerUpMultiplier(1.0f) {
    shape.setSize(sf::Vector2f(baseWidth, 20));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Cyan);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(2);
    shape.setOrigin(baseWidth / 2, 10);
}

void Paddle::update(sf::Time deltaTime, sf::RenderWindow& window) {
    float movement = 0.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        movement = -speed * deltaTime.asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        movement = speed * deltaTime.asSeconds();

    shape.move(movement, 0);
    
    // Keep paddle in bounds
    if (shape.getPosition().x < baseWidth/2)
        shape.setPosition(baseWidth/2, shape.getPosition().y);
    if (shape.getPosition().x > window.getSize().x - baseWidth/2)
        shape.setPosition(window.getSize().x - baseWidth/2, shape.getPosition().y);

    // Handle power-up duration
    if (powerUpTimer > 0) {
        powerUpTimer -= deltaTime.asSeconds();
        if (powerUpTimer <= 0) {
            shape.setSize(sf::Vector2f(baseWidth, 20));
            shape.setOrigin(baseWidth/2, 10);
        }
    }
}

void Paddle::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Paddle::getBounds() const {
    return shape.getGlobalBounds();
}

void Paddle::reset() {
    shape.setPosition(400, 550);
    shape.setSize(sf::Vector2f(baseWidth, 20));
    powerUpTimer = 0.0f;
}

void Paddle::applyPowerUp(float duration, float multiplier) {
    powerUpTimer = duration;
    powerUpMultiplier = multiplier;
    shape.setSize(sf::Vector2f(baseWidth * multiplier, 20));
    shape.setOrigin(baseWidth * multiplier / 2, 10);
}
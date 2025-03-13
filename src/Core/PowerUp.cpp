#include "PowerUp.h"

PowerUp::PowerUp(sf::Vector2f position, Type type)
    : powerUpType(type)
    , fallSpeed(200.0f)
    , lifetime(10.0f) {
    shape.setSize(sf::Vector2f(30, 30));
    shape.setPosition(position);
    shape.setOrigin(15, 15);
    shape.setFillColor(type == Type::SpeedBoost ? sf::Color::Yellow : sf::Color::Magenta);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);
}

void PowerUp::update(sf::Time deltaTime) {
    shape.move(0, fallSpeed * deltaTime.asSeconds());
    lifetime -= deltaTime.asSeconds();
}

void PowerUp::draw(sf::RenderWindow& window) const { // Added const
    window.draw(shape);
}

sf::FloatRect PowerUp::getBounds() const {
    return shape.getGlobalBounds();
}

void PowerUp::applyEffect(Paddle& paddle, Ball& ball) {
    switch (powerUpType) {
        case Type::SpeedBoost:
            ball.setSpeed(600.0f);
        break;
        case Type::PaddleSize:
            paddle.applyPowerUp(5.0f, 1.5f);
        break;
    }
}

bool PowerUp::isExpired() const {
    return lifetime <= 0 || shape.getPosition().y > 600;
}
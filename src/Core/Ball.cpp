#include "Ball.h"

Ball::Ball(float x, float y, sf::Sound& paddleSound)
    : baseSpeed(400.0f)
    , outOfBounds(false)
    , paddleHitSound(paddleSound) {
    shape.setRadius(10);
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Yellow);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(2);
    shape.setOrigin(10, 10);
    velocity = sf::Vector2f(baseSpeed, -baseSpeed);
}

void Ball::update(sf::Time deltaTime, const Paddle& paddle, sf::RenderWindow& window) {
    shape.move(velocity * deltaTime.asSeconds());

    if (shape.getPosition().x <= 10 || shape.getPosition().x >= window.getSize().x - 10)
        bounceHorizontal();
    if (shape.getPosition().y <= 40)
        bounceVertical();

    if (getBounds().intersects(paddle.getBounds())) {
        bounceVertical();
        paddleHitSound.play(); // Play paddle hit sound
        float paddleCenter = paddle.getBounds().left + paddle.getBounds().width / 2;
        float ballCenter = shape.getPosition().x;
        float angle = (ballCenter - paddleCenter) / (paddle.getBounds().width / 2);
        velocity.x = baseSpeed * angle;
    }

    outOfBounds = shape.getPosition().y > window.getSize().y;
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Ball::getBounds() const {
    return shape.getGlobalBounds();
}

void Ball::bounceVertical() {
    velocity.y = -velocity.y;
}

void Ball::bounceHorizontal() {
    velocity.x = -velocity.x;
}

void Ball::reset() {
    shape.setPosition(400, 500);
    velocity = sf::Vector2f(baseSpeed, -baseSpeed);
    outOfBounds = false;
}

bool Ball::isOutOfBounds() const {
    return outOfBounds;
}

void Ball::setSpeed(float speed) {
    baseSpeed = speed;
    velocity = sf::Vector2f(baseSpeed * (velocity.x > 0 ? 1 : -1), velocity.y);
}
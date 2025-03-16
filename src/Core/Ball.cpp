//
// Created by vijay on 3/13/25.
//

#include "Ball.h"

/**
 * Constructor for the Ball class.
 * Initializes a ball with a specified position and sound effect.
 *
 * @param x - The initial x-coordinate of the ball
 * @param y - The initial y-coordinate of the ball
 * @param paddleSound - Reference to the sound effect played when the ball hits the paddle
 */
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

/**
 * Updates the ball's position and handles collisions.
 * Moves the ball according to its velocity, checks for collisions with walls and paddle,
 * and adjusts the ball's trajectory accordingly.
 *
 * @param deltaTime - Time elapsed since the last update
 * @param paddle - Reference to the paddle for collision detection
 * @param window - Reference to the game window for boundary checks
 */
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

/**
 * Draws the ball on the screen.
 *
 * @param window - Reference to the render window where the ball will be drawn
 */
void Ball::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

/**
 * Gets the bounding rectangle of the ball.
 * Used for collision detection.
 *
 * @return FloatRect representing the ball's boundaries
 */
sf::FloatRect Ball::getBounds() const {
    return shape.getGlobalBounds();
}

/**
 * Causes the ball to bounce in the vertical direction.
 * Inverts the y-component of the velocity.
 */
void Ball::bounceVertical() {
    velocity.y = -velocity.y;
}

/**
 * Causes the ball to bounce in the horizontal direction.
 * Inverts the x-component of the velocity.
 */
void Ball::bounceHorizontal() {
    velocity.x = -velocity.x;
}

/**
 * Resets the ball to its initial position and state.
 * Called when starting a new game or after the ball goes out of bounds.
 */
void Ball::reset() {
    shape.setPosition(400, 500);
    velocity = sf::Vector2f(baseSpeed, -baseSpeed);
    outOfBounds = false;
}

/**
 * Checks if the ball is out of bounds.
 *
 * @return true if the ball has fallen below the bottom of the screen, false otherwise
 */
bool Ball::isOutOfBounds() const {
    return outOfBounds;
}

/**
 * Sets the ball's speed.
 * Updates the base speed while preserving the current direction.
 *
 * @param speed - The new base speed for the ball
 */
void Ball::setSpeed(float speed) {
    baseSpeed = speed;
    velocity = sf::Vector2f(baseSpeed * (velocity.x > 0 ? 1 : -1), velocity.y);
}
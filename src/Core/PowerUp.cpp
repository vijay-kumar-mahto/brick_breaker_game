//
// Created by vijay on 3/13/25.
//

#include "PowerUp.h"

/**
 * Constructor for the PowerUp class.
 * @param position Starting position vector for the power-up
 * @param type The type of power-up (SpeedBoost or PaddleSize)
 *
 * Similar to the Paddle and Brick constructors, initializes visual properties
 * and behavior parameters. Color depends on the power-up type: Yellow for
 * SpeedBoost and Magenta for PaddleSize.
 */
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

/**
 * Updates the power-up's position and lifetime.
 * @param deltaTime Time elapsed since the last update
 *
 * Unlike Paddle's update which handles input, this function only manages
 * the downward movement and lifetime countdown of the power-up.
 * Simpler than the Paddle update but shares the time-based movement pattern.
 */
void PowerUp::update(sf::Time deltaTime) {
    shape.move(0, fallSpeed * deltaTime.asSeconds());
    lifetime -= deltaTime.asSeconds();
}

/**
 * Draws the power-up on the specified render window.
 * @param window The target rendering window
 *
 * Identical to the draw methods in Brick and Paddle classes,
 * renders the power-up's shape to the window. Declared const
 * like Brick::draw for consistency.
 */
void PowerUp::draw(sf::RenderWindow& window) const { // Added const
    window.draw(shape);
}

/**
 * Gets the global bounding rectangle of the power-up.
 * @return The power-up's bounding rectangle for collision detection
 *
 * Identical to the getBounds methods in Brick and Paddle classes,
 * used for collision detection with the paddle.
 */
sf::FloatRect PowerUp::getBounds() const {
    return shape.getGlobalBounds();
}

/**
 * Applies the power-up's effect to game elements.
 * @param paddle Reference to the player's paddle
 * @param ball Reference to the game ball
 *
 * Unlike other classes, this function modifies external objects.
 * For SpeedBoost, increases ball speed directly.
 * For PaddleSize, calls the paddle's applyPowerUp method which
 * was seen in the Paddle class.
 */
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

/**
 * Checks if the power-up should be removed from the game.
 * @return true if the power-up has expired or fallen off-screen
 *
 * Similar conceptually to Brick::isDestroyed() but with different
 * conditions - checks both the lifetime counter and position.
 */
bool PowerUp::isExpired() const {
    return lifetime <= 0 || shape.getPosition().y > 600;
}
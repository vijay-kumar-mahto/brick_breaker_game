//
// Created by vijay on 3/13/25.
//

#include "Paddle.h"

/**
 * Constructor for the Paddle class.
 * @param x Initial x-coordinate for the paddle position
 * @param y Initial y-coordinate for the paddle position
 *
 * Initializes paddle properties including movement speed, width, power-up status,
 * and visual appearance. Sets the origin to the center of the paddle.
 */
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

/**
 * Updates the paddle's position and state based on input and time.
 * @param deltaTime Time elapsed since the last update
 * @param window Reference to the game window for boundary checking
 *
 * Handles left/right movement via keyboard input, keeps the paddle within
 * screen boundaries, and manages power-up timer countdown and effects.
 */
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

/**
 * Renders the paddle to the game window.
 * @param window Reference to the target render window
 *
 * Draws the paddle's visual representation at its current position.
 */
void Paddle::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

/**
 * Gets the global bounding rectangle of the paddle.
 * @return The paddle's bounding rectangle for collision detection
 *
 * Used for collision detection with the ball and other game elements.
 */
sf::FloatRect Paddle::getBounds() const {
    return shape.getGlobalBounds();
}

/**
 * Resets the paddle to its initial state.
 *
 * Sets the paddle back to its default position, size, and clears
 * any active power-ups. Called when starting a new game or after losing a life.
 */
void Paddle::reset() {
    shape.setPosition(400, 550);
    shape.setSize(sf::Vector2f(baseWidth, 20));
    powerUpTimer = 0.0f;
}

/**
 * Applies a size-changing power-up to the paddle.
 * @param duration How long the power-up effect should last in seconds
 * @param multiplier Factor by which to change the paddle's width
 *
 * Modifies the paddle's size and updates its origin point to maintain
 * proper centering. Power-up effect will expire after the specified duration.
 */
void Paddle::applyPowerUp(float duration, float multiplier) {
    powerUpTimer = duration;
    powerUpMultiplier = multiplier;
    shape.setSize(sf::Vector2f(baseWidth * multiplier, 20));
    shape.setOrigin(baseWidth * multiplier / 2, 10);
}
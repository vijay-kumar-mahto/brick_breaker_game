//
// Created by vijay on 3/13/25.
//

#include "Brick.h"

/**
 * Constructor for the Brick class.
 * @param x X-coordinate for the brick position
 * @param y Y-coordinate for the brick position
 * @param strength Number of hits required to destroy the brick
 *
 * Sets up the brick's visual appearance and hit points based on strength.
 * Green bricks have 10 hit point, blue bricks have 5 hit point.
 */
Brick::Brick(float x, float y, int strength) 
    : hitPoints(strength) {
    shape.setSize(sf::Vector2f(80, 30));
    shape.setPosition(x, y);
    shape.setOrigin(40, 15);
    shape.setFillColor(strength == 1 ? sf::Color::Green : sf::Color::Blue);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);
}

/**
 * Draws the brick on the specified render window.
 * @param window The target rendering window
 *
 * Renders the brick's shape to the window.
 */
void Brick::draw(sf::RenderWindow& window) const { // Added const
    window.draw(shape);
}

/**
 * Gets the global bounding rectangle of the brick.
 * @return The brick's bounding rectangle for collision detection
 */
sf::FloatRect Brick::getBounds() const {
    return shape.getGlobalBounds();
}

/**
 * Processes a hit on the brick, reducing its hit points.
 * @return true if the brick is destroyed (hit points <= 0), false otherwise
 *
 * When hit points reach 1, the brick changes color to green.
 */
bool Brick::hit() {
    hitPoints--;
    if (hitPoints == 1) shape.setFillColor(sf::Color::Green);
    return hitPoints <= 0;
}

/**
 * Checks if the brick has been destroyed.
 * @return true if the brick is destroyed (hit points <= 0), false otherwise
 */
bool Brick::isDestroyed() const {
    return hitPoints <= 0;
}

/**
 * Gets the current position of the brick.
 * @return The position vector of the brick
 */
sf::Vector2f Brick::getPosition() const {
    return shape.getPosition();
}
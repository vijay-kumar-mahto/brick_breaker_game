//
// Created by vijay on 3/13/25.
//

#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> // Added for sound
#include "Paddle.h"

class Ball {
public:
    Ball(float x, float y, sf::Sound& paddleSound); // Updated constructor
    void update(sf::Time deltaTime, const Paddle& paddle, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    void bounceVertical();
    void bounceHorizontal();
    void reset();
    bool isOutOfBounds() const;
    void setSpeed(float speed);

    sf::Sound& paddleHitSound; // Reference to sound from Game

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float baseSpeed;
    bool outOfBounds;
};

#endif
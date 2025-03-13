//
// Created by vijay on 3/13/25.
//

#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>

class Screen {
public:
    virtual ~Screen() = default;
    virtual void handleEvents(sf::RenderWindow& window) = 0;
    virtual void update(sf::Time deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

#endif
#include "GameScreen.h"
#include "MenuScreen.h"
#include "ResourceManager.h"

GameScreen::GameScreen(ScreenManager& screenManager)
    : screenManager(screenManager)
    , gameLogic(ResourceManager::getInstance().getSound("paddle_hit"))
    , hud()
    , menuClickSound(ResourceManager::getInstance().getSound("menu_click")) {
}

void GameScreen::handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            menuClickSound.play();
            screenManager.setScreen(std::make_unique<MenuScreen>(screenManager));
        }
    }
    hud.handleEvents(event, gameLogic, screenManager,menuClickSound);
}

void GameScreen::update(sf::Time deltaTime) {
    if (!gameLogic.isGameOver()) {
        gameLogic.update(deltaTime, screenManager.getWindow());
    }
    hud.update(gameLogic.getScore(), gameLogic.getLives(), gameLogic.getLevel(), gameLogic); // Updated to pass gameLogic
}

void GameScreen::render(sf::RenderWindow& window) {
    window.clear(sf::Color(20, 20, 40));
    gameLogic.render(window);
    hud.render(window, gameLogic.isGameOver());
    window.display();
}

void GameScreen::resetGame(bool newGame, int selectedLevel, float speedMultiplier) {
    gameLogic.resetGame(newGame, selectedLevel, speedMultiplier);
}
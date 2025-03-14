#include "MenuScreen.h"
#include "GameScreen.h"
#include "ResourceManager.h"

MenuScreen::MenuScreen(ScreenManager& screenManager)
    : screenManager(screenManager)
    , interface()
    , records()
    , selectingLevel(false)
    , resumeAvailable(false)
    , menuClickSound(ResourceManager::getInstance().getSound("menu_click"))
    , highScore(records.getHighScore()) { // Initialize highScore
    interface.setup(screenManager.getWindow());
}

void MenuScreen::handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::N && !selectingLevel) {
                menuClickSound.play();
                selectingLevel = true;
            }
            else if (event.key.code == sf::Keyboard::R && resumeAvailable) {
                menuClickSound.play();
                screenManager.setScreen(std::make_unique<GameScreen>(screenManager));
            }
        }
        interface.handleMouseEvents(event, selectingLevel, resumeAvailable, menuClickSound, screenManager, highScore);
        if (highScore == 0) { // Check if reset occurred
            records.resetHighScore(); // Sync reset to GameRecords
        }
    }
}

void MenuScreen::update(sf::Time deltaTime) {
    interface.animate(deltaTime, selectingLevel, resumeAvailable, 0, 3, highScore, 1);
}

void MenuScreen::render(sf::RenderWindow& window) {
    window.clear(sf::Color(20, 20, 40));
    interface.renderMenu(window, selectingLevel, resumeAvailable, highScore);
    window.display();
}
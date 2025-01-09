#include "GameMapSprite.h"

GameMapSprite::GameMapSprite() {
    // Create a simple ground platform
    sf::RectangleShape ground(sf::Vector2f(800.0f, 50.0f));
    ground.setFillColor(sf::Color::Green);
    ground.setPosition(0.0f, 550.0f);
    platforms.push_back(ground);

    // Create a simple floating platform
    sf::RectangleShape platform(sf::Vector2f(200.0f, 20.0f));
    platform.setFillColor(sf::Color::Green);
    platform.setPosition(300.0f, 400.0f);
    platforms.push_back(platform);
}

void GameMapSprite::draw(sf::RenderWindow& window) {
    for (const auto& platform : platforms) {
        window.draw(platform);
    }
}
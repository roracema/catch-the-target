#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "sprites/PlayerSprite.h"
#include "sprites/GameMapSprite.h"

// Constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float PLAYER_SPEED = 200.0f;

int main() {
    // Initialize window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Catch the Target!");
    window.setFramerateLimit(60);

    // Initialize player
    PlayerSprite player("../textures/player/DogWalking.png", 68, 34, 10); // Assuming each frame is 68x34, 10 frames in one row
    player.setPosition(WINDOW_WIDTH / 2.0f, 500.0f); // Ground level

    // Initialize game map
    GameMapSprite gameMap;

    // Load sound buffer
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("../sounds/player/jumpland.wav")) {
        // Handle error
        return -1;
    }

    // Create sound
    sf::Sound sound;
    sound.setBuffer(buffer);

    // Clock for delta time
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time deltaTime = clock.restart();
        sf::Vector2f movement(0.0f, 0.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player.jump();
            sound.play(); // Play sound when jumping
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            movement.x -= PLAYER_SPEED * deltaTime.asSeconds();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            movement.x += PLAYER_SPEED * deltaTime.asSeconds();
        }

        player.move(movement.x, movement.y);
        player.update(deltaTime.asSeconds());

        window.clear(sf::Color::White); // Change background color to white
        gameMap.draw(window);
        player.draw(window);
        window.display();
    }

    return 0;
}
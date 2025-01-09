#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H

#include <SFML/Graphics.hpp>
#include <vector>

class PlayerSprite {
public:
    PlayerSprite(const std::string& textureFile, int frameWidth, int frameHeight, int numFrames);
    void setPosition(float x, float y);
    void move(float offsetX, float offsetY);
    void jump();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::Texture texture;
    sf::Sprite sprite;
    std::vector<sf::IntRect> frames;
    int currentFrame;
    float frameTime;
    float elapsedTime;
    bool isJumping;
    float jumpSpeed;
    float gravity;
    bool facingRight; // New member to track the direction
};

#endif // PLAYERSPRITE_H
#include "PlayerSprite.h"

PlayerSprite::PlayerSprite(const std::string& textureFile, int frameWidth, int frameHeight, int numFrames)
    : currentFrame(0), frameTime(0.1f), elapsedTime(0.0f), isJumping(false), jumpSpeed(0.0f), gravity(500.0f), facingRight(true) {
    if (!texture.loadFromFile(textureFile)) {
        // Handle error
    }
    sprite.setTexture(texture);

    // Divide the spritesheet into frames
    for (int i = 0; i < numFrames; ++i) {
        frames.push_back(sf::IntRect(0, i * frameWidth, frameWidth, frameHeight));
    }
    sprite.setTextureRect(frames[0]);
    sprite.setOrigin(frameWidth / 2.0f, frameHeight / 2.0f); // Set origin to the center of the frame
}

void PlayerSprite::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void PlayerSprite::move(float offsetX, float offsetY) {
    sprite.move(offsetX, offsetY);

    // Change direction based on movement
    if (offsetX > 0 && !facingRight) {
        facingRight = true;
        sprite.setScale(1.0f, 1.0f); // Face right
    } else if (offsetX < 0 && facingRight) {
        facingRight = false;
        sprite.setScale(-1.0f, 1.0f); // Face left
    }
}

void PlayerSprite::jump() {
    if (!isJumping) {
        isJumping = true;
        jumpSpeed = -300.0f; // Initial jump speed
    }
}

void PlayerSprite::update(float deltaTime) {
    // Update animation frame
    elapsedTime += deltaTime;
    if (elapsedTime >= frameTime) {
        elapsedTime = 0.0f;
        currentFrame = (currentFrame + 1) % frames.size();
        sprite.setTextureRect(frames[currentFrame]);
    }

    // Update jump logic
    if (isJumping) {
        sprite.move(0, jumpSpeed * deltaTime);
        jumpSpeed += gravity * deltaTime; // Apply gravity

        if (sprite.getPosition().y >= 500.0f) { // Ground level
            sprite.setPosition(sprite.getPosition().x, 500.0f);
            isJumping = false;
        }
    }
}

void PlayerSprite::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect PlayerSprite::getBounds() const {
    return sprite.getGlobalBounds();
}
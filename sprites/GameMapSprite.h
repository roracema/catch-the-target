#ifndef GAMEMAPSPRITE_H
#define GAMEMAPSPRITE_H

#include <SFML/Graphics.hpp>
#include <vector>

class GameMapSprite {
public:
    GameMapSprite();
    void draw(sf::RenderWindow& window);

private:
    std::vector<sf::RectangleShape> platforms;
};

#endif // GAMEMAPSPRITE_H
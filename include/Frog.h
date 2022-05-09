#pragma once

#include <iostream>
#include <list>

#include "SFML/Graphics.hpp"
#include "Resources.h"
#include "Macros.h"
#include "Tile.h"

using std::cout;
using std::endl;

class Frog
{
public:
    Frog();
    void updateAndDraw(sf::RenderWindow& window);
    void move(int ,int);
    void movePos(sf::Vector2<float>, float);
    sf::Vector2f posToPixels(int, int);
    std::pair<int, int> getTile() const;

private:    
    sf::Texture* m_texture;
    sf::Sprite m_sprite;
};

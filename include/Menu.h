#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"
#include "Resources.h"
#include "Macros.h"

using std::cout;
using std::endl;

class Menu
{
public:
    Menu();
    void  updateAndDraw(sf::RenderWindow& window);
    bool clicked(sf::Vector2f mousePos, menu i);// todo
    void hover(sf::Vector2f mousePos);
    void drawSpacificButton(sf::RenderWindow& window,menu i);

private:
    sf::Text text;
    vector< sf::Texture *>m_texture;
    vector< sf::Sprite > m_sprite;
};

#pragma once
#include "SFML/Graphics.hpp"
#include "Resources.h"
#include <iostream>
#include "Macros.h"


using std::cout;
using std::endl;

class Tile 
{
public:
	Tile(const  sf::Vector2f position,float scale,bool isClicked=false);
    sf::Sprite getSprite() const;
    void setPosition(const sf::Vector2f position);
    sf::Vector2<float> getLocation( ) const;
    void  updateAndDraw(sf::RenderWindow& window);
    void clicked(sf::Vector2f mousePos);


private:
    bool m_isClicked;
    sf::Texture m_texture;
    sf::Sprite m_sprite;

};
//
// Created by Bar Oren on 29/04/2022.
//


#pragma once
#include "SFML/Graphics.hpp"
#include "Resources.h"
#include <iostream>
#include "Macros.h"


using std::cout;
using std::endl;

class GameObject
{
public:
    Tile(const  sf::Vector2f position,float scale);
    sf::Sprite getSprite() const;
    void setPosition(const sf::Vector2f position);
    sf::Vector2<float> getLocation( ) const;
    void  updateAndDraw(sf::RenderWindow& window);


private:
    vector< sf::Texture >m_texture;
    vector< sf::Sprite> m_sprite;

};
#pragma once
#include <iostream>
#include <list>

#include "SFML/Graphics.hpp"
#include "Resources.h"
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

    void addNeighbor(Tile *); // todo - meytal

private:
    bool m_isClicked;
    sf::Texture *m_texture;
    sf::Sprite m_sprite;

    std::list<Tile*> m_neighbors; // todo - meytal
};
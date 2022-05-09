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
	Tile(const sf::Vector2f position,float scale, bool = false,int=0 ,int=0);

    void setPosition(const sf::Vector2f position);
    void updateAndDraw(sf::RenderWindow& window);
    bool clicked(sf::Vector2f mousePos);
    auto getBegin() { return m_neighbors.begin(); };
    auto getEnd() { return m_neighbors.end(); };
    void addNeighbor(Tile *);
    void setColor(colorId);
    bool isLimit() { return m_isLimit; }; //todo const
    void setFoundBy(Tile* tile) { m_foundBy = tile; };
    void checkNeighbors();

    sf::Sprite getSprite() const;
    sf::Vector2<float> getLocation( ) const;
    Tile* getFoundBy() { return m_foundBy; };
    colorId getColor() { return m_color; }; // todo const

private:
    bool m_isClicked = false;
    bool m_isLimit;
    
    colorId m_color = colorId::white;
    Tile* m_foundBy = nullptr;   
    sf::Texture *m_texture;
    sf::Sprite m_sprite;
    std::list<Tile*> m_neighbors; // sherdptr
};

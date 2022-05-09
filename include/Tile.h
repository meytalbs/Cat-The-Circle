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

    void setPosition(const sf::Vector2f position); // Integrity check
    void updateAndDraw(sf::RenderWindow& window);
    bool clicked(sf::Vector2f mousePos);
    const auto getBegin() { return m_neighbors.begin(); };
    const auto getEnd() { return m_neighbors.end(); };
    void addNeighbor(Tile *);
    void setColor(colorId); // Integrity check
    const bool isLimit() { return m_isLimit; }; 
    void setFoundBy(Tile* tile) { m_foundBy = tile; }; // Integrity check
    void checkNeighbors();

    sf::Sprite getSprite() const;
    sf::Vector2<float> getLocation() const;
    Tile* getFoundBy() { return m_foundBy; };
    const colorId getColor() { return m_color; }; 

private:
    bool m_isClicked = false;
    bool m_isLimit;
    
    colorId m_color = colorId::white;
    Tile* m_foundBy = nullptr;   
    sf::Texture *m_texture;
    sf::Sprite m_sprite;
    std::list<Tile*> m_neighbors; 
};

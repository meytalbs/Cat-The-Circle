#pragma once
#include <iostream>
#include <list>

#include "SFML/Graphics.hpp"
#include "Resources.h"
#include "Macros.h"


using std::cout;
using std::endl;

class Frog
{
public:
    Frog();
  //  sf::Sprite getSprite() const;
   /// void setPosition(const sf::Vector2f position);
    //sf::Vector2<float> getLocation() const;
    void  updateAndDraw(sf::RenderWindow& window);
    void move(int ,int);
    sf::Vector2f posToPixels(int, int);
    void  movePos(sf::Vector2<float>,float );
  

private:
    
    sf::Texture* m_texture;
    sf::Sprite m_sprite;

};
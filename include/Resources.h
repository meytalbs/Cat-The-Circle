#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <array>

#include "Macros.h"

using std::vector;
using std::string;

class Resources 
{
public:
    Resources(const Resources &) = delete;

    static Resources &instance();
    void operator=(const Resources &) = delete;

    sf::Texture *getTexture(gameObjectId id);
    sf::Font& getFont() ;
    sf::Sprite* getSprite(gameObjectId id); // todo


private:
    Resources();
    void buildTexture();
    void buildSprite();
    sf::Texture m_temp;
    std::array <sf::Sprite, numOfSprites> m_sprite;//why arr and not vector ?
    std::array <sf::Texture, numOfSprites> m_texture;
    vector <string> m_imagePath = {"Boat","moves","Reset","Tile","staticFrog","nextLevel","X","undo","restart"};
    sf::Font m_font;
};
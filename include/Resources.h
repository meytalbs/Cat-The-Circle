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
   // sf::Music& getMusic(gameObjectId id) ;

    //Animation *getAnimation(gameObjectId id) ;
   // int getNunOfAnim();
    //int getNunOfFrames(gameObjectId id);

private:
    Resources();
    void buildTexture();
    void buildSprite();
  //  void buildAnimation();
  //  void buildMusic();
    sf::Texture m_temp;
    std::array <sf::Sprite, 8> m_sprite;//why arr and not vector ?
    std::array <sf::Texture, 8> m_texture;
    vector <string> m_imagePath = {"Boat","moves","Reset","Tile","staticFrog","nextLevel","X","undo"};
    //vector <string> m_musicNames={"MainMenuMusic.ogg"};
   // vector<Animation *> m_animation;
    //sf::Music m_music;
    //int numOfAnim=1;
    //vector<int>numOfFrames{ 4,3,3,3 ,3,4,4,4,1,4,4,1,4,1,4,1,1,1,1};
    sf::Font m_font;
};
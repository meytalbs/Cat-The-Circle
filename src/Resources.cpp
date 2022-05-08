#include "Resources.h"
Resources::Resources() {
    if (!m_font.loadFromFile("arcadeClassic.ttf")) {
        // error...
        std::cout << "error loading font";

    }
    buildTexture();
    //buildAnimation();
    buildSprite();
  //  buildMusic();
    //add sound
}


void Resources::buildTexture() {
    for(int i=0;i<m_imagePath.size();i++) {
        if (!m_texture[i].loadFromFile(m_imagePath[i] + ".png"))
            exit(EXIT_FAILURE);
        /*
        if (!m_temp.loadFromFile(m_imagePath[i]+".png")) {
            // error...
            std::cout << "error loading font";

        }
        m_texture.push_back(m_temp);
        */
    }
}

sf::Texture* Resources::getTexture(gameObjectId id)
{
    return &m_texture[(int)id];

}
sf::Sprite* Resources::getSprite(gameObjectId id) 
{
    return &m_sprite[(int)id];

}

void Resources::buildSprite()
{
    for(int i=0;i<m_imagePath.size();i++) {
        m_sprite[i].setTexture(m_texture[i]);

        /*
        sf::Sprite temp;
        temp.setTexture(m_texture[i]);
        m_sprite.push_back(temp);
        */

       m_sprite[i].setOrigin(m_sprite[i].getGlobalBounds().width /2.f,m_sprite[i].getGlobalBounds().height /2.f);

    }
}
sf::Font& Resources::getFont()
{
    return m_font;
}
Resources& Resources:: instance(){
    static auto resources=Resources();
    return resources;
}


/*
Animation* Resources::getAnimation(gameObjectId id)
{
    return m_animation[(int)id];
}
void Resources :: buildAnimation()
{
    for(int i=0; i<m_texture.size();i++) {
        Animation* temp=new Animation((&m_texture[i]),sf::Vector2u(numOfFrames[i],numOfAnim),0.17);
        m_animation.push_back(temp);
    }
}
int Resources::getNunOfFrames(gameObjectId id)
{
    return numOfFrames[(int)id];
}
int Resources::getNunOfAnim()
{
    return numOfAnim;
}
void Resources::buildMusic()
{

    for(int i=0;i<m_musicNames.size();i++) {
        // sf::Music temp;
        if (!m_music.openFromFile(m_musicNames[i])) {
            // error...
            std::cout << "error loading music";

        }
        // m_music.push_back(temp);
    }
}
sf::Music& Resources::getMusic(gameObjectId id)
{
    return m_music;

}


 */
//
// Created by Bar Oren on 29/04/2022.
//

#include "Menu.h"

Menu::Menu()
{
    m_texture.push_back(Resources::instance().getTexture(gameObjectId::moves));
    m_texture.push_back(Resources::instance().getTexture(gameObjectId::reset));

    m_sprite.push_back(Resources::instance().getSprite(gameObjectId::moves));
    m_sprite.push_back(Resources::instance().getSprite(gameObjectId::reset));

    for(int i =0 ;i<m_sprite.size() ;i++) {
        (*m_sprite[i]).setPosition(sf::Vector2f(1300,MARGIN_TOP+800*i));//
    }

}

void Menu::updateAndDraw(sf::RenderWindow& window)
{
    for(int i =0 ;i<m_sprite.size() ;i++) {
        window.draw(*m_sprite[i]);
    }
}
#include "Menu.h"

Menu::Menu()
{
    m_texture.push_back(Resources::instance().getTexture(gameObjectId::moves));
    m_texture.push_back(Resources::instance().getTexture(gameObjectId::reset));
    m_texture.push_back(Resources::instance().getTexture(gameObjectId::undo));

    m_texture.push_back(Resources::instance().getTexture(gameObjectId::nextLevel));
    m_texture.push_back(Resources::instance().getTexture(gameObjectId::x));

    m_sprite.push_back(*Resources::instance().getSprite(gameObjectId::moves));
    m_sprite.push_back(*Resources::instance().getSprite(gameObjectId::undo));

    m_sprite.push_back(*Resources::instance().getSprite(gameObjectId::reset));

    m_sprite.push_back(*Resources::instance().getSprite(gameObjectId::x));
    m_sprite.push_back(*Resources::instance().getSprite(gameObjectId::nextLevel));


    for(int i =0 ;i<m_sprite.size()-2 ;i++) {
        (m_sprite[i]).setPosition(sf::Vector2f(1300,MARGIN_TOP+400*i));//
    }
    (m_sprite[3]).setPosition(sf::Vector2f(40,40));//!! to do

    (m_sprite[4]).setPosition(sf::Vector2f(700,500));//!! to do
}
// ----------------------------------------------------------------------------

void Menu::updateAndDraw(sf::RenderWindow& window)
{
    for(int i =0 ;i<m_sprite.size()-1 ;i++) {
        window.draw(m_sprite[i]);
    }
}
void Menu::drawSpacificButton(sf::RenderWindow& window,menu i)
{

        window.draw(m_sprite[int(i)]);

}
// ----------------------------------------------------------------------------

bool Menu::clicked(sf::Vector2f mousePos, menu i) // todo
{
    cout << int (i)<<endl;
    if (m_sprite[int(i)].getGlobalBounds().contains(mousePos))
    {

        return true;
    }
}
// ----------------------------------------------------------------------------

void Menu::hover(sf::Vector2f mousePos)
{
    for(int i=1 ;i <3;i++)
        if ((m_sprite[i]).getGlobalBounds().contains(mousePos))
        {
            m_sprite[i].setColor(sf::Color(150, 200, 255));
        }else
            m_sprite[i].setColor(sf::Color(255, 255, 255));

}
// ----------------------------------------------------------------------------

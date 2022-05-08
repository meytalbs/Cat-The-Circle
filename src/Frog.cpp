#include "Frog.h"


Frog::Frog() {
    m_texture = Resources::instance().getTexture(gameObjectId::frog); // why do we need it?
    m_sprite = *Resources::instance().getSprite(gameObjectId::frog);
    ///move(6, 5);

    m_sprite.scale(1, 1);    
}
//------------------------------------------

void Frog::updateAndDraw(sf::RenderWindow& window)
{
    //m_animation->update(row,deltaTime);
   // m_sprite.setTextureRect(m_animation->getRect());

    window.draw(m_sprite);

}


std::pair<int,int> Frog::getTile()const
{
    std::pair<int, int> pos;

    pos.first = m_sprite.getPosition().x - MARGIN_RIGHT +40 ;
    pos.first = (pos.first /SPACE)%10;
    pos.second = m_sprite.getPosition().y - MARGIN_TOP;
    pos.second =( pos.second / SPACE)%10;
    return pos;
}
//------------------------------------------
void Frog::movePos(sf::Vector2<float> pos,float delta )
{
    auto dir = pos - m_sprite.getPosition();

       m_sprite.setPosition(pos);

    
}
void Frog::move(int x,int y)
{
    
    m_sprite.setPosition(posToPixels(y,x));
}
//------------------------------------------
sf::Vector2f Frog::posToPixels(int x, int y)
{
    sf::Vector2f pos;

    if (y % 2 == 0) {
        pos=sf::Vector2f(MARGIN_RIGHT - 40 + SPACE * y,
            MARGIN_TOP + SPACE * x);
    }
    else
       pos=sf::Vector2f(MARGIN_RIGHT + SPACE * y,
            MARGIN_TOP + SPACE * x);

    return pos;
}
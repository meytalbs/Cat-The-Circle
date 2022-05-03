#include "Tile.h"

using std::cout;
using std::endl;

Tile::Tile(const  sf::Vector2f position, float scale, bool isClicked) : 
    m_isClicked(isClicked)
{
    m_texture = Resources::instance().getTexture(gameObjectId::tile); // why do we need it?
    m_sprite = *Resources::instance().getSprite(gameObjectId::tile);

    m_sprite.setPosition(position); 
    m_sprite.scale(scale, scale); 


}
// ----------------------------------------------------------------------------


sf::Sprite Tile::getSprite() const
{
    return m_sprite;
}
// ----------------------------------------------------------------------------


//  set location of the object
void Tile::setPosition(const sf::Vector2f position)
{
    m_sprite.setPosition(position);
}
// ----------------------------------------------------------------------------


sf::Vector2<float> Tile::getLocation() const
{
    return m_sprite.getPosition();
}
void Tile::updateAndDraw(sf::RenderWindow& window)
{
    //m_animation->update(row,deltaTime);
   // m_sprite.setTextureRect(m_animation->getRect());

    window.draw(m_sprite);

}
// ----------------------------------------------------------------------------


void Tile::clicked(sf::Vector2f mousePos) // todo
{
    if ((m_sprite).getGlobalBounds().contains(mousePos))
    {
        (m_sprite).setColor(sf::Color(150, 200, 255));
    }
}
// ----------------------------------------------------------------------------

/*
*/
void Tile::addNeighbor(Tile *tile) 
{
    m_neighbors.push_back(tile);
}
// ----------------------------------------------------------------------------


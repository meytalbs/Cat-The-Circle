#include "Tile.h"

Tile::Tile(std::string color, double x, double y)
	: m_location(Location(x, y)), m_color(color)
{}

void Tile::addNeighbor(Tile* tile)
{
	m_neighborsList.push_back(tile);
}

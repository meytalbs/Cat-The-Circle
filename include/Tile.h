#pragma once

#include <string>
#include <list>

struct Location // todo - add operator ==
{
	double locationX, locationY;
};

class Tile 
{
public:
	Tile( std::string color, double x = 0, double y = 0);
	void addNeighbor(Tile* tile);


private:
	std::string m_color;
	int m_dis = 10000; // todo - max int
	bool visited = false; // todo
	Location m_location;

	//bool active = true;
	std::list<Tile*> m_neighborsList;
};
#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <memory>
#include <string>
#include <random>
#include <string>
#include <iterator>

#include "Tile.h"
#include "Frog.h"

using std::vector;
using std::unique_ptr;
using std::make_unique;

//will act like "board" will contain a vector of vector of tiles

class Graph 
{
public:
    Graph(int rows=11, int cols=11,int level=1);
    void drawTiles(sf::RenderWindow& window);
    void checkIfClicked(sf::Vector2f mousePs,float);
    void randomaize(int level);

    vector<std::pair<int, int>> assertNum(int size);

    void updateNeighborsList();
    Tile* BFS(Tile* s);
    int getCounter() { return m_counter; };
private:
    Frog frog;//should move it to vector

    vector<vector<Tile>> m_tiles; 
    vector<Tile*> m_limits;
    int m_rows ;
    int m_cols ;
    int m_counter = 0;
};

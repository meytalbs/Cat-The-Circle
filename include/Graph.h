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

class Graph 
{
public:
    Graph(int rows=11, int cols=11,int level=1);
    void drawTiles(sf::RenderWindow& window);
    bool checkIfClicked(sf::Vector2f mousePs,float);
    void randomaize(int level);
    void updateNeighborsList();
    int getCounter() { return m_counter; } ;
    bool isGameOver(){return m_gameOver;} ;
    vector<std::pair<int, int>> assertNum(int size, int a ,int b);
    Tile* BFS(Tile* s);
    Tile* getFreeTile(Tile* s);
    void undo();

private:
    std::list<std::pair<Tile *, std::pair<int,int>>> m_history;
    Frog frog;    //should move it to vector
    vector<vector<Tile>> m_tiles; 
    vector<Tile*> m_limits;
    int m_rows;
    int m_cols;
    int m_counter = 0;
    bool m_gameOver = false;
};

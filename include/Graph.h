#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <vector>
#include <memory>
#include <string>
#include "Tile.h"
#include <random>
#include <string>
#include <iterator>
#include <algorithm>
#include "Frog.h"


using std::vector;
using std::unique_ptr;
using std::make_unique;

//will act like "board" will contain a vector of vector of tiles

struct Node {
    int key;
    std::string color = "white";

};


class Graph {
public:
    //Graph();
    Graph(int rows=11, int cols=11,int level=1);
    void drawTiles(sf::RenderWindow& window);
    void checkIfClicked(sf::Vector2f mousePs,float);
    void randomaize(int level);

    vector<std::pair<int, int>> assertNum(int size);

    void updateNeighborsList();   // todo - meytal

private:
    Frog frog;//should move it to vector

    vector<vector<Tile>> m_tiles; //
    int m_rows ;
    int m_cols ;
};



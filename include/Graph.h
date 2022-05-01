#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <vector>
#include <memory>
#include <string>
#include "Tile.h"

using std::vector;
using std::unique_ptr;
using std::make_unique;

//will act like "board" will contain a vector of vector of tiles
struct Node {
    int key;
    std::string color = "white";

};
*/

class Graph {
public:
    //Graph();
    Graph(int rows=11, int cols=11);
    void drawTiles(sf::RenderWindow& window);
    void checkIfClicked(sf::Vector2f mousePs);

private:
   // std::unordered_map<int, std::list<Node>> m_graph;
    vector<vector<unique_ptr<Tile>> > m_tiles;
    int m_rows ;
    int m_cols ;
};



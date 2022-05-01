
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>

#include "Tile.h"

/*
struct Node {
    int key;
    std::string color = "white";

};
*/

class Graph {
public:   
    Graph(int rows = 11, int cols = 11);

    void createTiles();
    void updateNeighborsList();
    //std::list<Node> getList(int);
    void BFS(Location source);

private:
    std::vector<std::vector<Tile>> m_graph;
    int m_rows = 11;
    int m_cols = 11;
};



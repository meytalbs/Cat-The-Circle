
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <list>
#include <string>

struct Node {
    int key;
    std::string color = "white";

};

class Graph {
public:   
    Graph();    
    Graph(int rows, int cols);

    std::list<Node> getList(int);

private:
    std::unordered_map<int, std::list<Node>> m_graph;
    int m_rows = 11;
    int m_cols = 11;
};



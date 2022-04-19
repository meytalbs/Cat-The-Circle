
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <list>
#include <unordered_set>

class Graph {
public:   
    Graph();    
    Graph(int rows, int cols);

    std::list<int> getList(int);

private:
    std::unordered_map<int, std::list<int>> m_graph;
    int m_rows = 11;
    int m_cols = 11;
};



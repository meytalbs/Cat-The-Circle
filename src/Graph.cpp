#include "Graph.h"


Graph::Graph(int rows, int cols)
    : m_rows(rows), m_cols(cols)
{
    // create all the tiles of the graph
    createTiles();

    // update nayber list of each tiles
    updateNeighborsList();
}
// ----------------------------------------------------------------------------


void Graph::createTiles()
{
    Tile newTile = Tile("white", 0, 0);
    std::vector<Tile> temp;
    
    for (int row = 0; row < m_rows; ++row)
    {
        for (int col = 0; col < m_rows; ++col)
        {
            newTile = Tile("white", 
                            col, //row % 2 == 0 ? col + 0.5 : col, 
                            row);

            temp.push_back(newTile); // todo maybe another function ?
        }
        m_graph.push_back(temp);
    }
}
// ----------------------------------------------------------------------------


void Graph::updateNeighborsList()
{
    int factor = 0, x, y;

    for (int row = 0; row < m_rows; ++row)
    {
        row % 2 == 0 ? factor = 0 : factor = 1;

        for (int col = 0; col < m_rows; ++col)
        {
            if (row > 0 && col - factor >= 0)                                           // up left
            {
                x = row - 1;
                y = col - factor;
                m_graph[row][col].addNeighbor(&m_graph[x][y]);
            }
            
            if (row > 0 && col + 1 - factor < m_cols)                                   // up right            
            {
                x = row - 1;
                y = col + 1 - factor;
                m_graph[row][col].addNeighbor(&m_graph[x][y]);
            }
            
            if (col > 0)                                                                // left
            {
                y = col - 1;
                m_graph[row][col].addNeighbor(&m_graph[row][y]);
            }
            
            if (col + 1 < m_cols)                                                       // right
            {
                y = col + 1;
                m_graph[row][col].addNeighbor(&m_graph[row][y]);
            }
            
            if (row + 1 < m_rows && col - factor > -1)                                  // down left
            {
                x = row + 1;
                y = col - factor;
                m_graph[row][col].addNeighbor(&m_graph[x][y]);
            }
            
            if (row + 1 < m_rows && col + 1 - factor < m_cols)                          // down right            
            {
                x = row + 1;
                y = col + 1 - factor;
                m_graph[row][col].addNeighbor(&m_graph[x][y]);            
            }
        }
    }
}
// ----------------------------------------------------------------------------

/*
// BFS algoritem
void Graph::BFS(Location location)
{
    Tile* startVertex;
    std::cout << "jkashdjksad\n";
    
    for (int row = 0; row < m_rows; ++row)
        for (int col = 0; col < m_rows; ++col)
            if (m_graph[row][col].m_location.locationX == location.locationX && m_graph[row][col].m_location.locationY == location.locationY)
            {
                startVertex = &m_graph[row][col];
                std::cout << "hi\n";
            }

    // Create a queue for BFS
    std::list<Tile*> queue;

    // Mark the current node as visited and enqueue it
 
    startVertex->visited = true;
    queue.push_back(startVertex);


    // 'i' will be used to get all adjacent
   // vertices of a vertex
    std::list<int>::iterator i;

    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        Tile* currVertex = queue.front();
        std::cout << "Visited " << currVertex->m_location.locationX << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        /*
        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
            int adjVertex = *i;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }


}
        */


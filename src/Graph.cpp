#include "Graph.h"


Graph::Graph(int rows, int cols,int level)
    : m_rows(rows), m_cols(cols)
{
    m_tiles.reserve(m_rows * m_cols); // todo - using operator * on 4 byte value....
    bool isLimit = false;

   for (int i = 0; i < m_rows ; ++i) {
        vector<Tile> temp;
        for (int j = 0; j < m_cols; j++) {

            if (i == 0 || i == m_rows - 1 || j == 0 || j == m_cols - 1)
                isLimit = true;

            if(j%2==0 ) 
                temp.push_back(Tile(sf::Vector2f(MARGIN_RIGHT-40 + SPACE * i,
                                                              MARGIN_TOP + SPACE * j), 0.4, isLimit));
            
            else
                temp.push_back(Tile(sf::Vector2f(MARGIN_RIGHT + SPACE * i,
                                                              MARGIN_TOP + SPACE * j), 0.4, isLimit));

            isLimit = false;
        }
        m_tiles.push_back(std::move(temp));
    }
    
   randomaize(level);
   
   updateNeighborsList();
}
// ----------------------------------------------------------------------------


void Graph::randomaize(int level)
{ 
    vector<std::pair<int, int>> vect;
    vect=assertNum(11);//will be chossed according to level

    for (int i = 0; i < 11;i++)
    {
        m_tiles[vect[i].first][vect[i].second].color();
    }
}
// ----------------------------------------------------------------------------


vector<std::pair<int, int>> Graph:: assertNum(int size)
{
    vector<std::pair<int, int>> temp;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 10); // define the range

    for (int i = 0; i < size;i++)
    {
        temp.push_back(std::make_pair(distr(gen), distr(gen)));
    }
    return temp;
}
// ----------------------------------------------------------------------------


void Graph::drawTiles(sf::RenderWindow& window) {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; j++) {
            m_tiles[i][j].updateAndDraw(window);
        }
    }
    frog.updateAndDraw(window);
}
// ----------------------------------------------------------------------------


void Graph::checkIfClicked(sf::Vector2f mousePos, float deltaTime)
{
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; j++) {
            if (m_tiles[i][j].clicked(mousePos))
            {
                //maybe should return true and then bfs algo
                std::cout << "moving";
                frog.movePos(m_tiles[i][j].getLocation(),deltaTime);
            }
        }
        
    }
}
// ----------------------------------------------------------------------------

// this function run bfs algoritem and return the next tile frog needs to move to.
Tile* Graph::BFS(Tile * s) // todo
{    
    Tile* currentTile = s;
    bool isLimit = false;

    // Coloring all the vertices in white
    for (int row = 0; row < m_rows; ++row)
        for (int col = 0; col < m_rows; ++col)
            m_tiles[row][col].setColor(colorId::white);

    // Create a queue for BFS
    std::list<Tile *> queue;

    // Mark the current node as visited and enqueue it
    s->setColor(colorId::gray);
    queue.push_back(s);

    while (!queue.empty() && !isLimit) 
    {
        // Dequeue a vertex from queue and print it
        currentTile = queue.front();
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it            
        std::list<Tile*>::iterator it;
        for (it = currentTile->getBegin(); it != currentTile->getEnd(); ++it) 
        {
            // check if is limit -> stop
            if ((*it)-> isLimit())
                isLimit = true;
            
            // else check if color is white -> update tile color & insert to q
            if ((*it)->getColor() == colorId::white)
            {
                (*it)->setColor(colorId::gray);
                queue.push_back((*it));
                (*it)->setFoundBy(currentTile);
            }
        }                

        currentTile->setColor(colorId::black); // todo - try to add using colorId
    }
   
    // find the next tile    
    while (currentTile->getFoundBy() != s) // todo - maybe we need from it and not from current
        currentTile = currentTile->getFoundBy();

    return currentTile;
}
// ----------------------------------------------------------------------------


void Graph::updateNeighborsList() // todo - clean the function
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
                m_tiles[row][col].addNeighbor(&m_tiles[x][y]);
            }
            if (row > 0 && col + 1 - factor < m_cols)                                   // up right            
            {
                x = row - 1;
                y = col + 1 - factor;
                m_tiles[row][col].addNeighbor(&m_tiles[x][y]);
            }
            
            if (col > 0)                                                                // left
            {
                y = col - 1;
                m_tiles[row][col].addNeighbor(&m_tiles[row][y]);
            }

            if (col + 1 < m_cols)                                                       // right
            {
                y = col + 1;
                m_tiles[row][col].addNeighbor(&m_tiles[row][y]);
            }

            if (row + 1 < m_rows && col - factor > -1)                                  // down left
            {
                x = row + 1;
                y = col - factor;
                m_tiles[row][col].addNeighbor(&m_tiles[x][y]);
            }

            if (row + 1 < m_rows && col + 1 - factor < m_cols)                          // down right            
            {
                x = row + 1;
                y = col + 1 - factor;
                m_tiles[row][col].addNeighbor(&m_tiles[x][y]);
            }
            
        }
    }
}
// ----------------------------------------------------------------------------

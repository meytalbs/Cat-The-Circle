#include "Graph.h"


Graph::Graph(int rows, int cols,int level)
    : m_rows(rows), m_cols(cols)
{
    m_tiles.reserve(m_rows * m_cols); // todo - using operator * on 4 byte value....
    bool isLimit;

   for (int i = 0; i < m_rows ; ++i) {
        vector<Tile> temp;
        for (int j = 0; j < m_cols; j++) {

            if (i == 0 || i == m_rows - 1 || j == 0 || j == m_cols - 1)
                isLimit = true;
            else
                isLimit = false;

            if(j%2==0 ) 
                temp.push_back(Tile(sf::Vector2f(MARGIN_RIGHT-40 + SPACE * i,
                                                              MARGIN_TOP + SPACE * j), 0.4, isLimit,j,i));
            
            else
                temp.push_back(Tile(sf::Vector2f(MARGIN_RIGHT + SPACE * i,
                                                              MARGIN_TOP + SPACE * j), 0.4, isLimit,j,i));

        }
        m_tiles.push_back(std::move(temp));
    }
    
   randomaize(level);
   
   updateNeighborsList();
}
// ----------------------------------------------------------------------------


void Graph::randomaize(int level) // todo
{
    int size;
    vector<std::pair<int, int>> vect;

    switch(level)
    {
        case 1 : size =14;
                break;
        case 2: size = 8;
                break;
        case 3: size =4;
                break;

    }

    vect=assertNum(size,0,10);//will be chossed according to level

    for (int i = 0; i < 11; ++i)//!!!!!
    {
        m_tiles[vect[i].first][vect[i].second].color();
       // todo
    }

    do {
        vect = assertNum(1, 4, 6);//will be chossed according to level
    }
    while(m_tiles[vect[0].first][vect[0].second].getColor()!=colorId::white);
    frog.move(vect[0].first,vect[0].second);
}
// ----------------------------------------------------------------------------


vector<std::pair<int, int>> Graph:: assertNum(int size,int a,int b) // todo
{
    vector<std::pair<int, int>> temp;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(a, b); // define the range

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


bool Graph::checkIfClicked(sf::Vector2f mousePos, float deltaTime)
{
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; j++) {
            if (m_tiles[i][j].clicked(mousePos))
            {
                ++m_counter; // todo: print counter

                //updateNeighborsList();
                m_tiles[i][j].setColor(colorId::black); // todo
                //maybe should return true and then bfs algo
                std::pair<int, int> pos = frog.getTile();
               // cout << pos.first << " " << pos.second<<std::endl;
                if (!(&m_tiles[pos.first][pos.second])->isLimit())
                {
                    Tile* nextTile = BFS(&m_tiles[pos.first][pos.second]);
                    frog.movePos(nextTile->getLocation(),deltaTime);
                }
                else
                {              
                   return true;
                }
            }
        }
        
    }
    return false;
}
// ----------------------------------------------------------------------------

// this function run bfs algoritem and return the next tile frog needs to move to.
Tile* Graph::BFS(Tile * s) 
{    
    Tile* currentTile = s,
           * dest = nullptr;
    bool isLimit = false;   

    // Coloring all the vertices in white
   for (int row = 0; row < m_rows; ++row)
        for (int col = 0; col < m_rows; ++col)
            if (colorId::black != m_tiles[row][col].getColor())
                m_tiles[row][col].setColor(colorId::white);
            
    // Create a queue for BFS   
    std::list<Tile *> queue;

    // Mark the current node as visited and enqueue it
    s->setColor(colorId::gray);
    queue.push_back(s);

    std::list<Tile*>::iterator it;
    while (!queue.empty() && !isLimit) 
    {
        // Dequeue a vertex from queue and print it
        currentTile = queue.front();
        queue.pop_front();
         
        if ((currentTile)->isLimit())
        {
             dest = currentTile;
             isLimit = true;
        }

        for (it = currentTile->getBegin(); it != currentTile->getEnd(); ++it)
        {
            if ((*it)->getColor() == colorId::white)
            {
                std::cout << "col: " << (*it)->m_col << " row: " << (*it)->m_row << "\n";
                (*it)->setFoundBy(currentTile);
                (*it)->setColor(colorId::gray);
                queue.push_back(*it);
            }
        }  
    }

    // find the next tile    
    while (dest->getFoundBy() != s) 
    {
        dest = dest->getFoundBy();
    }


    return dest;
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
            if (m_tiles[row][col].getColor() == colorId::white)
            {
                if (row > 0 && col - factor != -1)                                           // up left
                {
                    x = row - 1; // [row-1][col-1] // ! even
                    y = col - factor;
                    m_tiles[row][col].addNeighbor(&m_tiles[x][y]);
                }
                if (row > 0 && col + (1 - factor) < m_cols)                                   // up right            
                {
                    x = row - 1;
                    y = col + (1 - factor);
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
                    x = row+1 ;
                    y = col - factor;
                    m_tiles[row][col].addNeighbor(&m_tiles[x][y]);
                }

                if (row + 1 < m_rows && col + 1 - factor < m_cols)                          // down right            
                {
                    x = row + 1;
                    y = col + (1 - factor);
                    m_tiles[row][col].addNeighbor(&m_tiles[x][y]);
                }
            }
        }
    }
}
// ----------------------------------------------------------------------------

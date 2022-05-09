#include "Graph.h"


Graph::Graph(int rows, int cols,int level)
    : m_rows(rows), m_cols(cols)
{
    m_tiles.reserve(m_rows * m_cols);
    bool isLimit;

   for (int i = 0; i < m_rows ; ++i) {
        vector<Tile> temp;
        for (int j = 0; j < m_cols; j++) {

            if (i == 0 || i == m_rows - 1 || j == 0 || j == m_cols - 1)
                isLimit = true;
            else
                isLimit = false;

            if(i%2==0 )
                temp.push_back(Tile(sf::Vector2f(MARGIN_RIGHT + SPACE * j-40,
                                                              MARGIN_TOP+ SPACE * i ), 0.4, isLimit,i,j));
            else
                temp.push_back(Tile(sf::Vector2f(MARGIN_RIGHT + SPACE * j,
                                                              MARGIN_TOP + SPACE * i), 0.4, isLimit,i,j));
        }
        m_tiles.push_back(std::move(temp));
    }
    
   randomaize(level);
   updateNeighborsList();
}
// ----------------------------------------------------------------------------


void Graph::randomaize(int level) // todo
{
    int size,a,b;
    vector<std::pair<int, int>> vect;

    switch(level)
    {
        case 1 : size =14;a =3;b=8; // todo
                break;
        case 2: size = 8;a =3;b=8;
                break;
        case 3: size =4 ;a=2;b=9;
                break;
    }

    vect=assertNum(size,a,b);//will be chossed according to level

    for (int i = 0; i < size; ++i)//!!!!!
    {
        m_tiles[vect[i].first][vect[i].second].setColor(colorId::black);
        // todo
    }

    do {
        vect = assertNum(1, 4, 6);//will be chossed according to level

    }
    while(m_tiles[vect[0].first][vect[0].second].getColor()!=colorId::white);

    if(m_tiles[vect[0].first][vect[0].second].getColor()==colorId::white) {
        frog.move(vect[0].first, vect[0].second);
        

    }

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


void Graph::drawTiles(sf::RenderWindow& window) 
{
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; j++) {
            m_tiles[i][j].updateAndDraw(window);
        }
    }

    frog.updateAndDraw(window);
}
// ----------------------------------------------------------------------------


bool Graph::checkIfClicked(sf::Vector2f mousePos)
{
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; j++) {

            if (m_tiles[i][j].clicked(mousePos) &&
            !(i == frog.getTile().first && j==frog.getTile().second))
            {
                ++m_counter;

                m_tiles[i][j].setColor(colorId::black); 
                std::pair<Tile *, std::pair<int,int>> temp (&m_tiles[i][j],frog.getTile());
                m_history.push_back(temp);

                std::pair<int, int> pos = frog.getTile();
                if (!(&m_tiles[pos.first][pos.second])->isLimit())
                {
                    Tile* nextTile = BFS(&m_tiles[pos.first][pos.second]);
                    if (nextTile) frog.movePos(nextTile->getLocation());
                }
                else
                   return true;
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

    //updateNeighborsList();
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
                (*it)->setFoundBy(currentTile);
                (*it)->setColor(colorId::gray);
                queue.push_back(*it);
            }
        }
    }

    if (!dest || !dest->getFoundBy())
    {
        dest = getFreeTile(s);
        return dest;
    }

    // find the next tile    
    while (dest->getFoundBy() != s)
    {
        dest = dest->getFoundBy();
    }

    return dest;
}
// ----------------------------------------------------------------------------


Tile* Graph::getFreeTile(Tile* s)
{
    std::list<Tile*>::iterator it;
    auto currentTile = s;

    for (it = currentTile->getBegin(); it != currentTile->getEnd(); ++it)
    {
        if ((*it)->getColor() != colorId::black)
        {
            return *it;
        }
    }

    m_gameOver = true;
    return nullptr;
}
// ----------------------------------------------------------------------------


void Graph::undo()
{
    if(!m_history.empty()) {
        m_history.back().first->setColor(colorId::white);
        frog.move(m_history.back().second.first, m_history.back().second.second);
        m_history.pop_back();
        --m_counter;
    }
}

// ----------------------------------------------------------------------------


void Graph::updateNeighborsList() // todo - clean the function
{
    int factor = 0, x, y;


    for (int row = 0; row < m_rows; ++row)
    {
        row % 2 == 0 ? factor =0: factor = 1;


        for (int col = 0; col < m_cols; ++col)
        {
            m_tiles[row][col].checkNeighbors();

            if (m_tiles[row][col].getColor() == colorId::white)
            {
                if (row > 0 && !(col == 0 && factor == 0))                               // up left
                {
                    x = row - 1;
                    y = col - (1-factor);                    
                    m_tiles[row][col].addNeighbor(&m_tiles[x][y]);
                }
                if (row > 0 && !(col == (m_cols - 1) && factor == 1))                    // up right
                {
                    x = row - 1;
                    y = col + factor;
                    m_tiles[row][col].addNeighbor(&m_tiles[x][y]);
                }

                if (col > 0)                                                             // left
                {
                    y = col - 1;
                    m_tiles[row][col].addNeighbor(&m_tiles[row][y]);
                }

                if (col+1 < m_cols)                                                      // right
                {
                    y = col + 1;
                    m_tiles[row][col].addNeighbor(&m_tiles[row][y]);
                }

                if (row + 1 < m_rows && !(col == 0 && factor == 0))                      // down left
                {
                    x = row+1 ;
                    y = col - (1 - factor);
                    m_tiles[row][col].addNeighbor(&m_tiles[x][y]);
                }

                if (row + 1 < m_rows && !(col == (m_cols -1 ) && factor == 1))           // down right
                {
                    x = row + 1;
                    y = col +  factor;
                    m_tiles[row][col].addNeighbor(&m_tiles[x][y]);
                }
            }
        }
    }
}
// ----------------------------------------------------------------------------

#include "Graph.h"


Graph::Graph(int rows, int cols,int level)
    : m_rows(rows), m_cols(cols)
{
    m_tiles.reserve(m_rows * m_cols); //

   for (int i = 0; i < m_rows ; ++i) {
        vector<Tile> temp;
        for (int j = 0; j < m_cols; j++) {

            if(j%2==0 ) {
                temp.push_back(Tile(sf::Vector2f(MARGIN_RIGHT-40 + SPACE * i,
                                                              MARGIN_TOP + SPACE * j), 0.4));
            } 
            else
                temp.push_back(Tile(sf::Vector2f(MARGIN_RIGHT + SPACE * i,
                                                              MARGIN_TOP + SPACE * j), 0.4));
        }
        m_tiles.push_back(std::move(temp));
    }
    
   randomaize(level);
   
     
   // todo
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


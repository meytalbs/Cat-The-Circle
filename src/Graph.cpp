#include "Graph.h"


Graph::Graph(int rows, int cols)
    : m_rows(rows), m_cols(cols)
{
    m_tiles.reserve(m_rows * m_cols); //

   for (int i = 0; i < m_rows ; ++i) {
        vector<Tile> temp;
        for (int j = 0; j < m_cols; j++) {

            if(j%2==0) {
                temp.push_back(Tile(sf::Vector2f(MARGIN_RIGHT-40 + SPACE * i,
                                                              MARGIN_TOP + SPACE * j), 0.4));
            } 
            else
                temp.push_back(Tile(sf::Vector2f(MARGIN_RIGHT + SPACE * i,
                                                              MARGIN_TOP + SPACE * j), 0.4));
        }
        m_tiles.push_back(std::move(temp));
    }

   // todo
   updateNeighborsList();
}
// ----------------------------------------------------------------------------


void Graph::drawTiles(sf::RenderWindow& window) {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; j++) {
            m_tiles[i][j].updateAndDraw(window);
        }
    }
}
// ----------------------------------------------------------------------------


void Graph::checkIfClicked(sf::Vector2f mousePos)
{
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; j++) {
            m_tiles[i][j].clicked(mousePos);
        }
    }
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


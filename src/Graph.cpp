#include "Graph.h"

/*
Graph::Graph()
{
    std::cout<<"AR";

    /*
    auto item = m_graph.find(5)->second;

    for (auto i = item.begin(); i != item.end(); ++i)
    {
        std::cout << "su" << i->key;
    }
    */

}
// ----------------------------------------------------------------------------
*/

Graph::Graph(int rows, int cols)
    : m_rows(rows), m_cols(cols)
{

   for (int i = 0; i < m_rows ; ++i) {
        vector<unique_ptr<Tile>> temp;
        for (int j = 0; j < m_cols; j++) {
            if(j%2==0) {
                temp.push_back(make_unique<Tile>(sf::Vector2f(MARGIN_RIGHT-40 + SPACE * i,
                                                              MARGIN_TOP + SPACE * j), 0.4));
            } else
                temp.push_back(make_unique<Tile>(sf::Vector2f(MARGIN_RIGHT + SPACE * i,
                                                              MARGIN_TOP + SPACE * j), 0.4));
        }
        m_tiles.push_back(std::move(temp));
    }
}
// ----------------------------------------------------------------------------
void Graph::drawTiles(sf::RenderWindow& window) {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; j++) {
            m_tiles[i][j]->updateAndDraw(window);
        }
    }
}
//----------------------
void Graph::checkIfClicked(sf::Vector2f mousePos)
{
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; j++) {
            m_tiles[i][j]->clicked(mousePos);
        }
    }
}

// todo - when it for left and when it for right
/*
std::list<Node> Graph::getList(int key) // todo - very bad!!!
{
    std::list<Node> list;
    Node node;

    // for even rows
    if ((key / m_rows) % 2 == 0)
    {
        if (key != 0 && key / m_rows != 0)
        {
            if (key % m_cols != 0)
            {
                node.key = (key - (m_cols + 1));
                list.push_back(node);
            }
            node.key = key - m_cols;
            list.push_back(node);
        }
        if (key % m_cols != 0)
        {
            node.key = key - 1;
            list.push_back(node);
        }
        if ((key + 1) % m_cols != 0)
        {
            node.key = key + 1;
            list.push_back(node);
        }

        if (key % m_cols != 0)
        {
            node.key = key + (m_cols - 1);
            list.push_back(node);

        }
        node.key = key + m_cols;    
        list.push_back(node);
    }
    // for !even rows
    else 
    {
        node.key = key - m_cols;
        list.push_back(node);

        if ((key + 1) % m_cols != 0)
        {
            node.key = key - (m_cols - 1);
            list.push_back(node);
        }

        if (key % m_cols != 0)
        {
            node.key = (key - 1);
            list.push_back(node);
        }
        if ((key + 1) % m_cols != 0)
        {
            node.key = (key + 1);
            list.push_back(node);
        }

        if (key / m_rows != (m_rows - 1))
        {
            node.key = (key + m_cols);
            list.push_back(node);

            if ((key + 1) % m_cols != 0)
            {
                node.key = (key + (m_cols + 1));
                list.push_back(node);
            }
        }
    }


}
        */

*/
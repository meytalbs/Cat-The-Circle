#include "Graph.h"


Graph::Graph()
{
    for (int i = 0; i < m_rows * m_cols; ++i)
        m_graph.insert({ i, getList(i) });

    /*
    auto item = m_graph.find(5)->second;

    for (auto i = item.begin(); i != item.end(); ++i)
    {
        std::cout << "su" << i->key;
    }
    */

}
// ----------------------------------------------------------------------------


Graph::Graph(int rows, int cols)
    : m_rows(rows), m_cols(cols)
{
    for (int i = 0; i < m_rows * m_cols; ++i)
        m_graph.insert({ i, getList(i) });
}
// ----------------------------------------------------------------------------



// todo - when it for left and when it for right
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


    return list;
}
// ----------------------------------------------------------------------------


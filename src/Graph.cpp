#include "Graph.h"


Graph::Graph()
{
    for (int i = 0; i < m_rows * m_cols; ++i)
        m_graph.insert({ i, getList(i) }); 
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
std::list<int> Graph::getList(int key) // todo - very bad!!!
{
    std::list<int> list;

    // for even rows
    if ((key / m_rows) % 2 == 0)
    {
        if (key != 0 && key / m_rows != 0)
        {
            if (key%m_cols != 0)
                list.push_back(key - (m_cols + 1));
        
            list.push_back(key - m_cols);
        }
        if (key%m_cols != 0)
            list.push_back(key - 1);
        if ((key+1)%m_cols != 0)
            list.push_back(key + 1);

        if (key%m_cols != 0)
            list.push_back(key + (m_cols - 1));
        list.push_back(key + m_cols);    
    }
    // for !even rows
    else 
    {
        list.push_back(key - m_cols);
        if ((key+1)%m_cols != 0)
            list.push_back(key - (m_cols-1));

        if (key % m_cols != 0)
            list.push_back(key - 1);
        if ((key + 1) % m_cols != 0)
            list.push_back(key + 1);

        if (key / m_rows != (m_rows - 1))
        {
            list.push_back(key + m_cols);
            if ((key + 1) % m_cols != 0)
                list.push_back(key + (m_cols + 1));
        }
    }

    return list;
}
// ----------------------------------------------------------------------------


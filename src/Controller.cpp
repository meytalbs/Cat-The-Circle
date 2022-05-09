#include "Controller.h"

Controller::Controller() 
{
    texture = (Resources::instance().getTexture(gameObjectId::boat));
    text.setFont(Resources::instance().getFont());
    text.setPosition(1325,MARGIN_TOP-20);
   // m_graph =Graph(11,11,1);
}
// ----------------------------------------------------------------------------


void Controller::run() 
{
    sf::Clock clock;
    sf::Sprite boat;
 
    boat.setTexture(*texture);
    boat.setPosition(sf::Vector2f(50.f, 50.f)); // absolute position
    //need to create singlton for all of the assets

	while (m_window.isOpen())
	{
        float delta = clock.restart().asSeconds() * 60;///temp;
        int x, y;
        sf::Mouse mouse;
        sf::Event event;
        while (m_window.getWindow().pollEvent(event))//check if good oop 
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {   
                // boat.setColor(sf::Color(150, 200, 255));
              m_inLimit= m_graph.checkIfClicked(m_window.getWindow().mapPixelToCoords(sf::Mouse::
                    getPosition(m_window.getWindow())),delta);

                if (m_menu.clicked(m_window.getWindow().mapPixelToCoords(sf::Mouse::
                    getPosition(m_window.getWindow()))))
                {

                    m_graph = Graph();  //!!check if it dosent make bad things with memory!!
                }
            }
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_window.closeWindow();//check if Window class is even needed
        }

        // draw everything here...
        // window.draw(...);
        m_graph.drawTiles(m_window.getWindow());
        m_window.getWindow().draw(boat);
        m_menu.hover(m_window.getWindow().mapPixelToCoords(sf::Mouse::
            getPosition(m_window.getWindow())));
        m_menu.updateAndDraw(m_window.getWindow());
        if(m_inLimit)
        {
            m_graph = Graph();
            m_inLimit=false;

        }
        text.setString(std::to_string(m_graph.getCounter()));
        m_window.getWindow().draw(text);
        // end the current frame
        m_window.display();
	}
}
// ----------------------------------------------------------------------------


bool Controller :: isRuning()
{
    return m_isRuning;
}
// ----------------------------------------------------------------------------

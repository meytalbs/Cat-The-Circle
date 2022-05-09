#include "Controller.h"

Controller::Controller() 
{
    texture = (Resources::instance().getTexture(gameObjectId::boat));
    text.setFont(Resources::instance().getFont());
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
        text.setPosition(1325,MARGIN_TOP-20);

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
                    getPosition(m_window.getWindow())),menu::restart))
                {

                    m_graph = Graph(11,11,1);  //!!check if it dosent make bad things with memory!!
                }
                if (m_menu.clicked(m_window.getWindow().mapPixelToCoords(sf::Mouse::
                                                                         getPosition(m_window.getWindow())),menu::close))
                {

                   m_window.getWindow().close();  //!!check if it dosent make bad things with memory!!
                }
            }
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_window.closeWindow();//check if Window class is even needed
        }

        // draw everything here...
        // window.draw(...);

        if(m_graph.isGameOver())//win
        {
            showScreen(event, true,
                       "Winner  Winner  Chicken  Dinner  in  " + std::to_string(m_graph.getCounter()) + " moves",menu::nextLevel);

        } else if(m_inLimit)//lose
            showScreen(event, false,
                       "loser  Winner  Chicken  Dinner  in  " + std::to_string(m_graph.getCounter()) + " moves",menu::nextLevel);
        else
        {
            m_graph.drawTiles(m_window.getWindow());
            m_window.getWindow().draw(boat);
            m_menu.hover(m_window.getWindow().mapPixelToCoords(sf::Mouse::
                                                               getPosition(m_window.getWindow())));
            m_menu.updateAndDraw(m_window.getWindow());

            text.setString(std::to_string(m_graph.getCounter()));
            m_window.getWindow().draw(text);
        }

        // end the current frame
        m_window.display();
	}
}

void Controller::showScreen(const sf::Event &event, bool isGameOver ,string t,menu show) {
    text.setPosition(300, 450);
    text.setString(t);

    m_window.getWindow().draw(text);//!!check if it dosent make bad things with memory!!
    m_menu.drawSpacificButton(m_window.getWindow(), show);
    if (event.type == sf::Event::MouseButtonPressed) {
        if (m_menu.clicked(m_window.getWindow().mapPixelToCoords(sf::Mouse::
                                                                 getPosition(m_window.getWindow())), show))
        {

            if(isGameOver) {
                m_level++;
                if (m_level > 3)
                    m_level = 1;
            } else
                m_inLimit =false;
            cout<< m_level;
            m_graph = Graph(11, 11, m_level);  //!!check if it dosent make bad things with memory!!
        }
    }

}
// ----------------------------------------------------------------------------



// ----------------------------------------------------------------------------
/*  text.setPosition(700,500);
                text.setString("winner  winner  chicken  dinner in " +std::to_string(m_graph.getCounter()) + " moves");
                m_window.getWindow().draw(text);//!!check if it dosent make bad things with memory!!
                m_menu.drawSpacificButton(m_window.getWindow(),2);
            if (event.type == sf::Event::MouseButtonPressed) {
                if (m_menu.clicked(m_window.getWindow().mapPixelToCoords(sf::Mouse::
                                                                         getPosition(m_window.getWindow())), 2)) {
                    level++;
                    if(level>3)
                        level=1;
                    m_graph = Graph(11, 11, level);  //!!check if it dosent make bad things with memory!!
                }
            }*/
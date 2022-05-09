#include "Controller.h"

Controller::Controller() 
{
    texture = (Resources::instance().getTexture(gameObjectId::boat));
    text.setFont(Resources::instance().getFont());

}
// ----------------------------------------------------------------------------


void Controller::run() 
{
    sf::Sprite boat;
 
    boat.setTexture(*texture);
    boat.setPosition(sf::Vector2f(50.f, 50.f)); // absolute position
    //need to create singlton for all of the assets

	while (m_window.isOpen()) {
        text.setPosition(1325, MARGIN_TOP - 20);

        int x, y;
        sf::Mouse mouse;
        sf::Event event;
        while (m_window.getWindow().pollEvent(event))//check if good oop 
        {


            if (m_graph.isGameOver())//win
            {
                showScreen(event, true,
                           "Winner  Winner  Chicken  Dinner  in  " + std::to_string(m_graph.getCounter()) + " moves",
                           menu::nextLevel);

            } else if (m_inLimit)//lose
            {
                showScreen(event, false,
                           "loser  Loser   you are a snoozer in   " + std::to_string(m_graph.getCounter()) + " moves",
                           menu::restartScreen);
            } else {//working state

                handleRegularClick(event);
                drawScreen(boat);

            }

            // end the current frame
            m_window.display();
        }
    }
}

void Controller::drawScreen(const sf::Sprite &boat) {
    m_graph.drawTiles(m_window.getWindow());
    m_window.getWindow().draw(boat);
    m_menu.hover(m_window.getWindow().mapPixelToCoords(sf::Mouse::
                                                       getPosition(m_window.getWindow())));
    m_menu.updateAndDraw(m_window.getWindow());

    text.setString(std::to_string(m_graph.getCounter()));
    m_window.getWindow().draw(text);
}

void Controller::handleRegularClick( const sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        // boat.setColor(sf::Color(150, 200, 255));
        m_inLimit = m_graph.checkIfClicked(m_window.getWindow().mapPixelToCoords(sf::Mouse::
                                                                                 getPosition(
                m_window.getWindow())));

        if (m_menu.clicked(m_window.getWindow().mapPixelToCoords(sf::Mouse::
                                                                 getPosition(m_window.getWindow())),
                           menu::restart)) {

            m_graph = Graph(11, 11, m_level);  //!!check if it dosent make bad things with memory!!
        }
        if (m_menu.clicked(m_window.getWindow().mapPixelToCoords(sf::Mouse::
                                                                 getPosition(m_window.getWindow())),
                           menu::close)) {

            m_window.getWindow().close();  //!!check if it dosent make bad things with memory!!
        }
        if (m_menu.clicked(m_window.getWindow().mapPixelToCoords(sf::Mouse::
                                                                 getPosition(m_window.getWindow())),
                           menu::undo))
            m_graph.undo();
    }
    // "close requested" event: we close the window
    if (event.type == sf::Event::Closed)
        m_window.closeWindow();//check if Window class is even needed

}

void Controller::showScreen(const sf::Event &event, bool isGameOver ,string t,menu show) {
    text.setPosition(400, 450);
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




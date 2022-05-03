

#include "Controller.h"
Controller::Controller() {
    texture= (Resources::instance().getTexture(gameObjectId::boat));
    frogtex= (Resources::instance().getTexture(gameObjectId::frog));
}

void Controller::run() 
{

    sf::Sprite boat;
    sf::Sprite frogSprite;//!!temppppp
    frogSprite.setTexture(*frogtex);
    frogSprite.setOrigin(50,50);
    frogSprite.setScale(0.9f,0.9f);
    frogSprite.setPosition(sf::Vector2f(MARGIN_RIGHT-30+SPACE*2,90+SPACE*2));
    boat.setTexture(*texture);

    boat.setPosition(sf::Vector2f(50.f, 50.f)); // absolute position
    //need to create singlton for all of the assets

	while (m_window.isOpen())
	{
        sf::Mouse mouse;
        sf::Event event;
        while (m_window.getWindow().pollEvent(event))//check if good oop 
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
               // boat.setColor(sf::Color(150, 200, 255));
                m_graph.checkIfClicked(m_window.getWindow().mapPixelToCoords(sf::Mouse::
                getPosition(m_window.getWindow())));
            }
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_window.closeWindow();//check if Window class is even needed

        }

        // draw everything here...
        // window.draw(...);
        m_graph.drawTiles(m_window.getWindow());
        m_window.getWindow().draw(boat);
        m_window.getWindow().draw(frogSprite);
        m_menu.updateAndDraw(m_window.getWindow());


        // end the current frame
        m_window.display();
	}
}
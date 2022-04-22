#include "Controller.h"

Controller::Controller() {
    if (!texture.loadFromFile("Boat.png"))
    {
        // should throw error
        std::cout << "error";
    }
}

void Controller::run() 
{
    sf::Sprite boat;
    boat.setTexture(texture);
    boat.setPosition(sf::Vector2f(50.f, 50.f)); // absolute position
    //need to create singlton for all of the assets
    
	while (m_window.isOpen())
	{
        sf::Event event;
        while (m_window.getWindow().pollEvent(event))//check if good oop 
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                boat.setColor(sf::Color(150, 200, 255));

            }
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_window.closeWindow();//check if Window class is even needed

        }

        // draw everything here...
        // window.draw(...);
        m_window.getWindow().draw(boat);

        // end the current frame
        m_window.display();
	}
}
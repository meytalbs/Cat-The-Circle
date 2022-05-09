#pragma once

#include <vector>
#include <string>

#include "SFML/Graphics.hpp"

using std::string;

class Window
{
public:
	Window(const sf::Vector2u windowSize = sf::Vector2u(1400, 1000),
		   const string title = "Circle The Frog ");
	bool isOpen();
	void closeWindow() { m_window.close(); };
	void display() { 
		m_window.display();
		m_window.clear(sf::Color(103, 230, 210));
	};
	sf::RenderWindow& getWindow() { return m_window; };

private:
	sf::RenderWindow m_window;
};
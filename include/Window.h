#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>


using std::string;

class Window
{
public:
	Window(const sf::Vector2u windowSize = sf::Vector2u(1400, 1000),
		const string title = "Frog Jump");
	bool isOpen();
	sf::RenderWindow& getWindow() { return m_window; };//i dont think its good oop maybe need to change
	void closeWindow() { m_window.close(); };
	void display() {
		m_window.display();
		m_window.clear(sf::Color(103, 230, 210));
	};

private:
	sf::RenderWindow m_window;
};
#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Window.h"
class Controller
{
public:
	Controller();
	void run();
private:
	Window m_window;
	sf::Texture texture;//will move it to class like from project just or testing


};
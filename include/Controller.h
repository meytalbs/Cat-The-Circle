#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Window.h"
#include "Tile.h"
#include <vector>
#include "Graph.h"
#include "Resources.h"
#include "Macros.h"
#include "Menu.h"
class Controller
{
public:
	Controller();
	void run();
private:
    Menu m_menu;
    Graph m_graph;
	Window m_window;
    sf::Texture frogtex;
	sf::Texture texture;//will move it to class like from project just or testing

};
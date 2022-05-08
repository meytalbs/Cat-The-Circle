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
#include "Frog.h"
class Controller
{
public:
	Controller();
	void run();
	bool isRuning();
private:
    bool m_inLimit=false;
    Menu m_menu;
    Graph m_graph;
	Window m_window;
	sf::Texture* texture;
    sf::Text text;
	bool m_isRuning = true;;
};
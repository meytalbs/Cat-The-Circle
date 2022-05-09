#pragma once

#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "Window.h"
#include "Tile.h"
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

private:
    Menu m_menu;
    Graph m_graph;
	Window m_window;
    int m_level =1;
	sf::Texture* texture;
    sf::Text text;
	bool m_isRuning = true;
    bool m_inLimit = false;

    void showScreen(const sf::Event &event, bool isGameOver,string t,menu show);
};

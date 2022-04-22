#include "Window.h"

Window::Window(const sf::Vector2u windowSize, const string title)
	: m_window(sf::VideoMode(windowSize.x, windowSize.y), title) {}


bool Window::isOpen() {
	return m_window.isOpen();
}
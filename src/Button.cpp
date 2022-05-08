#include"Button.h"

Button::Button(float x, float y, float width, float height,
    sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->m_bState = BTN_IDLE;
    this->m_shape.setPosition(x, y);
    this->m_shape.setSize(sf::Vector2f(width, height));
    this->m_shape.setOrigin(sf::Vector2f(width / 2.f, height / 2.f));
  
    this->m_idleColor = idleColor;
    this->m_hoverColor = hoverColor;
    this->m_activeColor = activeColor;

    this->m_shape.setFillColor(this->m_idleColor);
    m_pressed = false;
}

void Button::update(sf::Vector2f mousePos)
{
    //idle

    this->m_bState = BTN_IDLE;
    this->m_shape.setFillColor(this->m_idleColor);

    //hover
    if (m_shape.getGlobalBounds().contains(mousePos)) {
        this->m_bState = BTN_HOVER;

        //pressed
        switch (this->m_bState) {
        case BTN_IDLE:
            this->m_shape.setFillColor(this->m_idleColor);
            break;
        case BTN_HOVER:
            this->m_shape.setFillColor(this->m_hoverColor);
            break;
        case BTN_PRESSED:
            this->m_shape.setFillColor(this->m_activeColor);
            m_pressed = true;
        default:
            break;
        }
    }
}

void Button::quit()
{
    m_pressed = false;
}

bool Button::isPressed(sf::Vector2f mousePos)
{
    if (m_shape.getGlobalBounds().contains(mousePos)) {
        this->m_bState = BTN_PRESSED;
        return true;
    }

    return false;
}

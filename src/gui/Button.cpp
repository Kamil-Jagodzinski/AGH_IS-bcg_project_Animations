#include "../../include/gui/Button.h"

Button::Button()
:Object(), m_state(Button::state::IDLE)
{
	m_shape.setOutlineThickness(-5.f);
	m_shape.setOutlineColor(sf::Color::Black);
}

Button::Button(const sf::Vector2f &pos, const sf::Vector2f &size)
:Object(pos, size), m_state(Button::state::IDLE)
{
	m_shape.setOutlineThickness(-5.f);
}

//getters
const unsigned short Button::getState() const
{
    return m_state;
}

//setters
void Button::setState(const unsigned short new_state)
{
    m_state = new_state;
}

//check and update methods
bool Button::isPressed() const
{
    return (m_state == Button::state::ACTIVE);
}

void Button::lockButton()
{
    m_state = Button::state::LOCKED;
}

void Button::unlockButton()
{
    m_state = Button::state::IDLE;
}

void Button::update(sf::Vector2i mousePos, sf::Event &event)
{
    if(m_state != Button::state::LOCKED)
    {
        if(m_shape.getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            m_state = Button::state::HOVER;

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                m_state = Button::state::ACTIVE;
            }
        }
        else
        {
            m_state = Button::state::IDLE;
        }
        
        if(m_state == Button::state::IDLE)
        {
            m_shape.setFillColor( sf::Color(200,200,200) );
        }
        else if(m_state == Button::state::HOVER)
        {
            m_shape.setFillColor( sf::Color(100,100,100) );
        }
        else
        {
            m_shape.setFillColor( sf::Color(100,200,100) );
        }
    }
}

void Button::render(sf::RenderTarget *target)
{
    target->draw(m_shape);
}

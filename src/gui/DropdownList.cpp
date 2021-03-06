#include "../../include/gui/DropdownList.h"

DropdownList::DropdownList()
:
TextButton(),
m_background(sf::RectangleShape(sf::Vector2f(m_shape.getSize().x, m_shape.getSize().y / 2))),
m_dropStatus(DropdownList::DropStatus::HIDDEN),
m_currentChoice(0u)
{
	m_background.setPosition(
		sf::Vector2f(
			m_shape.getPosition().x, 
			m_shape.getPosition().y + m_shape.getSize().y
			)//right below the main button
	);
	m_background.setFillColor(sf::Color(210, 210, 210));

	m_isChanged = false;
}

DropdownList::DropdownList(
	const sf::Vector2f &pos, 
	const sf::Vector2f &size,
	std::shared_ptr<sf::Font> font,
	const sf::String &label
	)
:
TextButton(pos, size, font, label),
m_background(sf::RectangleShape(sf::Vector2f(size.x, size.y / 2.f))),
m_dropStatus(DropdownList::DropStatus::HIDDEN),
m_currentChoice(0u)
{
	m_background.setPosition(
		sf::Vector2f(
			m_shape.getPosition().x, 
			m_shape.getPosition().y + m_shape.getSize().y
		)//right below the main button
	);
	m_background.setFillColor(sf::Color(210, 210, 210));

	m_isChanged = false;
}

void DropdownList::addChoice(std::unique_ptr<TextButton> new_choice)
{
	sf::Vector2f relative_pos = m_background.getPosition() + sf::Vector2f(0.f, 3.f);
	if(!m_choices.empty())
	{
		relative_pos = m_choices.back()->getPosition();//set to position of last element
		relative_pos += sf::Vector2f(0.f, m_choices.back()->getSize().y);//shift y with height of last element
		relative_pos += sf::Vector2f(0.f, 1.f);//shift y with 2.f space between choices
	}

	new_choice->setPosition(relative_pos);
	new_choice->setSize(sf::Vector2f(m_shape.getSize().x, m_shape.getSize().y / 1.4f));
	new_choice->getShape().setOutlineThickness(0.f);
	m_choices.push_back(std::move(new_choice));

	//new element is appended, now background has to be adjusted in size
	m_background.setSize(
		sf::Vector2f(
			m_shape.getSize().x, 
			m_choices.back()->getPosition().y - m_background.getPosition().y
		)
	);
}

void DropdownList::addChoice(const sf::String &label)
{
	this->addChoice(std::make_unique<TextButton>(sf::Vector2f(0.f, 0.f), m_shape.getSize(), m_font, label));
}

void DropdownList::operator+=(std::unique_ptr<TextButton> new_choice)
{
	this->addChoice(std::move(new_choice));
}

void DropdownList::changeRead()
{
	m_isChanged = false;
}

const bool DropdownList::isChanged() const
{
	return m_isChanged;
}

const sf::RectangleShape &DropdownList::getBackground() const
{
	return m_background;
}

const unsigned short &DropdownList::getDropStatus() const
{
	return m_dropStatus;
}

const unsigned short &DropdownList::getCurrentChoice() const
{
	return m_currentChoice;
}

bool DropdownList::isDropped() const
{
	return (m_dropStatus == DropdownList::DropStatus::DROPPED);
}

void DropdownList::setBackgroundColor(const sf::Color &new_color)
{
	m_background.setFillColor(new_color);
}

void DropdownList::update(sf::Vector2i mousePos, sf::Event &event)
{
	TextButton::update(mousePos, event);
	if(m_dropStatus == DropdownList::DropStatus::DROPPED)
	{
		unsigned short count = 1u;
		for(auto &it : m_choices)
		{
			it->update(mousePos, event);
			if(it->isPressed())
			{
				m_dropStatus = DropdownList::DropStatus::HIDDEN;
				m_currentChoice = count;
				m_isChanged = true;
				this->setLabel(it->getLabel());
			}
			count++;
		}
	}

	if(m_state != Button::state::LOCKED)
	{
		if(m_shape.getGlobalBounds().contains(mousePos.x, mousePos.y)
		&& (event.type == sf::Event::MouseButtonReleased)
		&& (event.mouseButton.button == sf::Mouse::Left))
		{
			if(m_dropStatus == DropdownList::DropStatus::HIDDEN)
	        {
	        	m_dropStatus = DropdownList::DropStatus::DROPPED;
	        }
	        else
	        {
	        	m_dropStatus = DropdownList::DropStatus::HIDDEN;
	        }
		}
	}
}

void DropdownList::render(sf::RenderTarget *target)
{
	TextButton::render(target);
	if(m_dropStatus == DropdownList::DropStatus::DROPPED)
	{
		target->draw(m_background);
		for(auto &it : m_choices)
		{
			it->render(target);
		}
	}
}


#include "../../src/gui/ButtonSet.h"

#include "../../src/constants/Constants.h"

#include <string>
#include <sstream>

ButtonSet::ButtonSet(float x, float y, float w, float h, int thickness, const std::string& buttonText, const sf::Font& f, int fontSize)
{
	init(x, y, w, h, thickness, buttonText, f, fontSize);
}

ButtonSet::ButtonSet()
{
	
}

ButtonSet::~ButtonSet()
{

}

void ButtonSet::init(float x, float y, float w, float h, int thickness, const std::string& buttonText, const sf::Font& f, int fontSize)
{
	this->outlineThickness = thickness;

	this->border.setPosition(sf::Vector2f(x, y));
	this->border.setSize(sf::Vector2f(w, h));

	addButton(buttonText, f, fontSize);
}

void ButtonSet::update(sf::RenderWindow& window)
{
	for (auto& b : buttons)
		b.update(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window))));
}

void ButtonSet::render(sf::RenderWindow& window)
{
	window.draw(border);

	for (auto& b : buttons)
		b.render(&window);
}

void ButtonSet::addButton(const std::string& buttonText, const sf::Font& f, int fontSize)
{
	std::string text;
	Button b;
	std::stringstream bt{ static_cast<std::stringstream>(buttonText) };

	while (std::getline(bt, text, BUTTONSET_DELIMITER))
	{
		b.text.setString(text);
		b.text.setFont(f);
		b.text.setCharacterSize(fontSize);

		buttons.push_back(b);
	}
	reorder();
}

void ButtonSet::setColors(sf::Color border, sf::Color idle, sf::Color hover, sf::Color active)
{
	this->border.setFillColor(border);

	for (auto& b : buttons)
	{
		b.idleColor = idle;
		b.hoverColor = hover;
		b.activeColor = active;
	}
}

void ButtonSet::reorder()
{
	for (int i = 0; i < buttons.size(); ++i)
	{
		buttons[i].shape.setPosition(sf::Vector2f(
			this->border.getPosition().x + outlineThickness,
			(this->border.getPosition().y + outlineThickness) + ((this->border.getGlobalBounds().width - outlineThickness) * i ) / (buttons.size())
		));

		buttons[i].shape.setSize(sf::Vector2f(
			this->border.getSize().x - (outlineThickness * 2),
			(this->border.getSize().y / buttons.size()) - (outlineThickness * 2)
		));

		buttons[i].centerText();
	}
}
#include "../../src/gui/ButtonSet.h"

#include "../../src/constants/Constants.h"

#include <iostream>
#include <string>

ButtonSet::ButtonSet(float x, float y, float w, float h, int thickness, const std::string& buttonIDText, const sf::Font& f, int fontSize)
{
	init(x, y, w, h, thickness, buttonIDText, f, fontSize);
}

ButtonSet::ButtonSet()
{
	
}

ButtonSet::~ButtonSet()
{

}

void ButtonSet::init(float x, float y, float w, float h, int thickness, const std::string& buttonIDText, const sf::Font& f, int fontSize)
{
	this->outlineThickness = thickness;

	this->border.setPosition(sf::Vector2f(x, y));
	this->border.setSize(sf::Vector2f(w, h));

	addButton(buttonIDText, f, fontSize);
}

void ButtonSet::update(sf::RenderWindow& window)
{
	for (auto& it : buttons)
		it.second.update(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window))));
}

void ButtonSet::render(sf::RenderWindow& window)
{
	window.draw(border);

	for (auto& it : buttons)
		it.second.render(&window);
}

// Input formatting: "buttonID-Name/"
void ButtonSet::addButton(const std::string& buttonIDText, const sf::Font& f, int fontSize)
{
	std::string ID;
	std::string text;
	Button b;
	int pos = 0, mid = 0, end = 0;

	while (buttonIDText.find(BUTTONSET_DELIMITER, pos) != std::string::npos)
	{
		end = buttonIDText.find(BUTTONSET_DELIMITER, pos);
		mid = buttonIDText.find(BUTTON_DELIMITER, pos);
		//std::cout << "start, mid, end : " << pos << ", " << mid << ", " << end << std::endl;

		ID = buttonIDText.substr(pos, mid - pos);
		text = buttonIDText.substr(mid+1, end - mid - 1);
		
		//std::cout << "text: " << text << "\nID: " << ID << std::endl;
		pos = end + 1;

		b.text.setString(text);
		b.text.setFont(f);
		b.text.setCharacterSize(fontSize);

		buttons.insert(std::make_pair(ID, b));
	}

	reorder();
}

void ButtonSet::setColors(sf::Color border, sf::Color idle, sf::Color hover, sf::Color active)
{
	this->border.setFillColor(border);

	for (auto& it : buttons)
	{
		it.second.idleColor = idle;
		it.second.hoverColor = hover;
		it.second.activeColor = active;
	}
}

void ButtonSet::reorder()
{
	int i{};

	for (auto& it : buttons)
	{
		it.second.shape.setPosition(sf::Vector2f(
			this->border.getPosition().x + outlineThickness,
			(this->border.getPosition().y + outlineThickness) + ((this->border.getGlobalBounds().width - outlineThickness) * i ) / (buttons.size())
		));

		it.second.shape.setSize(sf::Vector2f(
			this->border.getSize().x - (outlineThickness * 2),
			(this->border.getSize().y / buttons.size()) - (outlineThickness * 2)
		));

		it.second.centerText();

		++i;
	}
}
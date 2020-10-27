#pragma once

#include "../../src/gui/Button.h"

#include <unordered_map>
#include <memory>

class ButtonSet
{
public:
	sf::RectangleShape border;
	std::unordered_map<std::string, Button> buttons;
	int outlineThickness;

public:
	ButtonSet(float x, float y, float w, float h, int thickness, const std::string& buttonIDText, const sf::Font& f, int fontSize);
	ButtonSet();
	~ButtonSet();

	void init(float x, float y, float w, float h, int thickness, const std::string& buttonTDText, const sf::Font& f, int fontSize);

	void setColors(sf::Color border, sf::Color idle, sf::Color hover, sf::Color active);

	void update(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
	void addButton(const std::string& buttonIDText, const sf::Font& f, int fontSize);

private:
	void reorder();
};
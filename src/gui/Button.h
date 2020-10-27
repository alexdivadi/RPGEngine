#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include <string>

enum buttonStates
{
	IDLE,
	HOVER,
	PRESSED
};

class Button
{
private:
	unsigned short state{ 0 };
	bool pressed{ false };
	bool hover{ false };

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	Button(float x, float y, float w, float h, sf::Font* font, std::string text, sf::Color idle, sf::Color hover, sf::Color active);
	Button(const std::string& text);
	Button();
	~Button();
	
	//init for individual button
	void init(float x, float y, float w, float h, sf::Font* font, std::string text, sf::Color idle, sf::Color hover, sf::Color active);
	// init for buttonSet
	void init(std::string text);

	void centerText();
	bool isPressed();

	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);

	friend class ButtonSet;	// lets ButtonSet objects access Button objects' private members
};
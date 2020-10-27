#include "../../src/gui/Button.h"

#include <iostream>

Button::Button(float x, float y, float w, float h, sf::Font* font, std::string text, sf::Color idle, sf::Color hover, sf::Color active)
{
	init(x, y, w, h, font, text, idle, hover, active);
}

Button::Button(const std::string& text)
{
	this->text.setString(text);
}

Button::Button()
{

}

Button::~Button()
{

}

void Button::init(float x, float y, float w, float h, sf::Font* font, std::string text, sf::Color idle, sf::Color hover, sf::Color active)
{
	this->idleColor = idle;
	this->hoverColor = hover;
	this->activeColor = active;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(w, h));
	this->shape.setFillColor(this->idleColor);

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(30);
	centerText();
}

void Button::init(std::string text)
{
	this->text.setString(text);
}

void Button::centerText()
{
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y - 10 + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);
}

bool Button::isPressed()
{
	return pressed;
}

void Button::update(const sf::Vector2f mousePos)
{
	//updates bool for hover and pressed

	
	// idle
	this->state = IDLE;
	hover = false;
	pressed = false;

	//hover
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->state = HOVER;
		hover = true;

		// press
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->state = PRESSED;
			pressed = true;
		}
	}

	switch (this->state)
	{
	case (IDLE):
		this->shape.setFillColor(this->idleColor);
		break;
	case (HOVER):
		this->shape.setFillColor(this->hoverColor);
		break;
	case (PRESSED):
		this->shape.setFillColor(this->activeColor);
		break;
	}

}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
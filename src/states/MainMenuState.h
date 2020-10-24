#pragma once

#include "../../src/states/GameState.h"

#include "../../src/gui/ButtonSet.h"

#include <string>

class MainMenuState : public GameState
{
public:
	sf::Text testText;
	sf::Sprite testSprite;
	sf::Music* testMusic;
	ButtonSet testButtonSet;

	const std::string stateName{ "MainMenu" };

public:
	MainMenuState(GameData* data, sf::RenderWindow* window);
	~MainMenuState();

	void init();
	void terminate();

	void handleInput();
	void update();
	void draw();
};
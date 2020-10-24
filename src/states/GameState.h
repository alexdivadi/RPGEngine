#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameData;

class GameState
{
public:
	GameData* data;
	sf::RenderWindow* window;

public:
	GameState(GameData* data, sf::RenderWindow* window) : data{ data }, window{ window } { }
	virtual ~GameState() = default;

	virtual void init() = 0;
	virtual void terminate() = 0;

	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};
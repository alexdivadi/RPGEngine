#pragma once

#include <SFML/Graphics.hpp>

#include "../../src/data/GameData.h"

class Game
{
private:
	sf::Clock clock;
	sf::Time elapsedTime;

public:
	sf::RenderWindow window;
	GameData gameData;

public:
	Game();
	~Game();

	void gameLoop();
	void printDebugInfo();
};
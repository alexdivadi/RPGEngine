#pragma once

#include "../../src/states/GameState.h"

class BattleState : public GameState
{
	//Battle b;

	const std::string stateName{ "Battle" };

public:
	BattleState(GameData* data, sf::RenderWindow* window);
	~BattleState();

	void init();
	void terminate();

	void handleInput();
	void update();
	void draw();
};
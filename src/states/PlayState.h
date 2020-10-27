#pragma once

#include "../../src/states/GameState.h"
#include "../../src/states/BattleState.h"
#include "../../src/constants/Constants.h"
#include "../../src/data/GameData.h"
#include "../../src/gui/ButtonSet.h"
#include "../../src/entities/Player.h"
#include "../../src/worlds/World.h"

class PlayState : public GameState
{
public:
	sf::Mouse mouse;

	sf::Text testText;
	sf::Sprite testSprite;
	sf::Music* testMusic;
	ButtonSet testButtonSet;

	World world;
	Player player{ world.entities, 0, 0, 50, 50, nullptr };

	const std::string stateName{ "Play" };

public:
	PlayState(GameData* data, sf::RenderWindow* window);
	~PlayState();

	void init();
	void terminate();

	void handleInput();
	void update(/* float dt */);
	void draw();
};
#include "../../src/states/BattleState.h"

#include "../../src/states/MainMenuState.h"
#include "../../src/data/GameData.h"
#include "../../src/constants/Constants.h"

#include <iostream>

BattleState::BattleState(GameData* data, sf::RenderWindow* window) : GameState(data, window)
{
	init();
}

BattleState::~BattleState()
{
	terminate();
}

void BattleState::init()
{

}

void BattleState::terminate()
{
	data->assets.clearFonts(stateName);
	data->assets.clearTextures(stateName);
	data->assets.clearSongs(stateName);
}

void BattleState::handleInput()
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::E)
			{
				std::cout << "battle calling addState type menu" << std::endl;
				data->stateMachine.addState(new MainMenuState(data, window), true);
			}
			break;
		}
	}

	//std::cout << "menu input" << std::endl;
}
void BattleState::update()
{
	//std::cout << "menu update" << std::endl;
}
void BattleState::draw()
{
	//std::cout << "menu draw" << std::endl;
}
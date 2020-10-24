#include "../../src/Game.h"

#include "../../src/constants/Constants.h"
#include "../../src/states/MainMenuState.h"

#include <iostream>

Game::Game()
{
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Window", sf::Style::Default);

	window.setFramerateLimit(60);

	// Puts first gamestate into play
	gameData.stateMachine.addState(new MainMenuState(&gameData, &window), false);

	gameLoop();
}

Game::~Game()
{

}

void Game::gameLoop()
{
	//These were declared in Game.h
	//sf::Clock clock;
	//sf::Time elapsedTime;

	//float deltaTime == elapsedTime.asSeconds()

	while (window.isOpen())
	{
		//From Zelda VVV
		elapsedTime = clock.restart();

		//sf::Time elapsed = clock.restart();
		//float dt = elapsed.asMilliseconds();

		gameData.stateMachine.processStateChange();

		//printDebugInfo();

		if (gameData.stateMachine.currentState() == nullptr)
		{
			std::cerr << "current state was nullptr" << std::endl;
			continue;
		}

		gameData.stateMachine.currentState()->handleInput();
		gameData.stateMachine.currentState()->update();

		window.clear(sf::Color::Black);

		gameData.stateMachine.currentState()->draw();

		window.display();
	}
}

void Game::printDebugInfo()
{
	std::cout << "\nCurrently:\n" << gameData.stateMachine.states.size() << " gameStates\n"
		<< gameData.assets.fonts.size() << " fonts\n"
		<< gameData.assets.textures.size() << " textures\n"
		<< gameData.assets.songs.size() << " songs\n\n";

	for (auto it = gameData.assets.fonts.begin(); it != gameData.assets.fonts.end(); ++it)
		std::cout << "Fonts has: " << it->first << " at " << it->second << std::endl;

	for (auto it = gameData.assets.textures.begin(); it != gameData.assets.textures.end(); ++it)
		std::cout << "Textures has: " << it->first << " at " << it->second << std::endl;

	for (auto it = gameData.assets.songs.begin(); it != gameData.assets.songs.end(); ++it)
		std::cout << "Songs has: " << it->first << " at " << it->second << std::endl;
}
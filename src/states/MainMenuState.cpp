#include "../../src/states/MainMenuState.h"

#include "../../src/states/PlayState.h"
#include "../../src/data/GameData.h"
#include "../../src/constants/Constants.h"

#include <iostream>

MainMenuState::MainMenuState(GameData* data, sf::RenderWindow* window) : GameState(data, window)
{
	init();
}

MainMenuState::~MainMenuState()
{
	terminate();
}

void MainMenuState::init()
{
	sf::Font* testFont{ data->assets.loadFont("default", "") };

	testText.setFont(*testFont);
	testText.setCharacterSize(30);
	testText.setFillColor(sf::Color::White);
	testText.setString("Grok");
	testText.setPosition(100, 100);

	testButtonSet.init(WINDOW_WIDTH / 10.f, (WINDOW_HEIGHT / 2.f), 200, 200, 3, "Start/Options/Quit", *testFont, 30);

	testButtonSet.setColors(sf::Color::White, sf::Color::Black, sf::Color(100, 100, 100), sf::Color(50, 50, 50));

	sf::Texture* testTexture{ data->assets.loadTexture("default", "") };
	
	testSprite.setTexture(*testTexture);
	testSprite.setScale(sf::Vector2f(
		WINDOW_WIDTH / testSprite.getGlobalBounds().width,
		WINDOW_HEIGHT / testSprite.getGlobalBounds().height
	));
	testSprite.setPosition(sf::Vector2f(0.f, 0.f));

	testMusic = data->assets.loadSong("default", "");
	testMusic->setLoop(true);

	testMusic->play();
}

void MainMenuState::terminate()
{
	testMusic->stop();

	data->assets.clearFonts(stateName);
	data->assets.clearTextures(stateName);
	data->assets.clearSongs(stateName);
}

void MainMenuState::handleInput()
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
				std::cout << "menu calling addState type play" << std::endl;
				data->stateMachine.addState(new PlayState(data, window), true);
			}
			break;
		}
	}

	//std::cout << "menu input" << std::endl;
}
void MainMenuState::update()
{
	//std::cout << "menu update" << std::endl;
	testButtonSet.update(*window);
}
void MainMenuState::draw()
{
	window->draw(testSprite);
	window->draw(testText);
	testButtonSet.render(*window);

	//std::cout << "menu draw" << std::endl;
}
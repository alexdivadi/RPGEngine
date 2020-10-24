#include "../../src/states/PlayState.h"

#include "../../src/states/BattleState.h"
#include "../../src/constants/Constants.h"
#include "../../src/data/GameData.h"

#include <iostream>

PlayState::PlayState(GameData* data, sf::RenderWindow* window) : GameState(data, window)
{
	init();
}

PlayState::~PlayState()
{
	terminate();
}

void PlayState::init()
{
	sf::Font* testFont{ data->assets.loadFont("default", "") };

	testText.setFont(*testFont);
	testText.setCharacterSize(30);
	testText.setFillColor(sf::Color::White);
	testText.setString("Wahoo");
	testText.setPosition(100, 100);

	sf::Texture* testTexture;
	data->assets.addTexture("Richard", "o__hP_jj_400x400.jpg", stateName);

	testTexture = data->assets.loadTexture("Richard", stateName);

	testSprite.setTexture(*testTexture);
	testSprite.setScale(sf::Vector2f(
		WINDOW_WIDTH / testSprite.getGlobalBounds().width, 
		WINDOW_HEIGHT / testSprite.getGlobalBounds().height
	));
	testSprite.setPosition(sf::Vector2f(0.f, 0.f));

	data->assets.addSong("HardRain", "Mother 3 - 036 Hard Rain.ogg", stateName);

	testMusic = data->assets.loadSong("HardRain", stateName);
	testMusic->setLoop(true);

	testMusic->play();

}

void PlayState::terminate()
{
	testMusic->stop();

	data->assets.clearFonts(stateName);
	data->assets.clearTextures(stateName);
	data->assets.clearSongs(stateName);
}

void PlayState::handleInput()
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
				std::cout << "play calling addState type menu\n" << std::endl;
				data->stateMachine.addState(new BattleState(data, window), true);
			}
			break;
		}
	}

	//std::cout << "play input" << std::endl;
}

void PlayState::update()
{
	//std::cout << sf::Mouse::getPosition().x << "  " << sf::Mouse::getPosition().y << std::endl;
	//std::cout << "play update" << std::endl;
	testButtonSet.update(*window);
}

void PlayState::draw()
{
	window->draw(testSprite);
	window->draw(testText);
	//testButtonSet.render(*window);

	//std::cout << "play draw" << std::endl;
}
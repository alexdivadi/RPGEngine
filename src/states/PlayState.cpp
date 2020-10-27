#include "../../src/states/PlayState.h"



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


	testButtonSet.init(WINDOW_WIDTH * 7.f / 10.f, (WINDOW_HEIGHT / 2.f), 200, 200, 3, "something-blah/", *testFont, 30);

	testButtonSet.setColors(sf::Color::White, sf::Color::Black, sf::Color(100, 100, 100), sf::Color(50, 50, 50));



	data->assets.addSong("HardRain", "Mother 3 - 036 Hard Rain.ogg", stateName);

	testMusic = data->assets.loadSong("HardRain", stateName);
	testMusic->setLoop(true);

	testMusic->play();

	/*
		actual game init
		World w("tiles", "ranch");


	*/
	data->assets.addTexture("PlayerSprite", "chara_01.jpg", stateName);
	player.initSprite(data->assets.loadTexture("PlayerSprite", stateName));

	data->assets.addTexture("Tileset", "tiles.png", stateName);
	world.generateMap(data->assets.loadTexture("Tileset", stateName), "O-1");

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

			if (event.key.code == sf::Keyboard::W) { player.yVel = -1 * player.speed; break; }	// player.moveUp	//player.move(0,1)
			if (event.key.code == sf::Keyboard::A) { player.xVel = -1 * player.speed; break; }
			if (event.key.code == sf::Keyboard::S) { player.yVel = 1 * player.speed; break; }
			if (event.key.code == sf::Keyboard::D) { player.xVel = 1 * player.speed; break; }

		}
	}

	//std::cout << "play input" << std::endl;
}

void PlayState::update(/* float dt */)
{
	//std::cout << sf::Mouse::getPosition().x << "  " << sf::Mouse::getPosition().y << std::endl;

	for (auto& e : world.entities)
		e->update(1.f / 60.f);	// 0.1f/60.f is temp dt

	testButtonSet.update(*window);

	//std::cout << "play update" << std::endl;
}

void PlayState::draw()
{
	window->draw(testSprite);
	window->draw(testText);

	world.render(window);

	for (auto& e : world.entities)
		e->render(*window);

	testButtonSet.render(*window);

	//std::cout << "play draw" << std::endl;
}
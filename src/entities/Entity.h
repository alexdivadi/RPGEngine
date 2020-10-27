#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
public:
	sf::Texture* texture;
	sf::Sprite sprite;

	float xPos;
	float yPos;
	int width;
	int height;

public:
	Entity(std::vector<Entity*>& e, float x, float y, int w, int h, sf::Texture* t);
	Entity(std::vector<Entity*>& e, float x, float y, int w, int h);
	~Entity();


	virtual void update(float dt);
	virtual void render(sf::RenderWindow& window);

	void initSprite(sf::Texture* t);
};
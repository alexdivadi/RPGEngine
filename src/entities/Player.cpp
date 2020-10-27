#include "../../src/entities/Player.h"

#include "../../src/data/ResourceManager.h"

#include <iostream>

Player::Player(std::vector<Entity*>& e, float x, float y, int w, int h, sf::Texture* t) : Entity(e, x, y, w, h, t)
{

}

Player::~Player()
{
}

void Player::init(std::vector<Entity*>& e, float x, float y, int w, int h, sf::Texture* t)
{

}

void Player::update(float dt)
{
	xPos += xVel * speed * dt;
	yPos += yVel * speed * dt;

	std::cout << "Player x: " << xPos << ", y: " << yPos << std::endl;

	sprite.setPosition(xPos, yPos);

	xVel = 0;
	yVel = 0;
}

bool Player::onInteract(std::vector<Entity>& e, Entity& target, NATURE nature)
{
	return false;
}
#pragma once

#include "../../src/entities/Entity.h"

class Player : public Entity
{
public:
	enum NATURE
	{
		TALK,
		FIGHT,
		GRAB,
		TELEPORT
	};
	// BattlePlayer p // stores player's combat stats

	float speed{ 10.f };
	float xVel;
	float yVel;

public:
	Player(std::vector<Entity*>& e, float x, float y, int w, int h, sf::Texture* t);
	~Player();

	void init(std::vector<Entity*>& e, float x, float y, int w, int h, sf::Texture* t);

	virtual void update(float dt);

	bool onInteract(std::vector<Entity>& e, Entity& target, NATURE nature);
};
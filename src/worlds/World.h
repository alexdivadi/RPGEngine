#pragma once

#include "../../src/worlds/Map.h"
#include "../../src/worlds/TileMap.h"
#include "../../src/entities/Entity.h"

#include <vector>

class Entity;

class World
{
public:
	Map cmap;
	TileMap tilemap;
	sf::Texture* tileset;

public:
	std::vector<Entity*> entities;

public:
	World();
	~World();

	/*
	Name: Generate Map
	Purpose: Uses map and tileset to load given level
	Parameters: string level_id
	Returns: Nothing
	*/
	void generateMap(sf::Texture* tileSpriteSheet, const std::string& level_id);
	void render(sf::RenderWindow* window);

};
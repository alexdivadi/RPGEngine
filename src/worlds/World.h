#pragma once
#include "../../src/data/GameData.h"
#include "../../src/worlds/Map.h"
#include "../../src/worlds/TileMap.h"

#include <vector>

class World
{
private:
	Map cmap;
	TileMap tilemap;
	//std::vector<Entitiy> entities;
	//Player player

public:
	World();
	~World();

	/*
	Name: Generate Map
	Purpose: Uses map and tileset to load given level
	Parameters: string level_id
	Returns: Nothing
	*/
	void generateMap(const std::string& level_id);
};
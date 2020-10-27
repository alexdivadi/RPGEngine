#include "../../src/worlds/World.h"

#include "../../src/constants/Constants.h"
#include "../../src/data/ResourceManager.h"


World::World()
{

}

World::~World()
{

}

void World::generateMap(sf::Texture* tileSpriteSheet, const std::string& level)
{
	std::string path = WORLD_FILE_ADDRESS + level + ".txt";

	this->tileset = tileSpriteSheet;

	this->cmap.create(path, level);
	this->tilemap.load(this->tileset, this->cmap);
}

void World::render(sf::RenderWindow* window)
{
	window->draw(tilemap);
}
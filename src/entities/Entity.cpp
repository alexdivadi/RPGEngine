#include "../../src/entities/Entity.h"

#include "../../src/data/ResourceManager.h"

Entity::Entity(std::vector<Entity*>& e, float x, float y, int w, int h, sf::Texture* t) : xPos(x), yPos(y), width(w), height(h), texture(t)
{
	e.push_back(this);
}

Entity::Entity(std::vector<Entity*>& e, float x, float y, int w, int h) : xPos(x), yPos(y), width(w), height(h)
{
	e.push_back(this);
}

Entity::~Entity()
{
}

void Entity::update(float dt)
{
	sprite.setPosition(xPos, yPos);
}

void Entity::render(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}

void Entity::initSprite(sf::Texture* t)
{
	if (this->texture == nullptr)
		this->texture = t;

	sprite.setTexture(*texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 130, 130));	//, width, height));
	sprite.setPosition(xPos, yPos);
}

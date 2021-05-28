#include "Entity.h"

Entity::Entity()
{
	sprite.setSize(sf::Vector2f(50.0f, 50.0f));
}

void Entity::move(const float x, const float y)
{
	sprite.move(x, y);
}

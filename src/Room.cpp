#include "Room.h"
#include <iostream>

Room::Room(sf::Vector2f pos, const sf::Texture* texture)
{
	sprite.setSize(sf::Vector2f(50.0f, 50.0f));
	sprite.setPosition(pos);
	sprite.setTexture(texture);
}

void Room::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

bool Room::tryStartCombat()
{
	if (!alreadyTriggered)
	{
		alreadyTriggered = true;
		return true;
	}
	return false;
}

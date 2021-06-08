#include "Room.h"
#include <iostream>

Room::Room(sf::Vector2f pos, const sf::Texture* roomTexture, const sf::Texture* ennemyTexture)
{
	roomSprite.setSize(sf::Vector2f(50, 50));
	roomSprite.setPosition(pos);
	roomSprite.setTexture(roomTexture);

	contentSprite.setSize(sf::Vector2f(40, 40));
	contentSprite.setPosition(pos + sf::Vector2f(5,5));
	contentSprite.setTexture(ennemyTexture);
}

void Room::render(sf::RenderTarget& target) const
{
	target.draw(roomSprite);
	if (!alreadyTriggered)
	{
		target.draw(contentSprite);
	}
}

int Room::enterRoom()
{
	if (!alreadyTriggered && !victory)
	{
		alreadyTriggered = true;
		return 1;
	}
	if (victory)
	{
		return 2;
	}
	return 0;
}

void Room::setFlag(const sf::Texture* flagTexture)
{
	victory = true;
	contentSprite.setTexture(flagTexture);
}

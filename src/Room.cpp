#include "Room.h"
#include <iostream>

Room::Room(sf::Vector2f pos)
{
	sprite.setSize(sf::Vector2f(50.0f, 50.0f));
	sprite.setPosition(pos);
	sprite.setFillColor(sf::Color::Green);
}

void Room::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

void Room::tryStartCombat(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states)
{
	if (!alreadyTriggered)
	{
		states->push(std::make_unique<CombatState>(manager, states));
		alreadyTriggered = true;
	}
}

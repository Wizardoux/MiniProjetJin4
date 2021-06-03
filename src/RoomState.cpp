#include "RoomState.h"
#include <iostream>

void RoomState::initPlayer()
{
	player = std::make_unique<Player>(sf::Vector2f(50, 200));
}

void RoomState::initDungeon()
{
	sf::Vector2f pos(50, 200);
	for (int i = 0; i < 5; i++)
	{
		rooms.push_back(std::make_unique<Room>(pos));
		pos.x += 60;
	}
	rooms[0]->useRoom();
}

RoomState::RoomState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states):
	State(manager, states)
{
	initDungeon();
	initPlayer();
}

void RoomState::render(sf::RenderTarget& target)
{
	for (auto&& room : rooms)
	{
		room->render(target);
	}
	player->render(target);
}

void RoomState::update()
{
}

void RoomState::checkKeyInput(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Escape)
	{
		exitState();
	}
	else if (event.key.code == sf::Keyboard::Left)
	{
		player->moveBack();
		rooms[player->getIndex()]->tryStartCombat(ressourceManager, states);
	}
	else if (event.key.code == sf::Keyboard::Right)
	{
		player->moveFrwd();
		rooms[player->getIndex()]->tryStartCombat(ressourceManager, states);
	}
}

void RoomState::checkMouseInput(sf::Event event, sf::Vector2f mousePos)
{
}

void RoomState::endState()
{
	std::cout << "Ending Game State\n";
}

#include "RoomState.h"
#include <iostream>

void RoomState::initPlayer()
{
	player = std::make_shared<Player>(sf::Vector2f(185, 285), ressourceManager->getPlayerTexture());
}

void RoomState::initDungeon()
{
	sf::Vector2f pos(180, 280);
	for (int i = 0; i < 5; i++)
	{
		rooms.push_back(std::make_unique<Room>(pos, ressourceManager->getRoomTexture()));
		pos.x += 60;
	}
	rooms[0]->useRoom();
}

RoomState::RoomState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states):
	State(manager, states)
{
	background.setSize(sf::Vector2f(800, 600));
	background.setTexture(ressourceManager->getspaceshipTexture());
	//Play menu music
	ressourceManager->playGameMusic();
	initDungeon();
	initPlayer();
}

void RoomState::render(sf::RenderTarget& target)
{
	target.draw(background);
	for (auto&& room : rooms)
	{
		room->render(target);
	}
	player->render(target);
}

void RoomState::update()
{
	if (player->checkIfDead())
	{
		exitState();
	}
}

void RoomState::checkKeyInput(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Left)
	{
		player->moveBack();
		if (rooms[player->getIndex()]->tryStartCombat())
		{
			StartCombat();
		}
	}
	else if (event.key.code == sf::Keyboard::Right)
	{
		player->moveFrwd();
		if (rooms[player->getIndex()]->tryStartCombat())
		{
			StartCombat();
		}
	}
}

void RoomState::checkMouseInput(sf::Event event, sf::Vector2f mousePos)
{
}

void RoomState::endState()
{
	ressourceManager->stopGameMusic();
	ressourceManager->playMenuMusic();
	std::cout << "Ending Game State\n";
}

void RoomState::StartCombat()
{
	player->refreshActionPoints();
	states->push(std::make_unique<CombatState>(ressourceManager, states, player));
}

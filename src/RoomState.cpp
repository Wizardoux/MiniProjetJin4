#include "RoomState.h"
#include <iostream>

//Constructor
RoomState::RoomState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states):
	State(manager, states),
	player(sf::Vector2f(305, 285), ressourceManager->getPlayerTexture())
{
	//Play menu music
	ressourceManager->playGameMusic();
	//Initialize variables
	initBackground();
	initDungeon();
	initPlayer();
}

//Init Functions
void RoomState::initBackground()
{
	background.setSize(sf::Vector2f(1020, 600));
	background.setTexture(ressourceManager->getSpaceshipTexture());
}

void RoomState::initPlayer()
{
	player.addWeapon(ressourceManager->getRandomWeapon());
	player.addWeapon(ressourceManager->getRandomWeapon());
}

void RoomState::initDungeon()
{
	//Create a dungeon with rooms
	sf::Vector2f pos(300, 280);
	for (int i = 0; i < 6; i++)
	{
		rooms.emplace_back(Room(pos, ressourceManager->getRoomTexture(), ressourceManager->getEnnemyTexture()));
		pos.x += 60;
	}
	//Make the first room of the dungeon safe
	rooms[0].useRoom();
	rooms[5].setFlag(ressourceManager->getFlagTexture());
}

//Others Functions
void RoomState::StartCombat()
{
	player.refreshActionPoints();
	states->push(std::make_unique<CombatState>(ressourceManager, states, &player));
}

//Engine Functions
void RoomState::render(sf::RenderTarget& target)
{
	target.draw(background);
	for (auto& room : rooms)
	{
		room.render(target);
	}
	player.render(target);
}

void RoomState::update()
{
	if (player.checkIfDead())
	{
		exitState();
	}
}

void RoomState::checkKeyInput(sf::Event event)
{
	//Check player movement and enters in the room
	if (event.key.code == sf::Keyboard::Left)
	{
		player.moveBack();
		if (rooms[player.getIndex()].enterRoom() == 1)
		{
			StartCombat();
		}
		if (rooms[player.getIndex()].enterRoom() == 2)
		{
			exitState();
		}
	}
	else if (event.key.code == sf::Keyboard::Right)
	{
		player.moveFrwd();
		if (rooms[player.getIndex()].enterRoom() == 1)
		{
			StartCombat();
		}
		if (rooms[player.getIndex()].enterRoom() == 2)
		{
			exitState();
		}
	}
}

void RoomState::checkMouseInput(sf::Event event, sf::Vector2f mousePos)
{
	//No mouse input
}

void RoomState::endState()
{
	ressourceManager->stopGameMusic();
	ressourceManager->playMenuMusic();
	std::cout << "Ending Game State\n";
}

//Imgui Functions
void RoomState::renderImgui()
{
	ImGui::Begin("Spaceship");
	//Button to kill all ennemy of the dungeon
	if (ImGui::Button("clean dungeon")) {
		for (auto& room : rooms)
		{
			room.enterRoom();
		}
	}
	ImGui::End();
}

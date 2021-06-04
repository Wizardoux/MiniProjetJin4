#pragma once
#include "State.h"
#include "Player.h"
#include "Room.h"
#include "Weapon.h"

class RoomState : public State
{
private:
	//Variables
	sf::RectangleShape background;
	std::shared_ptr<Player> player;
	std::vector<std::unique_ptr<Room>> rooms;

	//Functions
	void initPlayer();
	void initDungeon();

public:
	// Constructor/Destructor
	RoomState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states);
	virtual ~RoomState() = default;

	//Others Functions
	void render(sf::RenderTarget& target) override;
	void update() override;
	void checkKeyInput(sf::Event event) override;
	void checkMouseInput(sf::Event event, sf::Vector2f mousePos) override;
	void endState() override;
	void StartCombat();
};
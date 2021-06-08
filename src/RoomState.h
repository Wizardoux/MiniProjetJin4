#pragma once
#include "State.h"
#include "Player.h"
#include "Room.h"
#include "Weapon.h"
#include <imgui-SFML.h>
#include <imgui.h>

class RoomState : public State
{
private:
	//Variables
	Player player;
	std::vector<Room> rooms;

	//Init Functions
	void initBackground();
	void initPlayer();
	void initDungeon();

	//Others Functions
	void StartCombat();

public:
	// Constructor/Destructor
	RoomState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states);
	virtual ~RoomState() = default;

	//Engine Functions
	void render(sf::RenderTarget& target) const override;
	void update() override;
	void checkKeyInput(sf::Event event) override;
	void checkMouseInput(sf::Event event, sf::Vector2f mousePos) override;
	void endState() override;

	//Imgui Functions
	void renderImgui() override;
};
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <stack>
#include "State.h"
#include "CombatState.h"

class Room
{
private:
	sf::RectangleShape sprite;
	bool alreadyTriggered = false;

public:
	Room(sf::Vector2f pos);
	virtual ~Room() = default;

	// Functions
	void render(sf::RenderTarget& target);
	void tryStartCombat(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states);
	void useRoom() { alreadyTriggered = true; }
};


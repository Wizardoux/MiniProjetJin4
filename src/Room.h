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
	Room(sf::Vector2f pos, const sf::Texture* texture);
	virtual ~Room() = default;

	// Functions
	void render(sf::RenderTarget& target);
	bool tryStartCombat();
	void useRoom() { alreadyTriggered = true; }
};


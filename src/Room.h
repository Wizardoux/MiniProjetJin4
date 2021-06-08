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
	sf::RectangleShape roomSprite;
	sf::RectangleShape contentSprite;
	bool alreadyTriggered = false;
	bool victory = false;

public:
	Room(sf::Vector2f pos, const sf::Texture* roomTexture, const sf::Texture* ennemyTexture);
	virtual ~Room() = default;

	// Functions
	void render(sf::RenderTarget& target) const;
	int enterRoom();
	void useRoom() { alreadyTriggered = true; }
	void setFlag(const sf::Texture* flagTexture);
};


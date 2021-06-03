#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class Player
{
private:
	int indexRoom = 0;
	sf::RectangleShape sprite;

public:
	Player(sf::Vector2f pos);
	virtual ~Player() = default;

	// Functions
	void moveFrwd();
	void moveBack();
	void render(sf::RenderTarget& target);

	//Getter
	int getIndex() const { return indexRoom; }
};


#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class Entity
{
private:

protected:
	sf::RectangleShape sprite;

public:
	Entity();
	virtual ~Entity() = 0;

	// Functions
	virtual void move(const float x, const float y);
	virtual void update() = 0;
	virtual void render(sf::RenderTarget* target) = 0;
};


#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class Button
{
private:
	sf::RectangleShape sprite;
	sf::Text buttonText;

public:
	// Constructor/Destructor
	Button(sf::Vector2f position, const sf::Font &font, const std::string &text);
	virtual ~Button() = default;

	//Functions
	bool checkMouseOver(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget& target);
};
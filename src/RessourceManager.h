#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class RessourceManager
{
private:
	sf::Font gameFont;

public:
	//Constructors/Destructors
	RessourceManager();
	virtual ~RessourceManager() = default;

	//Getter
	sf::Font getFont() const { return gameFont; }
};


#pragma once
#include<stack>
#include<map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class State
{
private:
	bool quit = false;

public:
	// Constructor/Destructor
	State() = default;
	virtual ~State() = default;

	//Getter
	bool getQuit() const { return quit; }

	//Functions
	virtual void render(sf::RenderTarget& target) = 0;
	virtual void update() = 0;
	virtual void checkKeyInput(sf::Event event) = 0;
	virtual void exitState();
	virtual void endState() = 0;
};
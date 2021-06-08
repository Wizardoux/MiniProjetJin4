#pragma once
#include<stack>
#include<map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "RessourceManager.h"
#ifndef TESTBUILD
#include <imgui-SFML.h>
#include <imgui.h>
#endif // !TESTBUILD

class State
{
private:
	bool quit = false;

protected:
	RessourceManager* ressourceManager;
	std::stack<std::unique_ptr<State>>* states;
	sf::RectangleShape background;

public:
	// Constructor/Destructor
	State(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states);
	virtual ~State() = default;

	//Others Functions
	virtual void render(sf::RenderTarget& target) const = 0;
	virtual void update() = 0;
	virtual void checkKeyInput(sf::Event event) = 0;
	virtual void checkMouseInput(sf::Event event, sf::Vector2f mousePos) = 0;
	virtual void exitState();
	virtual void endState() = 0;

	//Imgui Functions
	virtual void renderImgui() = 0;

	//Getter
	bool getQuit() const { return quit; }
};
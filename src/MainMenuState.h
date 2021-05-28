#pragma once
#include "State.h"
#include "Button.h"

class MainMenuState : public State
{
private:
	sf::RectangleShape background;

public:
	// Constructor/Destructor
	MainMenuState();
	virtual ~MainMenuState() = default;

	//Functions
	void render(sf::RenderTarget& target) override;
	void update() override;
	void checkKeyInput(sf::Event event) override;
	void endState() override;
};
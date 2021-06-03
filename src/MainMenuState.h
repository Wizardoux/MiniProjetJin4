#pragma once
#include "State.h"
#include "Button.h"

class MainMenuState : public State
{
private:
	//Variables
	sf::RectangleShape background;
	std::vector<std::unique_ptr<Button>> buttons;

	//Functions
	void initButtons();

public:
	// Constructor/Destructor
	MainMenuState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states);
	virtual ~MainMenuState() = default;

	//Functions
	void render(sf::RenderTarget& target) override;
	void update() override;
	void checkKeyInput(sf::Event event) override;
	void checkMouseInput(sf::Event event, sf::Vector2f mousePos) override;
	void endState() override;
};
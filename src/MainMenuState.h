#pragma once
#include "State.h"
#include "Button.h"

class MainMenuState : public State
{
private:
	//Variables
	std::vector<Button> buttons;

	//Init Functions
	void initBackground();
	void initButtons();

public:
	// Constructor/Destructor
	MainMenuState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states);
	virtual ~MainMenuState() = default;

	//Engine Functions
	void render(sf::RenderTarget& target) const override;
	void update() override;
	void checkKeyInput(sf::Event event) override;
	void checkMouseInput(sf::Event event, sf::Vector2f mousePos) override;
	void endState() override;

	//Imgui Functions
	void renderImgui() override;
};
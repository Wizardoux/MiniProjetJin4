#pragma once
#include "State.h"
#include "Button.h"

class VictoryState : public State
{
private : 
	//Variables
	Button backMenu;
	sf::Text victoryText; 

	//Init Functions
	void initBackground();
	void initBtns();
	void initText();

public:
	// Constructor/Destructor
	VictoryState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states);
	virtual ~VictoryState() = default;

	//Engine Functions
	void render(sf::RenderTarget& target) const override;
	void update() override;
	void checkKeyInput(sf::Event event) override;
	void checkMouseInput(sf::Event event, sf::Vector2f mousePos) override;
	void endState() override;

	void renderImgui() override;
};

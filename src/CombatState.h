#pragma once
#include "State.h"

class CombatState : public State
{
private:

public:
	// Constructor/Destructor
	CombatState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states);
	virtual ~CombatState() = default;

	//Functions
	void render(sf::RenderTarget& target) override;
	void update() override;
	void checkKeyInput(sf::Event event) override;
	void checkMouseInput(sf::Event event, sf::Vector2f mousePos) override;
	void endState() override;
};
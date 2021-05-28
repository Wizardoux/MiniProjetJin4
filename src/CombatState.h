#pragma once
#include "State.h"

class CombatState : public State
{
private:

public:
	// Constructor/Destructor
	CombatState() = default;
	virtual ~CombatState() = default;

	//Functions
	void render(sf::RenderTarget& target) override;
	void update() override;
	void checkKeyInput(sf::Event event) override;
	void endState() override;
};
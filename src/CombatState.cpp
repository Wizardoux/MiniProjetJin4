#include "CombatState.h"
#include <iostream>

void CombatState::render(sf::RenderTarget& target)
{
}

void CombatState::update()
{
	std::cout << "Hello from Combat State\n";
}

void CombatState::checkKeyInput(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Escape)
	{
		exitState();
	}
}

void CombatState::endState()
{
	std::cout << "Ending Game State\n";
}

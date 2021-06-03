#include "CombatState.h"
#include <iostream>

CombatState::CombatState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states):
	State(manager, states)
{
}

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

void CombatState::checkMouseInput(sf::Event event, sf::Vector2f mousePos)
{
}

void CombatState::endState()
{
	std::cout << "Ending Game State\n";
}

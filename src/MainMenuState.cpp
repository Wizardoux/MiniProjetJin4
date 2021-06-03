#include "MainMenuState.h"
#include "CombatState.h"
#include "RoomState.h"
#include <iostream>

void MainMenuState::initButtons()
{
	buttons.push_back(std::make_unique<Button>(sf::Vector2f(300, 200), ressourceManager->getFont(), "play"));
	buttons.push_back(std::make_unique<Button>(sf::Vector2f(300, 300), ressourceManager->getFont(), "play"));
}

MainMenuState::MainMenuState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states):
	State(manager, states)
{
	background.setSize(sf::Vector2f(800,600));
	background.setFillColor(sf::Color::Blue);
	initButtons();
}

void MainMenuState::render(sf::RenderTarget& target)
{
	target.draw(background);
	for (auto&& btn : buttons)
	{
		btn->render(target);
	}
}

void MainMenuState::update()
{
}

void MainMenuState::checkKeyInput(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Escape)
	{
		exitState();
	}
}

void MainMenuState::checkMouseInput(sf::Event event, sf::Vector2f mousePos)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		if (buttons[0]->checkMouseOver(mousePos))
		{
			states->push(std::make_unique<RoomState>(ressourceManager, states));
		}
		if (buttons[1]->checkMouseOver(mousePos))
		{
			exitState();
		}
	}
}

void MainMenuState::endState()
{
	std::cout << "Ending Menu State\n";
}

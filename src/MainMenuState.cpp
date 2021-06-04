#include "MainMenuState.h"
#include "CombatState.h"
#include "RoomState.h"
#include <iostream>

void MainMenuState::initButtons()
{
	//Setup the two buttons of the menu
	buttons.push_back(std::make_unique<Button>(sf::Vector2f(330, 200), ressourceManager->getFont(), "Play", ressourceManager->getButtonTexture()));
	buttons.push_back(std::make_unique<Button>(sf::Vector2f(330, 330), ressourceManager->getFont(), "Quit", ressourceManager->getButtonTexture()));
}

MainMenuState::MainMenuState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states):
	State(manager, states)
{
	//Play menu music
	ressourceManager->playMenuMusic();
	//Setup the background
	background.setSize(sf::Vector2f(800,600));
	background.setTexture(ressourceManager->getMenuTexture());
	//Initialize buttons
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
			ressourceManager->stopMenuMusic();
		}
		if (buttons[1]->checkMouseOver(mousePos))
		{
			exitState();
		}
	}
}

void MainMenuState::endState()
{
	ressourceManager->stopMenuMusic();
	std::cout << "Ending Menu State\n";
}

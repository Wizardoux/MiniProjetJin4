#include "MainMenuState.h"
#include "CombatState.h"
#include "RoomState.h"
#include <iostream>

//Constructor
MainMenuState::MainMenuState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states) :
	State(manager, states)
{
	//Play menu music
	ressourceManager->playMenuMusic();
	//Initialize variables
	initBackground();
	initButtons();
}

//Init Functions
void MainMenuState::initBackground()
{
	//Setup the background
	background.setSize(sf::Vector2f(1020, 600));
	background.setTexture(ressourceManager->getMenuTexture());
}

void MainMenuState::initButtons()
{
	//Setup the two buttons of the menu
	buttons.emplace_back(Button(sf::Vector2f(450, 200), ressourceManager->getFont(), "Play", ressourceManager->getButtonTexture()));
	buttons.emplace_back(Button(sf::Vector2f(450, 330), ressourceManager->getFont(), "Quit", ressourceManager->getButtonTexture()));
}

//Engine Functions
void MainMenuState::render(sf::RenderTarget& target)
{
	target.draw(background);
	for (auto& btn : buttons)
	{
		btn.render(target);
	}
}

void MainMenuState::update()
{
	// Nothing to check here
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
	//Check if the player click on a button
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		if (buttons[0].checkMouseOver(mousePos))
		{
			states->push(std::make_unique<RoomState>(ressourceManager, states));
			ressourceManager->stopMenuMusic();
		}
		if (buttons[1].checkMouseOver(mousePos))
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

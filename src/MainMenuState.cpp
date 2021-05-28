#include "MainMenuState.h"
#include <iostream>

MainMenuState::MainMenuState()
{
	background.setSize(sf::Vector2f(800,600));
	background.setFillColor(sf::Color::Blue);
}

void MainMenuState::render(sf::RenderTarget& target)
{
	target.draw(background);
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

void MainMenuState::endState()
{
	std::cout << "Ending Menu State\n";
}

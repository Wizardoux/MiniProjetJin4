#include "VictoryState.h"

VictoryState::VictoryState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states):
	State(manager, states),
	backMenu(Button(sf::Vector2f(410, 330), ressourceManager->getFont(), "Back to menu", ressourceManager->getButtonTexture()))
{
	initBackground();
	initBtns();
	initText();
}

//Init Functions
void VictoryState::initBackground() 
{

	background.setSize(sf::Vector2f(1020, 600));
	background.setTexture(ressourceManager->getVictoryTexture());
}

void VictoryState::initBtns() 
{
	backMenu.setSize(sf::Vector2f(220, 70));
}

void VictoryState::initText()
{
	victoryText.setString("You win");
	victoryText.setFont(*ressourceManager->getFont());
	victoryText.setCharacterSize(40);
	victoryText.setFillColor(sf::Color::White);
	victoryText.setPosition(sf::Vector2f(435, 200));
}


//Engine Functions
void VictoryState::render(sf::RenderTarget & target) const 
{
	target.draw(background);
	target.draw(victoryText);
	backMenu.render(target);
}

void VictoryState::update()
{
	//nothing to update
}

void VictoryState::checkKeyInput(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Escape)
	{
		exitState();
	}
}

void VictoryState::checkMouseInput(sf::Event event, sf::Vector2f mousePos)
{
	if (event.mouseButton.button == sf::Mouse::Left && backMenu.checkMouseOver(mousePos))
	{	
		exitState();
	}
}

void VictoryState::endState() 
{
	std::cout << "Ending Victory State\n";
}

void VictoryState::renderImgui() 
{
	//nothing to render
}

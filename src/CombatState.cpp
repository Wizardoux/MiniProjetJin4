#include "CombatState.h"
#include <iostream>
#include <Button.h>

//Constructor
CombatState::CombatState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states, std::shared_ptr<Player> player):
	State(manager, states),
	//Share the player with RoomState
	player(player),
	ennemy(ressourceManager->getEnnemyTexture()),
	//Initialize Buttons
	playerHp(sf::Vector2f(30, 500), ressourceManager->getFont(), "health: " + std::to_string(player->getHp()), ressourceManager->getButtonTexture()),
	ennemyHp(sf::Vector2f(800, 500), ressourceManager->getFont(),"ennemy: " + std::to_string(ennemy.getHp()), ressourceManager->getButtonTexture()),
	endTurnButton(sf::Vector2f(800, 50), ressourceManager->getFont(), "end Turn", ressourceManager->getButtonTexture()),
	playerAP(sf::Vector2f(30, 420), ressourceManager->getFont(), "Action: " + std::to_string(player->getAction()), ressourceManager->getButtonTexture()),
	textBox(sf::Vector2f(240, 420), ressourceManager->getFont(), "Combat information here", ressourceManager->getTextboxTexture())
{
	//Initialize rest of the variables
	initBackground();
	initPlayerSprite();
	InitEnnemy();
	initWeaponsBtns();
	initTextBox();
}

//Init Functions
void CombatState::initBackground()
{
	background.setSize(sf::Vector2f(1020, 600));
	background.setTexture(ressourceManager->getInteriorTexture());
}

void CombatState::initPlayerSprite()
{
	playerSprite.setSize(sf::Vector2f(40, 40));
	playerSprite.setTexture(ressourceManager->getPlayerTexture());
	playerSprite.setPosition(sf::Vector2f(400, 300));
}

void CombatState::initWeaponsBtns()
{
	//Create a button for each player's weapon and initialize vector of weapons
	sf::Vector2f pos(30, 20);
	playerWeapons = player->getWeapon();
	for (auto&& weapon : playerWeapons)
	{
		weaponsBtns.emplace_back(WeaponButton(pos, ressourceManager->getFont(), ressourceManager->getButtonTexture(), weapon));
		pos.y += 80;
	}
}

void CombatState::InitEnnemy()
{
	ennemy.addWeapon(ressourceManager->getRandomWeapon());
	ennemy.addWeapon(ressourceManager->getRandomWeapon());
	ennemy.addWeapon(ressourceManager->getRandomWeapon());
	ennemyWeapons = ennemy.getWeapon();
}

void CombatState::initTextBox()
{
	textBox.setSize(sf::Vector2f(550, 150));
}

//Others Functions
void CombatState::refreshUI()
{
	//Refresh values of the UI
	playerHp.setText("health: " + std::to_string(player->getHp()));
	ennemyHp.setText("ennemy: " + std::to_string(ennemy.getHp()));
	playerAP.setText("Action: " + std::to_string(player->getAction()));
}

void CombatState::refreshCombat()
{
	refreshUI();
	if (ennemy.checkIfDead() || player->checkIfDead())
	{
		stealWeapon();
		exitState();
	}
}

void CombatState::endTurn()
{
	//Increase of the player, and play the ennemy turn
	player->increaseActionPoints();
	playEnnemyTurn();
	refreshCombat();
}

void CombatState::playEnnemyTurn()
{
	// Obtain a random index of a weapon used by the ennemy
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, ennemyWeapons.size() - 1); // define the range
	int randomIndex = distr(gen);
	//Use this random weapon
	ennemy.useWeapon(randomIndex, *player);
	textBox.setText("ennemy use " + ennemyWeapons[randomIndex]->getName() + ", deals " + std::to_string(ennemyWeapons[randomIndex]->getDamage())
	+ "\nbut suffer " + std::to_string(ennemyWeapons[randomIndex]->getRepercussion()));
	ressourceManager->playBlaster();
}

void CombatState::stealWeapon()
{
	// Obtain a random index of a weapon used by the ennemy
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, ennemyWeapons.size() - 1); // define the range
	int randomIndex = distr(gen);
	player->addWeapon(*ennemyWeapons[randomIndex]);
}

//Engine Functions
void CombatState::render(sf::RenderTarget& target)
{
	target.draw(background);
	target.draw(playerSprite);
	ennemy.render(target);
	playerHp.render(target);
	ennemyHp.render(target);
	endTurnButton.render(target);
	playerAP.render(target);
	for (auto& button : weaponsBtns)
	{
		button.render(target);
	}
	textBox.render(target);
}

void CombatState::update()
{
	//No current need to check something
}

void CombatState::checkKeyInput(sf::Event event)
{
	//No Keyboard input to manage
}

void CombatState::checkMouseInput(sf::Event event, sf::Vector2f mousePos)
{
	//Check if the player click on a button
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		//Weapon Buttons
		for (int i = 0; i < weaponsBtns.size(); i++)
		{
			if (weaponsBtns[i].checkMouseOver(mousePos))
			{
				if (player->tryUseWeapon(i, ennemy))
				{
					textBox.setText("player use " + playerWeapons[i]->getName() + ", deals " + std::to_string(playerWeapons[i]->getDamage())
					+ "\nbut suffer " + std::to_string(playerWeapons[i]->getRepercussion()));
					ressourceManager->playBlaster();
				}
				refreshCombat();
			}
		}
		//EndTurn Button
		if (endTurnButton.checkMouseOver(mousePos))
		{
			endTurn();
		}
	}
}

void CombatState::endState()
{
	std::cout << "Ending Game State\n";
}

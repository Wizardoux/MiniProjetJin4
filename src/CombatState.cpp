#include "CombatState.h"
#include <iostream>
#include <Button.h>

CombatState::CombatState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states, std::shared_ptr<Player> player):
	State(manager, states),
	player(player),
	endTurnButton(sf::Vector2f(580,50), ressourceManager->getFont(), "end Turn", ressourceManager->getButtonTexture()),
	playerAP(sf::Vector2f(30, 420), ressourceManager->getFont(), "Action: " + std::to_string(player->getAction()), ressourceManager->getButtonTexture())
{
	ennemy = std::make_unique<Character>(ressourceManager->getEnnemyTexture());
	background.setSize(sf::Vector2f(800, 600));
	background.setTexture(ressourceManager->getInteriorTexture());
	playerSprite.setSize(sf::Vector2f(40, 40));
	playerSprite.setTexture(ressourceManager->getPlayerTexture());
	playerSprite.setPosition(sf::Vector2f(400, 300));
	playerHp = std::make_unique<Button>(sf::Vector2f(30, 500), ressourceManager->getFont(),
	"health: " + std::to_string(player->getHp()), ressourceManager->getButtonTexture());
	ennemyHp = std::make_unique<Button>(sf::Vector2f(580, 500), ressourceManager->getFont(),
	"ennemy: " + std::to_string(ennemy->getHp()), ressourceManager->getButtonTexture());
	initWeaponsBtns();
}

void CombatState::initWeaponsBtns()
{
	sf::Vector2f pos(100, 120);
	for (int i = 0; i < player->getnbWeapons(); i++)
	{
		weaponsBtns.push_back(std::make_unique<Button>(pos, ressourceManager->getFont(), "Weapon", ressourceManager->getButtonTexture()));
		pos.y += 80;
	}
}

void CombatState::refreshUI()
{
	playerHp->setText("health: " + std::to_string(player->getHp()));
	ennemyHp->setText("ennemy: " + std::to_string(ennemy->getHp()));
	playerAP.setText("Action: " + std::to_string(player->getAction()));
}

void CombatState::endTurn()
{
	player->increaseActionPoints();
	ennemy->useWeapon(0, *player);
	ressourceManager->playBlaster();
	refreshUI();
	if (ennemy->checkIfDead() || player->checkIfDead())
	{
		exitState();
	}
}

void CombatState::render(sf::RenderTarget& target)
{
	target.draw(background);
	target.draw(playerSprite);
	ennemy->render(target);
	for (auto&& button : weaponsBtns)
	{
		button->render(target);
	}
	playerHp->render(target);
	ennemyHp->render(target);
	endTurnButton.render(target);
	playerAP.render(target);
}

void CombatState::update()
{
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
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		for (int i = 0; i < weaponsBtns.size(); i++)
		{
			if (weaponsBtns[i]->checkMouseOver(mousePos))
			{
				if (player->tryUseWeapon(i, *ennemy))
				{
					ressourceManager->playBlaster();
				}
				refreshUI();
				if (ennemy->checkIfDead() || player->checkIfDead())
				{
					exitState();
				}
			}
		}
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

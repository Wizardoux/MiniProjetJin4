#pragma once
#include "State.h"
#include "Player.h"
#include "Button.h"

class CombatState : public State
{
private:
	//Variables
	std::shared_ptr<Player> player;
	std::unique_ptr<Character> ennemy;
	std::vector<std::unique_ptr<Button>> weaponsBtns;
	sf::RectangleShape background;
	sf::RectangleShape playerSprite;
	std::unique_ptr<Button> playerHp;
	std::unique_ptr<Button> ennemyHp;
	Button endTurnButton;
	Button playerAP;

public:
	// Constructor/Destructor
	CombatState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states, std::shared_ptr<Player> player);
	virtual ~CombatState() = default;

	//Init Functions
	void initWeaponsBtns();

	//Others Functions
	void refreshUI();
	void endTurn();
	void render(sf::RenderTarget& target) override;
	void update() override;
	void checkKeyInput(sf::Event event) override;
	bool checkEnnemyDefeated();
	void checkMouseInput(sf::Event event, sf::Vector2f mousePos) override;
	void endState() override;
};
#pragma once
#include "State.h"
#include "Player.h"
#include "WeaponButton.h"

class CombatState : public State
{
private:
	//Variables
	Player* player;
	std::vector<std::shared_ptr<Weapon>> playerWeapons;
	std::vector<std::shared_ptr<Weapon>> ennemyWeapons;
	Character ennemy;
	Button playerHp;
	Button ennemyHp;
	Button endTurnButton;
	Button playerAP;
	Button textBox;
	std::vector<WeaponButton> weaponsBtns;
	sf::RectangleShape playerSprite;

	//Init Functions
	void initBackground();
	void initPlayerSprite();
	void initWeaponsBtns();
	void InitEnnemy();
	void initTextBox();

	//Others Functions
	void refreshUI();
	void refreshCombat();
	void endTurn();
	void playEnnemyTurn();
	void stealWeapon();

	//Imgui Functions
	void renderImgui() override;

public:
	// Constructor/Destructor
	CombatState(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states, Player* player);
	virtual ~CombatState() = default;

	//Engine Functions
	void render(sf::RenderTarget& target) override;
	void update() override;
	void checkKeyInput(sf::Event event) override;
	void checkMouseInput(sf::Event event, sf::Vector2f mousePos) override;
	void endState() override;
};
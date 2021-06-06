#pragma once
#include "Character.h"

class Player: public Character
{
private:
	//Variables
	int indexRoom = 0;
	int actionPoint = 5;

public:
	//Constructors/Destructors
	Player(sf::Vector2f pos, const sf::Texture* texture);
	virtual ~Player() = default;

	//Others Functions
	void moveFrwd();
	void moveBack();
	void increaseActionPoints();
	void refreshActionPoints();
	bool tryUseWeapon(int weaponIndex, Character& target);

	//Getter
	int getIndex() const { return indexRoom; }
	int getAction() const { return actionPoint; }
};


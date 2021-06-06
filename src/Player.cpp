#include "Player.h"

//Constructors
Player::Player(sf::Vector2f pos, const sf::Texture* texture):
	Character(texture)
{
	sprite.setPosition(pos);
}

//Others Functions
void Player::moveFrwd()
{
	//Call in roomstate to move the character
	if (indexRoom < 5)
	{
		sprite.move(60, 0);
		indexRoom++;
	}
}

void Player::moveBack()
{
	//Call in roomstate to move the character
	if (indexRoom > 0)
	{
		sprite.move(-60, 0);
		indexRoom--;
	}
}

void Player::increaseActionPoints()
{
	//Increase action points of the player
	actionPoint += 5;
}

void Player::refreshActionPoints()
{
	//Refresh action points of the player
	actionPoint = 5;
}

bool Player::tryUseWeapon(int weaponIndex, Character& target)
{
	//Use the weapon if enough action points
	if (actionPoint >= inventory[weaponIndex]->getCost())
	{
		actionPoint -= inventory[weaponIndex]->getCost();
		Character::useWeapon(weaponIndex, target);
		return true;
	}
	return false;
}

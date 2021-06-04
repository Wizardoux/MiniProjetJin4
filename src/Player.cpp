#include "Player.h"

Player::Player(sf::Vector2f pos, const sf::Texture* texture):
	Character(texture)
{
	sprite.setPosition(pos);
}

void Player::moveFrwd()
{
	if (indexRoom < 4)
	{
		sprite.move(60, 0);
		indexRoom++;
	}
}

void Player::moveBack()
{
	if (indexRoom > 0)
	{
		sprite.move(-60, 0);
		indexRoom--;
	}
}

void Player::increaseActionPoints()
{
	actionPoint += 5;
}

void Player::refreshActionPoints()
{
	actionPoint = 5;
}

bool Player::tryUseWeapon(int weaponIndex, Character& target)
{
	if (actionPoint >= inventory[weaponIndex]->getCost())
	{
		actionPoint -= inventory[weaponIndex]->getCost();
		Character::useWeapon(weaponIndex, target);
		return true;
	}
	return false;
}

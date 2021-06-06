#pragma once
#include "Character.h"
#include <iostream>

Character::Character(const sf::Texture* texture)
{
	sprite.setSize(sf::Vector2f(40, 40));
	sprite.setPosition(sf::Vector2f(600, 300));
	sprite.setTexture(texture);
}

void Character::render(sf::RenderTarget& target) const
{
	target.draw(sprite);
}

void Character::takeDamage(int amount)
{
	hp -= amount;
}

void Character::useWeapon(int weaponIndex, Character& target)
{
	if (inventory.size() >= weaponIndex + 1)
	{
		target.takeDamage(inventory[weaponIndex]->getDamage());
		takeDamage(inventory[weaponIndex]->getRepercussion());
		std::cout << "player deals " << inventory[weaponIndex]->getDamage() << "and takes " << inventory[weaponIndex]->getRepercussion() << "\n";
	}
}

bool Character::checkIfDead() const
{
	if (hp <= 0)
	{
		return true;
	}
	return false;
}

void Character::addWeapon(Weapon weapon)
{
	inventory.push_back(std::make_shared<Weapon>(weapon));
}

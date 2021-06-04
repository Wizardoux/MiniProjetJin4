#pragma once
#include "Character.h"
#include <iostream>

Character::Character(const sf::Texture* texture)
{
	sprite.setSize(sf::Vector2f(40.0f, 40.0f));
	sprite.setPosition(sf::Vector2f(650.0f, 300.0f));
	sprite.setTexture(texture);
	inventory.push_back(std::make_unique<Weapon>("TestWeapon", 10, 2, 3));
	inventory.push_back(std::make_unique<Weapon>("TestWeapon", 5, 5, 1));
}

void Character::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

void Character::takeDamage(int amount)
{
	hp -= amount;
}

void Character::useWeapon(int weaponIndex, Character& target)
{
	target.takeDamage(inventory[weaponIndex]->getDamage());
	takeDamage(inventory[weaponIndex]->getRepercussion());
	std::cout << "player deals " << inventory[weaponIndex]->getDamage() << "and takes " << inventory[weaponIndex]->getRepercussion() << "\n";
}

bool Character::checkIfDead()
{
	if (hp <= 0)
	{
		return true;
	}
	return false;
}

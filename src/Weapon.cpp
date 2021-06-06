#pragma once
#include "Weapon.h"

//Constructors
Weapon::Weapon(const std::string& name, int damage, int repercussion, int cost, sf::Texture* texture):
	name(name), damage(damage), repercussion(repercussion), actionCost(cost), weaponTexture(texture)
{
}

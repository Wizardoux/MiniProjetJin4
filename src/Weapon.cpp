#pragma once
#include "Weapon.h"

Weapon::Weapon(const std::string& name, int damage, int repercussion, int cost):
	name(name), damage(damage), repercussion(repercussion), actionCost(cost)
{
}

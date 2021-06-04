#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Weapon.h"

class Character
{
private:
	int hp = 20;

protected:
	sf::RectangleShape sprite;
	std::vector<std::unique_ptr<Weapon>> inventory;

public:
	Character(const sf::Texture* texture);
	virtual ~Character() = default;

	// Functions
	void render(sf::RenderTarget& target);
	void takeDamage(int amount);
	void useWeapon(int weaponIndex, Character& target);
	bool checkIfDead();
	int getHp() const { return hp; }
};
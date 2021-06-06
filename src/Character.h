#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Weapon.h"

class Character
{
	//Variables
private:
	int hp = 40;

protected:
	sf::RectangleShape sprite;
	std::vector<std::shared_ptr<Weapon>> inventory;

public:
	//Constructors/Destructor
	Character(const sf::Texture* texture);
	virtual ~Character() = default;

	//Others Functions
	void render(sf::RenderTarget& target) const;
	void takeDamage(int amount);
	void useWeapon(int weaponIndex, Character& target);
	bool checkIfDead() const;
	void addWeapon(Weapon weapon);

	//Getter
	int getHp() const { return hp; }
	std::vector<std::shared_ptr<Weapon>> getWeapon() { return inventory; }
};
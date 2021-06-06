#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class Weapon
{
private:
	//Variables
	std::string name;
	std::string description;
	int damage;
	int repercussion;
	int actionCost;
	sf::Texture* weaponTexture;

public:
	//Constructors/Destructors
	Weapon(const std::string& name, int damage, int repercussion, int cost, sf::Texture* texture);
	virtual ~Weapon() = default;

	//Getter
	int getDamage() const { return damage; }
	int getCost() const { return actionCost; }
	int getRepercussion() const { return repercussion; }
	std::string getName() const { return name; }
	sf::Texture* getTexture() { return weaponTexture; }
};
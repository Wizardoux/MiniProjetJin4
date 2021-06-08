#pragma once
#include "Button.h"
#include "Weapon.h"

class WeaponButton final : protected Button
{
private:
	sf::RectangleShape weaponSprite;

public:
	// Constructor/Destructor
	WeaponButton(sf::Vector2f position, const sf::Font* font, const sf::Texture* texture, std::shared_ptr<Weapon> weapon);
	~WeaponButton() = default;

	//Others Functions
	using Button :: checkMouseOver;
	void render(sf::RenderTarget& target) const;
};
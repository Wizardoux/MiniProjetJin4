#pragma once
#include "Button.h"
#include "Weapon.h"

class WeaponButton : public Button
{
private:
	sf::RectangleShape weaponSprite;

public:
	// Constructor/Destructor
	WeaponButton(sf::Vector2f position, const sf::Font* font, const sf::Texture* texture, std::shared_ptr<Weapon> weapon);
	virtual ~WeaponButton() = default;

	//Others Functions
	void render(sf::RenderTarget& target) override;
};
#include "WeaponButton.h"

WeaponButton::WeaponButton(sf::Vector2f position, const sf::Font* font, const sf::Texture* texture, std::shared_ptr<Weapon> weapon):
	Button(position, font, "tmp", texture)
{
	//Bigger than a classic button
	sprite.setSize(sf::Vector2f(280, 70));
	//change the text with the name of the weapon
	buttonText.setString(weapon->getName());
	weaponSprite.setPosition(position + sf::Vector2f(200, 10));
	weaponSprite.setSize(sf::Vector2f(50, 50));
	weaponSprite.setTexture(weapon->getTexture());
}

void WeaponButton::render(sf::RenderTarget& target)
{
	Button::render(target);
	target.draw(weaponSprite);
}

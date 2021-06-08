#include "WeaponButton.h"

WeaponButton::WeaponButton(sf::Vector2f position, const sf::Font* font, const sf::Texture* texture, std::shared_ptr<Weapon> weapon):
	Button(position, font, "tmp", texture)
{
	//Bigger than a classic button
	sprite.setSize(sf::Vector2f(280, 70));
	//More text on this button
	buttonText.setCharacterSize(22);
	//change the text with the name of the weapon
	buttonText.setString(std::to_string(weapon->getCost()) + " : " + weapon->getName());
	weaponSprite.setPosition(position + sf::Vector2f(215, 10));
	weaponSprite.setSize(sf::Vector2f(50, 50));
	weaponSprite.setTexture(weapon->getTexture());
}

void WeaponButton::render(sf::RenderTarget& target) const
{
	Button::render(target);
	target.draw(weaponSprite);
}

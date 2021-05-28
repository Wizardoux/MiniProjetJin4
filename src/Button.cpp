#include "Button.h"

Button::Button(sf::Vector2f position, const sf::Font& font, const std::string& text)
{
	// init the button background
	sprite.setSize(sf::Vector2f(100, 50));
	sprite.setPosition(position);
	sprite.setFillColor(sf::Color::Black);
	//init the text
	buttonText.setFont(font);
	buttonText.setString(text);
	buttonText.setCharacterSize(12);
	buttonText.setFillColor(sf::Color::White);
	// text on the center of the button
	buttonText.setPosition(
		sprite.getPosition().x / 2.0f - buttonText.getGlobalBounds().width / 2.0f,
		sprite.getPosition().y / 2.0f - buttonText.getGlobalBounds().height / 2.0f);
};

bool Button::checkMouseOver(const sf::Vector2f& mousePos)
{
	if (sprite.getGlobalBounds().contains(mousePos))
	{
		return true;
	}
	return false;
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}
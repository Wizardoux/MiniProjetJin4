#include "Button.h"

Button::Button(sf::Vector2f position, const sf::Font& font, const std::string& text)
{
	// init the button background
	sprite.setSize(sf::Vector2f(100, 50));
	sprite.setPosition(position);
	sprite.setFillColor(sf::Color::Magenta);
	//init the text
	buttonText.setFont(font);
	buttonText.setString(text);
	buttonText.setCharacterSize(20);
	buttonText.setFillColor(sf::Color::Black);
	// text on the center of the button
	buttonText.setPosition(
		sprite.getPosition().x - buttonText.getGlobalBounds().width / 2.0f + sprite.getGlobalBounds().width / 2.0f,
		sprite.getPosition().y - buttonText.getGlobalBounds().height / 2.0f + sprite.getGlobalBounds().height / 2.0f);
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
	//target.draw(buttonText);
}
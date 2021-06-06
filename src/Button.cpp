#include "Button.h"

//Constructor
Button::Button(sf::Vector2f position, const sf::Font* font, const std::string& text, const sf::Texture* texture)
{
	// init the button background
	sprite.setSize(sf::Vector2f(180, 70));
	sprite.setPosition(position);
	sprite.setTexture(texture);
	//init the text
	buttonText.setFont(*font);
	buttonText.setString(text);
	buttonText.setCharacterSize(25);
	buttonText.setFillColor(sf::Color::White);
	// text on the center of the button
	centerText();
};

//Others Functions
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
	target.draw(buttonText);
}

void Button::centerText()
{
	buttonText.setPosition(
		sprite.getPosition().x - buttonText.getGlobalBounds().width / 2.0f + sprite.getGlobalBounds().width / 2.0f,
		sprite.getPosition().y - buttonText.getGlobalBounds().height / 2.0f + sprite.getGlobalBounds().height / 2.0f);
}

//Setter
void Button::setText(std::string& text)
{
	buttonText.setString(text);
	centerText();
}

void Button::setSize(sf::Vector2f size)
{
	sprite.setSize(size);
	centerText();
}

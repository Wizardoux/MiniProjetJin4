#include "Player.h"

Player::Player(sf::Vector2f pos)
{
	sprite.setSize(sf::Vector2f(50.0f, 50.0f));
	sprite.setPosition(pos);
	sprite.setFillColor(sf::Color::Red);
}

void Player::moveFrwd()
{
	if (indexRoom < 4)
	{
		sprite.move(60, 0);
		indexRoom++;
	}
}

void Player::moveBack()
{
	if (indexRoom > 0)
	{
		sprite.move(-60, 0);
		indexRoom--;
	}
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

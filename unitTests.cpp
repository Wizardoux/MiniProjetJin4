#pragma once
#include <gtest/gtest.h>
#include "Player.h"
#include "RessourceManager.h"

TEST(TestWeapon, TestBase) {
	const sf::Texture texture;
	Player player(sf::Vector2f(0,0), &texture);
	EXPECT_EQ(player.getWeapon().size(), 0);
}

TEST(TestState, TestBase) {

	const sf::Texture texture;
	Player player(sf::Vector2f(0, 0), &texture);
	EXPECT_EQ(player.getWeapon().size(), 0);
}

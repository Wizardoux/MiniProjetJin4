#pragma once
#include <gtest/gtest.h>
#include "Player.h"
#include "Button.h"
#include "Room.h"
#include "Weapon.h"
#include <string>
#include <../JSON/json.hpp>

using json = nlohmann::json;

//Test the working of the buttons
TEST(TestButton, TestBase) {
	sf::Font font;
	sf::Texture texture;
	Button button(sf::Vector2f(0, 0), &font, "text", &texture);
	EXPECT_EQ(button.checkMouseOver(sf::Vector2f(50, 20)), true); //click on the button
	EXPECT_EQ(button.checkMouseOver(sf::Vector2f(500, 400)), false); //click next to the button
}

//Test the working of the rooms
TEST(TestRoom, TestBase) {
	sf::Texture texture;
	Room testRoom(sf::Vector2f(0, 0), &texture, &texture);
	EXPECT_EQ(testRoom.enterRoom(), 1); //ennemy in the room
	EXPECT_EQ(testRoom.enterRoom(), 0); //empty room
	testRoom.setFlag(&texture);
	EXPECT_EQ(testRoom.enterRoom(), 2); //flag in the room 
}

//Combat System test
TEST(TestCombat, TestBase) {
	sf::Texture texture;
	Weapon testWeapon("testWeapon", 10, 5, 5, &texture);
	Character ennemy(&texture);
	Player player(sf::Vector2f(0, 0), &texture);
	EXPECT_EQ(player.getWeapon().size(), 0);
	ennemy.addWeapon(testWeapon);
	player.addWeapon(testWeapon);
	EXPECT_EQ(player.getWeapon().size(), 1); //check inventory of the player
	EXPECT_EQ(player.tryUseWeapon(0, ennemy), true); //check the player can use testWeapon
	EXPECT_EQ(ennemy.getHp(), 10); //check it hurts ennemy
	EXPECT_EQ(ennemy.checkIfDead(), false); //check if ennemy is still alive
	EXPECT_EQ(player.tryUseWeapon(0, ennemy), false); //check the player can't use testWeapon any longer
	//ennemy turn
	player.increaseActionPoints();
	ennemy.useWeapon(0, player);
	EXPECT_EQ(player.getHp(), 5); //check player's Hp
	EXPECT_EQ(player.tryUseWeapon(0, ennemy), true);
	EXPECT_EQ(ennemy.checkIfDead(), true); //check the ennemy is dead
}

//Json test
TEST(TestJson, TestBase) {
	//Define json string
	auto j = R"(
  {
	"weapons": [
		{
		"name": "testJson1",
		"Damage": 1,
		"Repercussion": 2,
		"Cost":3,
		"Texture": "test1.png"
		},
		{
		"name": "testJson2",
		"Damage": 4,
		"Repercussion": 5,
		"Cost":6,
		"Texture": "test2.png"
		}
	]
  }
)"_json;
	//Check stats of weapons
	//weapon1
	EXPECT_EQ(j["weapons"][0]["name"], "testJson1");
	EXPECT_EQ(j["weapons"][0]["Damage"], 1);
	EXPECT_EQ(j["weapons"][0]["Repercussion"], 2);
	EXPECT_EQ(j["weapons"][0]["Cost"], 3);
	EXPECT_EQ(j["weapons"][0]["Texture"], "test1.png");
	//weapon2
	EXPECT_EQ(j["weapons"][1]["name"], "testJson2");
	EXPECT_EQ(j["weapons"][1]["Damage"], 4);
	EXPECT_EQ(j["weapons"][1]["Repercussion"], 5);
	EXPECT_EQ(j["weapons"][1]["Cost"], 6);
	EXPECT_EQ(j["weapons"][1]["Texture"], "test2.png");
}


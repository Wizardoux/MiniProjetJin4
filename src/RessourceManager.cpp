#include "RessourceManager.h"
#include <iostream>
#include <random>
#include <../JSON/json.hpp>
#include <fstream>
#include <string>
#include "Weapon.h"

using json = nlohmann::json;

RessourceManager::RessourceManager()
{
	initTextures();
	initSounds();
	initWeapons();
}

void RessourceManager::initWeapons()
{
	std::ifstream read("../../resources/Weapon.json");
	json j;
	read >> j;
	int size = j["weapons"].size();
	for (int k = 0; k < size; k++) {
		std::string filename = j["weapons"][k]["Texture"];
		Weaponstextures.push_back(std::make_unique<sf::Texture>());
		Weaponstextures.back()->loadFromFile(filename);
		weapons.emplace_back(Weapon(j["weapons"][k]["name"], j["weapons"][k]["Damage"], j["weapons"][k]["Repercussion"], j["weapons"][k]["Cost"],
			&*Weaponstextures.back()));
		std::cout << filename;

	}
}

void RessourceManager::initTextures()
{
	gameFont.loadFromFile("Thirteen-Pixel-Fonts.ttf");
	roomTexture.loadFromFile("room.png");
	flagTexture.loadFromFile("flag.png");
	textboxTexture.loadFromFile("textbox.png");
	spaceshipTexture.loadFromFile("spaceship.png");
	playerTexture.loadFromFile("player.png");
	ennemyTexture.loadFromFile("spacemarine.png");
	buttonTexture.loadFromFile("buttonsci-fi.png");
	interiorTexture.loadFromFile("interior.png");
	menuTexture.loadFromFile("menu.png");
	vaccinTexture.loadFromFile("vaccin.png");
	blasterTexture.loadFromFile("blaster.png");
	sniperTexture.loadFromFile("sniper.png");
	grenadeTexture.loadFromFile("grenade.png");
}

void RessourceManager::initSounds()
{
	menuMusic.openFromFile("MARiAN - Retro Sci Fi.wav");
	menuMusic.setLoop(true);
	gameMusic.openFromFile("Sci-Fi Technology.wav");
	gameMusic.setLoop(true);
	SFXbuffer.loadFromFile("blaster.wav");
	SFXsound.setBuffer(SFXbuffer);
}

Weapon RessourceManager::getRandomWeapon()
{
	//Return a random
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, weapons.size() - 1); // define the range
	int randomIndex = distr(gen);
	return weapons[randomIndex];
}


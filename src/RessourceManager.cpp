#include "RessourceManager.h"
#include <iostream>
#include <random>

RessourceManager::RessourceManager()
{
	initTextures();
	initSounds();
	initWeapons();
}

void RessourceManager::initWeapons()
{
	weapons.emplace_back(Weapon("Blaster", 5, 1, 2, &blasterTexture));
	weapons.emplace_back(Weapon("Sniper", 20, 0, 6, &sniperTexture));
	weapons.emplace_back(Weapon("vaccin", 0, -10, 4, &vaccinTexture));
	weapons.emplace_back(Weapon("grenade", 10, 10, 1, &grenadeTexture));
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


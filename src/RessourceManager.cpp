#include "RessourceManager.h"

using json = nlohmann::json;

RessourceManager::RessourceManager()
{
	initTextures();
	initSounds();
	initWeapons();
}

void RessourceManager::initWeapons()
{
	std::ifstream read("../../resources/Weapon.json");	//Open Json file
	json j;	//Create json
	read >> j;	//Read Json file
	for (auto weapon : j["weapons"])
	{
		std::string filename = weapon["Texture"]; //Find file texture name
		Weaponstextures.push_back(std::make_unique<sf::Texture>());	//Add the texture to the vector
		Weaponstextures.back()->loadFromFile("../../resources/" + filename);
		weapons.emplace_back(weapon["name"],weapon["Damage"],weapon["Repercussion"],
		weapon["Cost"],&*Weaponstextures.back()); //Add a weapon with json stats in the vector
	}
}

void RessourceManager::initTextures()
{
	gameFont.loadFromFile("../../resources/Thirteen-Pixel-Fonts.ttf");
	roomTexture.loadFromFile("../../resources/room.png");
	flagTexture.loadFromFile("../../resources/flag.png");
	textboxTexture.loadFromFile("../../resources/textbox.png");
	spaceshipTexture.loadFromFile("../../resources/spaceship.png");
	playerTexture.loadFromFile("../../resources/player.png");
	ennemyTexture.loadFromFile("../../resources/spacemarine.png");
	buttonTexture.loadFromFile("../../resources/buttonsci-fi.png");
	interiorTexture.loadFromFile("../../resources/interior.png");
	menuTexture.loadFromFile("../../resources/menu.png");
}

void RessourceManager::initSounds()
{
	menuMusic.openFromFile("../../resources/MARiAN - Retro Sci Fi.wav");
	menuMusic.setLoop(true);
	gameMusic.openFromFile("../../resources/Sci-Fi Technology.wav");
	gameMusic.setLoop(true);
	SFXbuffer.loadFromFile("../../resources/blaster.wav");
	SFXsound.setBuffer(SFXbuffer);
}

Weapon RessourceManager::getRandomWeapon()
{
	//Return a random weapon
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, weapons.size() - 1); // define the range
	int randomIndex = distr(gen);
	return weapons[randomIndex];
}


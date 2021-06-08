#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Weapon.h"
#include <random>
#include <../JSON/json.hpp>
#include <fstream>
#include <string>

class RessourceManager
{
private:
	//Textures
	sf::Font gameFont;
	sf::Texture playerTexture;
	sf::Texture ennemyTexture;
	sf::Texture buttonTexture;
	sf::Texture roomTexture;
	sf::Texture menuTexture;
	sf::Texture interiorTexture;
	sf::Texture spaceshipTexture;
	sf::Texture flagTexture;
	sf::Texture textboxTexture;
	std::vector < std::unique_ptr <sf::Texture>> Weaponstextures;

	//Sounds
	sf::Music menuMusic;
	sf::Music gameMusic;
	sf::SoundBuffer SFXbuffer;
	sf::Sound SFXsound;

	//Weapons DataBase
	std::vector<Weapon> weapons;

public:
	//Constructors/Destructors
	RessourceManager();
	virtual ~RessourceManager() = default;

	//InitFunction
	void initWeapons();
	void initTextures();
	void initSounds();

	//Getter
	sf::Font* getFont() { return &gameFont; }
	sf::Texture* getPlayerTexture() { return &playerTexture; }
	sf::Texture* getEnnemyTexture() { return &ennemyTexture; }
	sf::Texture* getButtonTexture() { return &buttonTexture; }
	sf::Texture* getRoomTexture() { return &roomTexture; }
	sf::Texture* getInteriorTexture() { return &interiorTexture; }
	sf::Texture* getMenuTexture() { return &menuTexture; }
	sf::Texture* getSpaceshipTexture() { return &spaceshipTexture; }
	sf::Texture* getFlagTexture() { return &flagTexture; }
	sf::Texture* getTextboxTexture() { return &textboxTexture; }
	//Weapon Getter
	Weapon getRandomWeapon() const;

	//Sounds Functions
	void playMenuMusic() { menuMusic.play(); }
	void playGameMusic() { gameMusic.play(); }
	void stopMenuMusic() { menuMusic.stop(); }
	void stopGameMusic() { gameMusic.stop(); }
	void playBlaster() { SFXsound.play(); }
};


#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

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

	//Sounds
	sf::Music menuMusic;
	sf::Music gameMusic;
	sf::SoundBuffer SFXbuffer;
	sf::Sound SFXsound;

public:
	//Constructors/Destructors
	RessourceManager();
	virtual ~RessourceManager() = default;

	//Getter
	sf::Font* getFont() { return &gameFont; }
	sf::Texture* getPlayerTexture() { return &playerTexture; }
	sf::Texture* getEnnemyTexture() { return &ennemyTexture; }
	sf::Texture* getButtonTexture() { return &buttonTexture; }
	sf::Texture* getRoomTexture() { return &roomTexture; }
	sf::Texture* getInteriorTexture() { return &interiorTexture; }
	sf::Texture* getMenuTexture() { return &menuTexture; }
	sf::Texture* getspaceshipTexture() { return &spaceshipTexture; }

	//Sounds Functions
	void playMenuMusic();
	void playGameMusic();
	void stopMenuMusic();
	void stopGameMusic();
	void playBlaster();
};


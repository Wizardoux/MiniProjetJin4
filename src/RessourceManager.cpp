#include "RessourceManager.h"
#include <iostream>

RessourceManager::RessourceManager()
{
	if (!gameFont.loadFromFile("Thirteen-Pixel-Fonts.ttf"))
	{
		std::cout<< "Failed to load font";
	}
	if (!roomTexture.loadFromFile("room.png"))
	{
		std::cout << "Failed to load texture";
	}
	if (!spaceshipTexture.loadFromFile("spaceship.png"))
	{
		std::cout << "Failed to load texture";
	}
	if (!playerTexture.loadFromFile("player.png"))
	{
		std::cout << "Failed to load texture";
	}
	if (!ennemyTexture.loadFromFile("spacemarine.png"))
	{
		std::cout << "Failed to load texture";
	}
	if (!buttonTexture.loadFromFile("buttonsci-fi.png"))
	{
		std::cout << "Failed to load texture";
	}
	if (!interiorTexture.loadFromFile("interior.png"))
	{
		std::cout << "Failed to load texture";
	}
	if (!menuTexture.loadFromFile("menu.png"))
	{
		std::cout << "Failed to load texture";
	}
	if (!menuMusic.openFromFile("MARiAN - Retro Sci Fi.wav"))
	{
		std::cout << "Failed to open music";
	}
	if (!gameMusic.openFromFile("Sci-Fi Technology.wav"))
	{
		std::cout << "Failed to open music";
	}
	if (!SFXbuffer.loadFromFile("blaster.wav"))
	{
		std::cout << "Failed to load sound";
	}
	SFXsound.setBuffer(SFXbuffer);
}

void RessourceManager::playMenuMusic()
{
	menuMusic.play();
}

void RessourceManager::playGameMusic()
{
	gameMusic.play();
}

void RessourceManager::stopMenuMusic()
{
	menuMusic.stop();
}

void RessourceManager::stopGameMusic()
{
	gameMusic.stop();
}

void RessourceManager::playBlaster()
{
	SFXsound.play();
}


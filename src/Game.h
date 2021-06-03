#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "State.h"
#include "CombatState.h"
#include "MainMenuState.h"

class Game final
{
private:
	//Variables
	sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(800, 600), "Ruins of Science");
	sf::Event sfEvent;
	std::stack<std::unique_ptr<State>> states;
	sf::Vector2f mousePos;

	//Init
	void initWindow();
	void initStates();

	//Ressources
	RessourceManager ressourceManager;

public:
	//Constructors/Destructors
	Game();
	~Game();

	//Functions
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};


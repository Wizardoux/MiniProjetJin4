#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "State.h"
#include "CombatState.h"
#include "MainMenuState.h"
#include <imgui-SFML.h>
#include <imgui.h>

class Game final
{
private:
	//Variables
	sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(1020, 600), "Ruins of Science");
	sf::Event sfEvent;
	std::stack<std::unique_ptr<State>> states;
	sf::Vector2f mousePos;
	RessourceManager ressourceManager;

	//Init Functions
	void initWindow();
	void initIMGUI();
	void initStates();

	//IMGUI Variables
	sf::RenderWindow ImguiWindow = sf::RenderWindow(sf::VideoMode(600,600), "Console", sf::Style::Titlebar);
	sf::Clock deltaClock;

public:
	//Constructors/Destructors
	Game();
	~Game();

	//Others Functions
	void updateSFMLEvents();
	void update();
	void render();
	void run();

	//Imgui Functions
	void updateIMGUI();
	void renderIMGUI();
};


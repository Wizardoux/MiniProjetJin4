#include "Game.h"
#include <cassert>

//Init Functions
void Game::initWindow()
{
    window.setFramerateLimit(60);
}

void Game::initStates()
{
    //The first state is the menu state
    states.push(std::make_unique<MainMenuState>(&ressourceManager, &states));
}

//Constructors/Destructors
Game::Game()
{
    initWindow();
    initStates();
}

Game::~Game()
{
    //Remove all the states of the stack
    while (!states.empty())
    {
        states.top()->endState();
        states.top().reset();
        states.pop();
    }
    assert(states.empty());
}

//Functions
void Game::updateSFMLEvents()
{
    //Check if SFML events happended
    while (window.pollEvent(sfEvent))
    {
        //Check the type of the event...
        switch (sfEvent.type)
        {
            //Window closed
        case sf::Event::Closed:
            window.close();
            break;
            //Key pressed
        case sf::Event::KeyPressed:
            if (!states.empty())
            {
                states.top()->checkKeyInput(sfEvent);
            }
            break;
            //Mouse button pressed
        case sf::Event::MouseButtonPressed:
            if (!states.empty())
            {
                states.top()->checkMouseInput(sfEvent, mousePos);
            }
            break;
            //We don't process other types of events
        default:
            break;
        }
    }
}

void Game::update()
{
    //Check the SFML events
    updateSFMLEvents();
    //Update the position of the mouse
    mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    //Update the current screen, that is to say the top state
    if (!states.empty())
    {
        states.top()->update();
        if (states.top()->getQuit())
        {
            states.top()->endState();
            states.top().reset();
            states.pop();
        }
    }
    //Application End
    else
    {
        window.close();
    }
}

void Game::render()
{
    //Clear the window
    window.clear();
    //Render the current screen, that is to say the top state
    if (!states.empty())
    {
        states.top()->render(window);
    }
    window.display();
}

void Game::run()
{
    while (window.isOpen())
    {
        update();
        render();
    }
}

#include "Game.h"
#include <cassert>

//Init
void Game::initWindow()
{
    window.setFramerateLimit(60);
}

void Game::initStates()
{
    states.push(std::make_unique<MainMenuState>());
    states.push(std::make_unique<CombatState>());
}

//Constructors/Destructors
Game::Game()
{
    initWindow();
    initStates();
    gameFont.loadFromFile("Thirteen-Pixel-Fonts.ttf");
}

Game::~Game()
{
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
    while (window.pollEvent(sfEvent))
    {
        // check the type of the event...
        switch (sfEvent.type)
        {
            // window closed
        case sf::Event::Closed:
            window.close();
            break;
            // key pressed
        case sf::Event::KeyPressed:
            if (!states.empty())
            {
                states.top()->checkKeyInput(sfEvent);
            }
            break;
            // we don't process other types of events
        default:
            break;
        }
    }
}

void Game::update()
{
    //check the SFML events
    updateSFMLEvents();
    //update the position of the mouse
    mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    // update the current screen, that is to say the top state
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
    window.clear();
    // render the current screen, that is to say the top state
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

#include "State.h"

void State::exitState()
{
	quit = true;
}

State::State(RessourceManager* manager, std::stack<std::unique_ptr<State>>* states) :
	ressourceManager(manager),
	states(states)
{
}

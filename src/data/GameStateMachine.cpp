#include "../../src/data/GameStateMachine.h"

GameStateMachine::GameStateMachine()
{

}

GameStateMachine::~GameStateMachine()
{
	while (!states.empty())
		removeState();
}

GameState* GameStateMachine::currentState()
{
	if (states.empty())
		return nullptr;
	else
		return states.back();
}

void GameStateMachine::processStateChange()
{
	// Remove if true and if states isnt empty
	if (isRemoving && !(states.empty()))
	{
		delete states.back();
		states.pop_back();

		isRemoving = false;
	}

	if (isAdding)
	{
		// Cant replace nothing
		if (isReplacing && !(states.empty()))
		{
			delete states.back();
			states.erase(states.end(), states.end());
			if (tempAddingState != nullptr)
			{
				states.back() = tempAddingState;
				tempAddingState = nullptr;
			}
			isReplacing = false;
		}
		else
		{
			if (tempAddingState != nullptr)
			{
				states.push_back(tempAddingState);
				tempAddingState = nullptr;
			}
		}

		isAdding = false;
	}
}

void GameStateMachine::addState(GameState* state, bool isReplacing)
{
	this->isAdding = true;
	this->isReplacing = isReplacing;

	this->tempAddingState = state;
}

void GameStateMachine::removeState()
{
	this->isRemoving = true;
}
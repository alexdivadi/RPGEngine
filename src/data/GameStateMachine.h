#pragma once

#include <vector>

#include "../../src/states/GameState.h"

class GameStateMachine
{
public:
	std::vector<GameState*> states;
	GameState* tempAddingState;

	bool isAdding;
	bool isRemoving;
	bool isReplacing;

public:
	GameStateMachine();
	~GameStateMachine();

	/*
	Name: Process State Change
	Purpose: Checks every iteration of the Game Loop to see if any state is queued to be added or deleted from the Game States container and executes it
	Parameters: None
	Returns: void
	*/
	void processStateChange();

	/*
	Name: Add State
	Purpose: To queue the addition of a new gamestate to the top of the states container, capable of replacing current top state
	Parameters: Pointer to next game state, bool whether you want to replace current top state
	Returns: void
	*/
	void addState(GameState* state, bool isReplacing);

	/*
	Name: Remove State
	Purpose: To queue the remove topmost gamestate
	Parameters: None
	Returns: void
	*/
	void removeState();

	/*
	Name: Current State
	Purpose: Returns the topmost state of the states container
	Parameters: None
	Returns: pointer to top/back() gamestate of states
	*/
	GameState* currentState();
};
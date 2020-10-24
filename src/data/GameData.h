#pragma once

#include "../../src/data/GameStateMachine.h"
#include "../../src/data/ResourceManager.h"

class GameData
{
public:
	GameStateMachine stateMachine;
	ResourceManager assets;
	//InputManager

public:
	GameData() {};
	~GameData() {};
};
#pragma once

#include <SFML/Graphics.hpp>

#include <stdio.h>
#include <string>
#include <fstream>

class Map
{
private:
	int* m_indicies;
	bool* m_solids;

public:
	int nWidth;
	int nHeight;
	std::string sName;
	sf::Sprite* pSprite;

public:
	Map();
	~Map();

	int GetIndex(int x, int y);
	bool GetSolid(int x, int y);

	/*
	Name: Create
	Purpose: loads tile # and collision for each tile from file
	Input: string literal Filename, string literal level_name
	Returns: bool succesful?
	*/
	bool Create(const std::string& fileName, const std::string& name, sf::Sprite* sprite);
};
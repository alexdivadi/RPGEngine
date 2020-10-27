#pragma once

#include <SFML/Graphics.hpp>

#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>

class Map
{
private:
	//int* m_indicies; 
	std::vector<int> m_indicies;
	//bool* m_solids; 
	std::vector<bool> m_solids;

public:
	int nWidth;
	int nHeight;
	std::string sName;

public:
	Map();
	~Map();

	int getIndex(int x, int y);
	bool getSolid(int x, int y);

	/*
	Name: Create
	Purpose: loads tile # and collision for each tile from file
	Input: string literal Filename, string literal level_name
	Returns: bool succesful?
	*/
	bool create(const std::string& fileName, const std::string& name);
};
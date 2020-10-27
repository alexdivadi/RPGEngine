#include "../../src/worlds/Map.h"

Map::Map()
{
	nHeight = 0;
	nWidth = 0;
	sName = "";
}

int Map::getIndex(int x, int y)
{
	if (x >= 0 && x < nWidth && y >= 0 && y < nHeight)
		return m_indicies[x + y * nWidth];
	else
		return 0;
}

bool Map::getSolid(int x, int y)
{
	if (x >= 0 && x < nWidth * 16 && y >= 0 && y < nHeight * 16)
		return m_solids[x + y * nWidth];
	else
		return 0;
}

bool Map::create(const std::string& fileName, const std::string& name)
{
	int temp_i;
	bool temp_s;
	sName = name;
	std::ifstream data(fileName, std::ios::in | std::ios::binary);
	if (data.is_open())
	{
		data >> nWidth >> nHeight;

		for (int i = 0; i < nWidth * nHeight; i++)
		{
			data >> temp_i;
			data >> temp_s;
			m_indicies.push_back(temp_i);
			m_solids.push_back(temp_s);
		}
		return true;
	}
	return false;
}

Map::~Map()
{
	//if (m_indicies != nullptr)
		//delete m_indicies;
	//if (m_solids != nullptr)
		//delete m_solids;
}


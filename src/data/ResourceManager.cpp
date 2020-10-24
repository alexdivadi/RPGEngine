#include "../../src/data/ResourceManager.h"

#include "../../src/constants/Constants.h"

#include <iostream>

ResourceManager::ResourceManager()
{
	// passing empty string because these assets excist independant of any state
	addFont("default", "framd.ttf", "");
	addTexture("default", "Presidential.png", "");
	addSong("default", "On_The_Ranch.flac", "");
}

ResourceManager::~ResourceManager()
{

}

void ResourceManager::addFont(const std::string& fontName, const std::string& fileName, const std::string& stateName)
{
	if (fonts.find(stateName + fontName) == fonts.end())
	{
		std::unique_ptr<sf::Font> f = std::make_unique<sf::Font>();

		if (!f->loadFromFile(FONTS_FILE_ADDRESS + fileName))
			std::cerr << "Error loading font \"" << fileName << "\"\n";
		else
			fonts.insert(std::make_pair(stateName + fontName, std::move(f)));
	}
	else
		std::cerr << "Font \"" << stateName + fontName << "\" already exists\n";
}

sf::Font* ResourceManager::loadFont(const std::string& fontName, const std::string& stateName)
{
	if (fonts[stateName + fontName] != nullptr)
		return fonts[stateName + fontName].get();

	else if (fonts.find(stateName + fontName) == fonts.end())
		std::cerr << "Error: font \"" << fontName << "\" not found\n";
	else
		std::cerr << "\"" << fontName << "\" pointing to nullptr\n";
	return fonts["default"].get();
}

void ResourceManager::clearFonts(const std::string& stateName)
{
	for (auto it = fonts.begin(); it != fonts.end(); )
		if (it->first.find(stateName) == 0)
		{
			std::cout << "deleting \"" << it->first << "\" (" << it->second << ")\n";
			it = fonts.erase(it);
		}
		else
			++it;
}

void ResourceManager::addTexture(const std::string& textureName, const std::string& fileName, const std::string& stateName)
{
	if (textures.find(stateName + textureName) == textures.end())
	{
		std::unique_ptr<sf::Texture> t = std::make_unique<sf::Texture>();

		if (!t->loadFromFile(TEXTURES_FILE_ADDRESS + fileName))
			std::cerr << "Error loading texture \"" << fileName << "\"\n";
		else
			textures.insert(std::make_pair(stateName + textureName, std::move(t)));
	}
	else
		std::cerr << "Texture \"" << stateName + textureName << "\" already exists\n";
}

sf::Texture* ResourceManager::loadTexture(const std::string& textureName, const std::string& stateName)
{
	if (textures[stateName + textureName] != nullptr)
		return textures[stateName + textureName].get();

	else if (textures.find(stateName + textureName) == textures.end())
		std::cerr << "Error: font \"" << textureName << "\" not found\n";
	else
		std::cerr << "\"" << textureName << "\" pointing to nullptr\n";
	return textures["default"].get();
}

void ResourceManager::clearTextures(const std::string& stateName)
{
	for (auto it = textures.begin(); it != textures.end(); )
        if (it->first.find(stateName) == 0)
        {
			std::cout << "deleting \"" << it->first << "\" (" << it->second << ")\n";
			it = textures.erase(it);
		}
		else
			++it;
}

void ResourceManager::addSong(const std::string& songName, const std::string& fileName, const std::string& stateName)
{
	if (songs.find(stateName + songName) == songs.end())
	{
		std::unique_ptr<sf::Music> m = std::make_unique<sf::Music>();

		if (!m->openFromFile(MUSIC_FILE_ADDRESS + fileName))
			std::cerr << "Error loading texture \"" << fileName << "\"\n";
		else
			songs.insert(std::make_pair(stateName + songName, std::move(m)));
	}
	else
		std::cerr << "Song \"" << stateName + songName << "\" already exists\n";
}

sf::Music* ResourceManager::loadSong(const std::string& songName, const std::string& stateName)
{
	if (songs[stateName + songName] != nullptr)
		return songs[stateName + songName].get();

	else if (songs.find(stateName + songName) == songs.end())
		std::cerr << "Error: font \"" << songName << "\" not found\n";
	else
		std::cerr << "\"" << songName << "\" pointing to nullptr\n";
	return songs["default"].get();
}

void ResourceManager::clearSongs(const std::string& stateName)
{
	for (auto it = songs.begin(); it != songs.end(); )
		if (it->first.find(stateName) == 0)
		{
			std::cout << "deleting \"" << it->first << "\" (" << it->second << ")\n";
			it = songs.erase(it);
		}
		else
			++it;
}

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <memory>
#include <string>
#include <unordered_map>

class ResourceManager
{
public:
	std::unordered_map<std::string, std::unique_ptr<sf::Font>> fonts;
	std::unordered_map<std::string, std::unique_ptr<sf::Texture>> textures;
	std::unordered_map<std::string, std::unique_ptr<sf::Music>> songs;

public:
	ResourceManager();
	~ResourceManager();

	/*
	Name: Add Font/Texture/Song
	Purpose: Loads media from file under a given name into the medias respective type of unordered map
	Parameters: Name of media, file addess, name of current state to know what state is associated with this resource
	Returns: void
	*/
	void addFont(const std::string& fontName, const std::string& fileName, const std::string& stateName);
	/*
	Name: Add Font/Texture/Song
	Purpose: Loads media from file under a given name into the medias respective type of unordered map
	Parameters: Name of media, file addess, name of current state to know what state is associated with this resource
	Returns: void
	*/
	sf::Font* loadFont(const std::string& fontName, const std::string& stateName);
	void clearFonts(const std::string& stateName);

	void addTexture(const std::string& textureName, const std::string& fileName, const std::string& stateName);
	sf::Texture* loadTexture(const std::string& textureName, const std::string& stateName);
	void clearTextures(const std::string& stateName);

	void addSong(const std::string& songName, const std::string& fileName, const std::string& stateName);
	sf::Music* loadSong(const std::string& songName, const std::string& stateName);
	void clearSongs(const std::string& stateName);
};
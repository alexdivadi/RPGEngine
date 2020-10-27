#pragma once

#include <string>

constexpr int WINDOW_WIDTH{ 800 };
constexpr int WINDOW_HEIGHT{ 600 };

const std::string RES_FILE_ADDRESS{ "res/" };
const std::string FONTS_FILE_ADDRESS{ RES_FILE_ADDRESS + "fonts/" };
const std::string TEXTURES_FILE_ADDRESS{ RES_FILE_ADDRESS + "textures/" };
const std::string MUSIC_FILE_ADDRESS{ RES_FILE_ADDRESS + "music/" };
const std::string WORLD_FILE_ADDRESS{ RES_FILE_ADDRESS + "maps/" };

// seperates button id and text sets
constexpr char BUTTONSET_DELIMITER{ '/' };
// seperates button id from text
constexpr char BUTTON_DELIMITER{ '-' };

// eg:: buttonID1-Button Text/buttonID2-Another Button Text/buttonID3-More Button Text
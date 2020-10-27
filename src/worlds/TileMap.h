#pragma once

#include <SFML/Graphics.hpp>
#include <stdio.h>

#include "../../src/worlds/Map.h"

/*
Code Adapted from SFML vertex array article
*/

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    sf::VertexArray m_vertices;
    sf::Texture* m_tileset;

public:
    /*
    Name: Load
    Purpose: fills Vertex Array with tileset coords based on given map data
    Parameters: SFML Texture, Map current map
    Returns: bool successful
    */
    bool load(sf::Texture* tileset, Map cmap);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

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
    sf::Texture m_tileset;

public:

    /*
    Name: Load
    Purpose: fills Vertex Array with tileset coords based on given map data
    Parameters: SFML Texture, Map current map
    Returns: bool successful
    */
    bool load(sf::Texture& tileset, Map cmap)
    {
        const int scale{ scale };
        m_tileset = tileset;
        // resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(cmap.nWidth * cmap.nHeight * 4);

        for (unsigned int i = 0; i < cmap.nWidth; ++i)
            for (unsigned int j = 0; j < cmap.nHeight; ++j)
            {
                // get the current tile number
                int tileNumber = cmap.GetIndex(i, j);

                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / scale);
                int tv = tileNumber / (m_tileset.getSize().x / scale);

                // get a pointer to the current tile's quad
                sf::Vertex* quad = &m_vertices[(i + j * cmap.nWidth) * 4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(i * scale, j * scale);
                quad[1].position = sf::Vector2f((i + 1) * scale, j * scale);
                quad[2].position = sf::Vector2f((i + 1) * scale, (j + 1) * scale);
                quad[3].position = sf::Vector2f(i * scale, (j + 1) * scale);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * scale, tv * scale);
                quad[1].texCoords = sf::Vector2f((tu + 1) * scale, tv * scale);
                quad[2].texCoords = sf::Vector2f((tu + 1) * scale, (tv + 1) * scale);
                quad[3].texCoords = sf::Vector2f(tu * scale, (tv + 1) * scale);
            }

        return true;
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }
};

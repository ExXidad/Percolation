#include <iostream>
#include "SFML/Graphics.hpp"

void initMazeDraw(const std::vector<std::vector<int>> &maze, sf::RenderWindow &window) {
    sf::Vector2<unsigned int> size = window.getSize();
    double windowWidth = size.x;
    double windowHeight = size.y;

    int lenX = maze.size();
    int lenY = maze[0].size();

    double xTileSize = windowWidth / (lenX);
    double yTileSize = windowHeight / (lenY);

    sf::RectangleShape tile;
    tile.setSize(sf::Vector2f(xTileSize, yTileSize));
    tile.setOutlineThickness(0);

    for (int j = 0; j < lenY; ++j) {
        for (int i = 0; i < lenX; ++i) {
            if (maze[i][j]) {
                tile.setFillColor(sf::Color::White);
            } else {
                tile.setFillColor(sf::Color::Black);
            }

            tile.setPosition(i * xTileSize, j * yTileSize);
            window.draw(tile);
        }
    }
}

void
drawPath(const std::vector<int> &pathX, const std::vector<int> &pathY, sf::RenderWindow &window, int lenX, int lenY) {
    sf::Vector2<unsigned int> size = window.getSize();
    double windowWidth = size.x;
    double windowHeight = size.y;

    int len = pathX.size();

    double xTileSize = windowWidth / (lenX);
    double yTileSize = windowHeight / (lenY);

    sf::CircleShape tile;
    double radius = std::min(xTileSize, yTileSize) / 2 / 1.618;
    tile.setRadius(radius);
    tile.setOutlineThickness(0);
    tile.setFillColor(sf::Color::Red);

    sf::VertexArray lines(sf::LinesStrip, len);

    for (int i = 0; i < len; ++i) {
        lines[i].position  = sf::Vector2f(pathX[i] * xTileSize + xTileSize / 2, pathY[i] * yTileSize + yTileSize / 2);
        lines[i].color = sf::Color::Red;
        tile.setPosition(pathX[i] * xTileSize + xTileSize / 2 - radius, pathY[i] * yTileSize + yTileSize / 2 - radius);
        window.draw(tile);
    }
    window.draw(lines);
}

void keepWindowOpened(sf::RenderWindow &window) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }
    }
}
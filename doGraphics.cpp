#include <iostream>
#include "head.h"


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

void drawPath(const std::vector<int> &pathX, const std::vector<int> &pathY, sf::RenderWindow &window, int lenX, int lenY) {
    sf::Vector2<unsigned int> size = window.getSize();
    double windowWidth = size.x;
    double windowHeight = size.y;

    int len = pathX.size();

    double xTileSize = windowWidth / (lenX);
    double yTileSize = windowHeight / (lenY);

    sf::RectangleShape tile;
    tile.setSize(sf::Vector2f(xTileSize, yTileSize));
    tile.setOutlineThickness(0);
    tile.setFillColor(sf::Color::Red);

    for (int i = 0; i < len; ++i) {
        tile.setPosition(pathX[i] * xTileSize, pathY[i] * yTileSize);
        window.draw(tile);
    }
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
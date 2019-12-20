#include <iostream>
#include "SFML/Graphics.hpp"

void doGraphics(const std::vector<std::vector<int>> &maze) {
    int lenX = maze.size();
    int lenY = maze[0].size();

    double windowWidth = 1000;
    double windowHeight = 1000;

    double xTileSize = windowWidth / (lenX+1);
    double yTileSize = windowHeight / (lenY+1);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Maze",
                            sf::Style::Default, settings);
    window.clear(sf::Color::Red);

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

            tile.setPosition(i * xTileSize + xTileSize / 2, j * yTileSize + yTileSize / 2);
            window.draw(tile);
        }
    }

    window.display();

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
#include <iostream>
#include <utility>
#include "SFML/Graphics.hpp"

typedef std::pair<int, int> intPair;
typedef std::vector<int> intVector;
typedef std::vector<bool> boolVector;
typedef std::vector<std::vector<int>> intMap2D;
typedef std::vector<std::vector<bool>> boolMap2D;
typedef std::vector<intPair> intVectorPair;

void initMazeDraw(const intMap2D &maze, sf::RenderWindow &window) {
    sf::Vector2<unsigned int> size = window.getSize();
    double windowWidth = size.x;
    double windowHeight = size.y;


    double xTileSize = windowWidth/maze[0].size();
    double yTileSize = windowHeight/maze.size();

    sf::RectangleShape tile;
    tile.setSize(sf::Vector2f(xTileSize, yTileSize));
    tile.setOutlineThickness(0);

    for (int j = 0; j < maze.size(); ++j) {
        for (int i = 0; i < maze[0].size(); ++i) {
            if (maze[j][i]) {
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
drawPath(const intVectorPair &path, sf::RenderWindow &window, int lenX, int lenY) {
    sf::Vector2<unsigned int> size = window.getSize();
    double windowWidth = size.x;
    double windowHeight = size.y;

    int len = path.size();

    double xTileSize = windowWidth / (lenX);
    double yTileSize = windowHeight / (lenY);

    sf::CircleShape tile;
    double radius = std::min(xTileSize, yTileSize) / 2 / 1.618;
    tile.setRadius(radius);
    tile.setOutlineThickness(0);
    tile.setFillColor(sf::Color::Red);

    sf::VertexArray lines(sf::LinesStrip, len);

    for (int i = 0; i < len; ++i) {
        lines[i].position = sf::Vector2f(path[i].first * xTileSize + xTileSize / 2,
                                         path[i].second * yTileSize + yTileSize / 2);
        lines[i].color = sf::Color::Red;
        tile.setPosition(path[i].first * xTileSize + xTileSize / 2 - radius,
                         path[i].second * yTileSize + yTileSize / 2 - radius);
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
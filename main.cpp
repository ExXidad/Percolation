#include "head.h"
#include <fstream>
#include <iostream>
#include <vector>



void initMazeDraw(const std::vector<std::vector<int>> &maze, sf::RenderWindow &window);

void keepWindowOpened(sf::RenderWindow &window);


int main() {
    std::string line;
    std::ifstream file("Maze.dat");

    if (file.is_open()) {
        std::cout << "File opened. Maze dimensions are ";
        int lenX, lenY;
        file >> lenX >> lenY;
        std::cout << lenX << "x" << lenY << std::endl;

        std::vector<std::vector<int>> maze(lenX, std::vector<int>(lenY, 0));

        for (int j = 0; j < lenY; ++j) {
            for (int i = 0; i < lenX; ++i) {
                file >> maze[i][j];
            }
        }

        file.close();

        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;
        double windowWidth = 1000;
        double windowHeight = 1000;

        sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Maze",
                                sf::Style::Default, settings);
        window.clear(sf::Color::Red);

        initMazeDraw(maze,window);

















        window.display();

        keepWindowOpened(window);
    }

    else {
        std::cout << "File issue" << std::endl;
    }
    return 0;
}
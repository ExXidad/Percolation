#include "head.h"
#include <fstream>
#include <iostream>
#include <vector>
void doGraphics(const std::vector<std::vector<int>> &maze);


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

        doGraphics(maze);
    }



    return 0;
}
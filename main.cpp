#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include "SFML/Graphics.hpp"
#include "percolation.h"

typedef std::pair<int, int> intPair;
typedef std::vector<int> intVector;
typedef std::vector<bool> boolVector;
typedef std::vector<std::vector<int>> intMap2D;
typedef std::vector<std::vector<bool>> boolMap2D;
typedef std::queue<intPair> intQueuePair;
typedef std::vector<intPair> intVectorPair;

void initMazeDraw(const intMap2D &maze, sf::RenderWindow &window);

void
drawPath(const intVectorPair &path, sf::RenderWindow &window, int lenX, int lenY);

void keepWindowOpened(sf::RenderWindow &window);

void print2D(const std::vector<std::vector<int>> &data) {
    int lenX = data.size();
    int lenY = data[0].size();
    for (int j = 0; j < lenY; ++j) {
        for (int i = 0; i < lenX; ++i) {
            std::cout << data[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

bool pointInMazeQ(int lenX, int lenY, int x, int y) {
    return x < lenX && x >= 0 &&
           y < lenY && y >= 0;
}


int main() {
    int m = 10;
    int n = 5;


    int x0 = 0, y0 = 0;
    //int x1 = 29, y1 = 29;
    int x1 = n - 1, y1 = m + 1;

    mapInt maze = generateMap(m, n, 40);
    std::cout << maze;


    intMap2D dist(m + 2, intVector(n, -1));
    boolMap2D wasVisited(m + 2, boolVector(n, false));

    dist[y0][x0] = 0;
    wasVisited[y0][x0] = true;

    int nextX, nextY;
    int currentX = x0, currentY = y0;

    intQueuePair queue;
    queue.push(intPair(currentX, currentY));

    while (!queue.empty()) {
        currentX = queue.front().first;
        currentY = queue.front().second;

        wasVisited[currentY][currentX] = true;
        for (int j = -1; j <= 1; ++j)
            for (int i = -1; i <= 1; ++i) {
                nextX = currentX + i;
                nextY = currentY + j;
                if (pointInMazeQ(n, m + 2, nextX, nextY) &&
                    maze[nextY][nextX] == 1 &&
                    ((abs(i) == 1) xor (abs(j) == 1))) {

                    //if now visited point -> step in
                    if (!wasVisited[nextY][nextX]) queue.push(intPair(nextX, nextY));

                    if (dist[nextY][nextX] != -1)
                        dist[nextY][nextX] = std::min(dist[currentY][currentX] + 1, dist[nextY][nextX]);
                    else
                        dist[nextY][nextX] = dist[currentY][currentX] + 1;
                }
            }

        queue.pop();
    }

    std::cout << std::endl;
    std::cout << dist;

    if (dist[y1][x1] == -1) std::cout << "End point can't be reached" << std::endl;
    else {
        intVectorPair path{intPair(x1, y1)};
        currentX = x1;
        currentY = y1;
        bool addedToPath;

        while (!((currentX == x0) && (currentY == y0))) {
            addedToPath = false;
            for (int j = -1; j <= 1; ++j) {
                for (int i = -1; i <= 1; ++i) {
                    nextX = currentX + i;
                    nextY = currentY + j;
                    //std::cout << dist[currentY][currentX] << " : " << dist[nextY][nextX] << std::endl;
                    if (pointInMazeQ(n, m + 2, nextX, nextY) &&
                        ((abs(i) == 1) xor (abs(j) == 1)) &&
                        (maze[nextY][nextX] == 1) &&
                        (dist[nextY][nextX] == (dist[currentY][currentX] - 1))) {

                        currentX = nextX;
                        currentY = nextY;

                        path.push_back(intPair(nextX, nextY));

                        addedToPath = true;
                        break;
                    }
                }
                if (addedToPath) { break; }
            }
        }
        //window setup
        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;

        //set window size here
        int windowWidth = 30 * n;
        int windowHeight = 30 * (m + 2);

        sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Maze",
                                sf::Style::Default, settings);
        window.clear(sf::Color::Blue);

        initMazeDraw(maze, window);

        drawPath(path, window, n, m + 2);
        window.display();
        keepWindowOpened(window);
    }


    return 0;
}
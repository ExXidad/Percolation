#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include "SFML/Graphics.hpp"


void initMazeDraw(const std::vector<std::vector<int>> &maze, sf::RenderWindow &window);

void
drawPath(const std::vector<int> &pathX, const std::vector<int> &pathY, sf::RenderWindow &window, int lenX, int lenY);

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
    if (x < lenX && x >= 0 &&
        y < lenY && y >= 0) {
        return 1;
    } else {
        return 0;
    }
}


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

        //print2D(maze);

        //set entrance/exit point
        int x0 = 0, y0 = 0;//x0 = 100, y0 = 3;
        int x1 = 29, y1 = 29; //x1 = 500, y1 = 501;

//        int x0, y0;
//        int x1, y1;
//
//        std::cout << "Enter start point: " << std::endl;
//        std::cin >> x0;
//        std::cin >> y0;
//        std::cout << "Enter exit point: " << std::endl;
//        std::cin >> x1;
//        std::cin >> y1;


        if (!pointInMazeQ(lenX, lenY, x0, y0) || maze[x0][y0] == 0 ||
            !pointInMazeQ(lenX, lenY, x1, y1) || maze[x1][y1] == 0) {
            std::cout << "Wrong enter/exit points" << std::endl;
        } else {
            std::vector<std::vector<int>> dist(lenX, std::vector<int>(lenY, 1000000));
            std::vector<std::vector<bool>> wasVisited(lenX, std::vector<bool>(lenY, false));

            dist[x0][y0] = 0;
            wasVisited[x0][y0] = true;
            int nextX, nextY;
            int currentX = x0, currentY = y0;

            std::queue<int> queueX;
            std::queue<int> queueY;
            queueX.push(currentX);
            queueY.push(currentY);


            while ((!queueX.empty() && !queueY.empty()) || !((currentX == x1) && (currentY == y1))) {
                currentX = queueX.front();
                currentY = queueY.front();
                for (int j = -1; j <= 1; ++j) {
                    for (int i = -1; i <= 1; ++i) {
                        nextX = currentX + i;
                        nextY = currentY + j;
                        if (pointInMazeQ(lenX, lenY, nextX, nextY) &&
                            !wasVisited[nextX][nextY] &&
                            maze[nextX][nextY] == 1 &&
                            ((abs(i) == 1) xor (abs(j) == 1))) {
                            queueX.push(nextX);
                            queueY.push(nextY);
                            wasVisited[nextX][nextY] = true;
                            dist[nextX][nextY] = std::min(dist[currentX][currentY] + 1, dist[nextX][nextY]);
                        }
                    }
                }
                queueX.pop();
                queueY.pop();
            }

//            std::cout << "---------------" << std::endl;
//            print2D(dist);

            if (dist[x1][y1] == 1000000) {
                std::cout << "End point can't be reached" << std::endl;
            } else {
                std::vector<int> pathX{x1};
                std::vector<int> pathY{y1};
                currentX = x1;
                currentY = y1;
                bool addedToPath;

                while (!((currentX == x0) && (currentY == y0))) {
                    addedToPath = false;
                    for (int j = -1; j <= 1; ++j) {
                        for (int i = -1; i <= 1; ++i) {
                            nextX = currentX + i;
                            nextY = currentY + j;
                            if (pointInMazeQ(lenX, lenY, nextX, nextY) &&
                                ((abs(i) == 1) xor (abs(j) == 1)) &&
                                (maze[nextX][nextY] == 1) &&
                                (dist[nextX][nextY] == (dist[currentX][currentY] - 1))) {

                                currentX = nextX;
                                currentY = nextY;

                                pathX.push_back(nextX);
                                pathY.push_back(nextY);

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
                int windowWidth = 900;
                int windowHeight = 900;

                sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Maze",
                                        sf::Style::Default, settings);
                window.clear(sf::Color::Blue);

                initMazeDraw(maze, window);

                drawPath(pathX, pathY, window, lenX, lenY);
                window.display();
                keepWindowOpened(window);
            }

        }
    } else {
        std::cout << "File issue" << std::endl;
    }
    return 0;
}
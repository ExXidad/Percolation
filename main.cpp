#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include "SFML/Graphics.hpp"
#include "percolation.h"

typedef std::pair<int, int> intPair;
typedef std::vector<int> intVector;
typedef std::vector<bool> boolVector;
typedef std::vector<std::vector<int>> intMap2D;
typedef std::vector<std::vector<bool>> boolMap2D;
typedef std::queue<intPair> intQueuePair;
typedef std::vector<intPair> intVectorPair;

bool pointInMazeQ(int lenX, int lenY, int x, int y) {
    return x < lenX && x >= 0 &&
           y < lenY && y >= 0;
}

bool testPerk(mapInt &maze, int m, int n) {
    std::srand(time(nullptr));

    int x0 = 0, y0 = 0;

    int x1 = n - 1, y1 = m + 1;

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

    if (dist[y1][x1] == -1) return false; else return true;
}

void computeNIterations(uint64_t &counter, int m, int n, int K, uint64_t N) {
    for (int iteration = 0; iteration < N; ++iteration) {
        mapInt maze = generateMap(m, n, K);//Returns (m+2):n size

        bool passQ = testPerk(maze, m, n);

        if (passQ) ++counter;
    }
}

int main() {
    std::srand(time(nullptr));

    int m = 30;
    int n = 30;

    uint64_t iters = pow(10, 6);

    int numberOfThreads = 12;
    uint64_t itersPerThread = iters / numberOfThreads;

    iters = itersPerThread * numberOfThreads;

    std::fstream file;
    file.open("result.txt", std::ios::out);

    for (int K = m; K <= m * n - std::min(m, n); K+=10) {
        std::vector<uint64_t> partialCounters(numberOfThreads, 0);
        std::vector<std::thread> threads(0);
        for (int threadNumber = 0; threadNumber < numberOfThreads; ++threadNumber) {
            threads.emplace_back(
                    std::thread(computeNIterations, std::ref(partialCounters[threadNumber]), m, n, K, itersPerThread));
        }

        for (auto &thread : threads) {
            thread.join();
        }

        uint64_t counter = std::accumulate(partialCounters.begin(), partialCounters.end(), uint64_t(0));

        file << K << " " << static_cast<long double>(counter) / iters << std::endl;
        std::cout << "Progress: " << static_cast<double>(K-m) / (m * n - std::min(m, n) - m)*100<< "%"
                  << std::endl;
    }

    file.close();
    return 0;
}
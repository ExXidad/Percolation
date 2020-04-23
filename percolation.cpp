#include "percolation.h"


mapInt generateMap(int m, int n, int K) {
    mapInt map(m + 2, std::vector<int>(n, 0));
    if (m * n <= K) {
        for (int j = 0; j < m + 2; ++j) {
            for (int i = 0; i < n + 1; ++i) {
                map[j][i] = 1;
            }
        }
    } else {
        std::vector<std::pair<int, int>> possiblePlaces;
        for (int j = 1; j < m + 1; ++j) {
            for (int i = 0; i < n; ++i) {
                possiblePlaces.emplace_back(std::pair<int, int>(i, j));
            }
        }

        for (auto &item : map[0]) item = 1;
        for (auto &item : map[m + 1]) item = 1;

        for (int k = 0; k < K; ++k) {
            int possibleNumber = rand() % possiblePlaces.size();
            std::pair<int, int> pair = possiblePlaces[possibleNumber];
            map[pair.second][pair.first] = 1;
            possiblePlaces.erase(possiblePlaces.begin() + possibleNumber);
        }
    }

    return map;
}

std::ostream &operator<<(std::ostream &stream, const mapInt &map) {
    for (int j = 0; j < map.size(); ++j) {
        std::cout << "| ";
        for (int i = 0; i < map[0].size(); ++i) {
            std::cout << std::setw(3) << map[j][i] << " ";
        }
        std::cout << "|";
        std::cout << std::endl;
    }
}
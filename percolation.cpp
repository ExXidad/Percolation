#include "percolation.h"


mapInt generateMap(int m, int n, int K) {
    std::srand(time(nullptr));
    mapInt map(m + 2, std::vector<int>(n, 0));
    if (m * n <= K) {
        for (int j = 0; j < m + 2; ++j) {
            for (int i = 0; i < n + 1; ++i) {
                map[j][i] = 1;
            }
        }
    } else {
        for (auto &item : map[0]) item = 1;
        for (auto &item : map[m + 1]) item = 1;

        for (int k = 0; k < K; ++k) {
            int j = rand() % (m + 2);
            int i = rand() % n;
            if (map[j][i] == 0) map[j][i] = 1; else --k;
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
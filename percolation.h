//
// Created by exxidad on 21.04.2020.
//

#ifndef MAZE_PERCOLATION_H
#define MAZE_PERCOLATION_H

#include <random>
#include <ctime>
#include <vector>
#include <iomanip>
#include <iostream>

typedef std::vector<std::vector<int>> mapInt;

mapInt generateMap(int m, int n, int K);

std::ostream &operator<< (std::ostream &stream,const mapInt &map);

#endif //MAZE_PERCOLATION_H

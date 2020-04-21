//
// Created by mi on 21.03.2020.
//

#ifndef MATHVECT_MYTYPES_H
#define MATHVECT_MYTYPES_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

typedef std::vector<double> vectorDouble;
typedef std::vector<int> vectorInt;
typedef std::vector<vectorDouble> mapDouble;

vectorDouble operator*(const vectorDouble &vector, const double num);

void operator*=(vectorDouble &vector, const double num);

vectorDouble operator+(const vectorDouble &vector, const double num);

void operator+=(vectorDouble &vector, const double num);

vectorDouble operator-(const vectorDouble &vector, const double num);

void operator-=(vectorDouble &vector, const double num);

vectorDouble operator/(const vectorDouble &vector, const double num);

void operator/=(vectorDouble &vector, const double num);

vectorDouble operator+(vectorDouble &vect, const vectorDouble &anotherVect);

void operator+=(vectorDouble &vect, const vectorDouble &anotherVect);

vectorDouble operator-(const vectorDouble &vect, const vectorDouble &anotherVect);

void operator-=(vectorDouble &vect, const vectorDouble &anotherVect);

double operator*(const vectorDouble &vect, const vectorDouble &anotherVect);

std::ostream &operator<< (std::ostream &stream, vectorDouble & vect);

//////////////////////////////////////////////////////////////////////////////////
vectorInt operator*(const vectorInt &vector, const int num);

void operator*=(vectorInt &vector, const int num);

vectorInt operator+(const vectorInt &vector, const int num);

void operator+=(vectorInt &vector, const int num);

vectorInt operator-(const vectorInt &vector, const int num);

void operator-=(vectorInt &vector, const int num);

vectorInt operator/(const vectorInt &vector, const int num);

void operator/=(vectorInt &vector, const int num);

vectorInt operator+(vectorInt &vect, const vectorInt &anotherVect);

void operator+=(vectorInt &vect, const vectorInt &anotherVect);

vectorInt operator-(const vectorInt &vect, const vectorInt &anotherVect);

void operator-=(vectorInt &vect, const vectorInt &anotherVect);

int operator*(const vectorInt &vect, const vectorInt &anotherVect);

std::ostream &operator<< (std::ostream &stream, vectorInt & vect);
//////////////////////////////////////////////////////////////////////////////////

mapDouble operator+(mapDouble &map, const double num);

void operator+=(mapDouble &map, const double num);

mapDouble operator-(mapDouble &map, const double num);

void operator-=(mapDouble &map, const double num);

mapDouble operator*(mapDouble &map, const double num);

void operator*=(mapDouble &map, const double num);

mapDouble operator/(mapDouble &map, const double num);

void operator/=(mapDouble &map, const double num);

mapDouble operator+(mapDouble &map, const mapDouble &anotherMap);

void operator+=(mapDouble &map, const mapDouble &anotherMap);

mapDouble operator-(const mapDouble &map, const mapDouble &anotherMap);

void operator-=(mapDouble &map, const mapDouble &anotherMap);

double operator*(const mapDouble &map, const mapDouble &anotherMap);

std::ostream &operator<< (std::ostream &stream,const mapDouble &map);
//////////////////////////////////////////////

#endif //MATHVECT_MYTYPES_H

#include "myTypes.h"

vectorDouble operator*(const vectorDouble &vector, const double num) {
    vectorDouble tmp(vector.size(), 0);
    for (int i = 0; i < vector.size(); ++i) {
        tmp[i] = vector[i] * num;
    }
    return tmp;
}

void operator*=(vectorDouble &vector, const double num) {
    for (double &item : vector) {
        item *= num;
    }
}


vectorDouble operator+(const vectorDouble &vector, const double num) {
    vectorDouble tmp(vector.size(), 0);
    for (int i = 0; i < vector.size(); ++i) {
        tmp[i] = vector[i] + num;
    }
    return tmp;
}

void operator+=(vectorDouble &vector, const double num) {
    for (double &item : vector) {
        item += num;
    }
}


vectorDouble operator-(const vectorDouble &vector, const double num) {
    vectorDouble tmp(vector.size(), 0);
    for (int i = 0; i < vector.size(); ++i) {
        tmp[i] = vector[i] - num;
    }
    return tmp;
}

void operator-=(vectorDouble &vector, const double num) {
    for (double &item : vector) {
        item -= num;
    }
}


vectorDouble operator/(const vectorDouble &vector, const double num) {
    vectorDouble tmp(vector.size(), 0);
    for (int i = 0; i < vector.size(); ++i) {
        tmp[i] = vector[i] / num;
    }
    return tmp;
}

void operator/=(vectorDouble &vector, const double num) {
    for (double &item : vector) {
        item /= num;
    }
}



vectorDouble operator+(vectorDouble &vect, const vectorDouble &anotherVect) {
    if (vect.size() != anotherVect.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    vectorDouble tmp(vect.size(), 0);
    for (int i = 0; i < vect.size(); ++i) {
        tmp[i] = vect[i] + anotherVect[i];
    }

    return vectorDouble(tmp);
}

void operator+=(vectorDouble &vect, const vectorDouble &anotherVect) {
    if (vect.size() != anotherVect.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    for (int i = 0; i < vect.size(); ++i) {
        vect[i] += anotherVect[i];
    }
}


vectorDouble operator-(const vectorDouble &vect, const vectorDouble &anotherVect) {
    if (vect.size() != anotherVect.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    vectorDouble tmp(vect.size(), 0);
    for (int i = 0; i < vect.size(); ++i) {
        tmp[i] = vect[i] - anotherVect[i];
    }

    return vectorDouble(tmp);
}

void operator-=(vectorDouble &vect, const vectorDouble &anotherVect) {
    if (vect.size() != anotherVect.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    for (int i = 0; i < vect.size(); ++i) {
        vect[i] -= anotherVect[i];
    }
}


double operator*(const vectorDouble &vect, const vectorDouble &anotherVect) {
    if (vect.size() != anotherVect.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    double tmp = 0;
    for (int i = 0; i < vect.size(); ++i) {
        tmp += vect[i] * anotherVect[i];
    }

    return tmp;
}

std::ostream &operator<< (std::ostream &stream, vectorDouble & vect){
    for (const auto &item : vect) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
};

///////////////////////////////////////////////////////////////////////////////////
vectorInt operator*(const vectorInt &vector, const int num) {
    vectorInt tmp(vector.size(), 0);
    for (int i = 0; i < vector.size(); ++i) {
        tmp[i] = vector[i] * num;
    }
    return tmp;
}

void operator*=(vectorInt &vector, const int num) {
    for (int &item : vector) {
        item *= num;
    }
}


vectorInt operator+(const vectorInt &vector, const int num) {
    vectorInt tmp(vector.size(), 0);
    for (int i = 0; i < vector.size(); ++i) {
        tmp[i] = vector[i] + num;
    }
    return tmp;
}

void operator+=(vectorInt &vector, const int num) {
    for (int &item : vector) {
        item += num;
    }
}


vectorInt operator-(const vectorInt &vector, const int num) {
    vectorInt tmp(vector.size(), 0);
    for (int i = 0; i < vector.size(); ++i) {
        tmp[i] = vector[i] - num;
    }
    return tmp;
}

void operator-=(vectorInt &vector, const int num) {
    for (int &item : vector) {
        item -= num;
    }
}


vectorInt operator/(const vectorInt &vector, const int num) {
    vectorInt tmp(vector.size(), 0);
    for (int i = 0; i < vector.size(); ++i) {
        tmp[i] = vector[i] / num;
    }
    return tmp;
}

void operator/=(vectorInt &vector, const int num) {
    for (int &item : vector) {
        item /= num;
    }
}



vectorInt operator+(vectorInt &vect, const vectorInt &anotherVect) {
    if (vect.size() != anotherVect.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    vectorInt tmp(vect.size(), 0);
    for (int i = 0; i < vect.size(); ++i) {
        tmp[i] = vect[i] + anotherVect[i];
    }

    return vectorInt(tmp);
}

void operator+=(vectorInt &vect, const vectorInt &anotherVect) {
    if (vect.size() != anotherVect.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    for (int i = 0; i < vect.size(); ++i) {
        vect[i] += anotherVect[i];
    }
}


vectorInt operator-(const vectorInt &vect, const vectorInt &anotherVect) {
    if (vect.size() != anotherVect.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    vectorInt tmp(vect.size(), 0);
    for (int i = 0; i < vect.size(); ++i) {
        tmp[i] = vect[i] - anotherVect[i];
    }

    return vectorInt(tmp);
}

void operator-=(vectorInt &vect, const vectorInt &anotherVect) {
    if (vect.size() != anotherVect.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    for (int i = 0; i < vect.size(); ++i) {
        vect[i] -= anotherVect[i];
    }
}


int operator*(const vectorInt &vect, const vectorInt &anotherVect) {
    if (vect.size() != anotherVect.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    int tmp = 0;
    for (int i = 0; i < vect.size(); ++i) {
        tmp += vect[i] * anotherVect[i];
    }

    return tmp;
}

std::ostream &operator<< (std::ostream &stream, vectorInt & vect){
    for (const auto &item : vect) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
};
///////////////////////////////////////////////////////////////////////////////////

mapDouble operator+(mapDouble &map, const double num) {
    mapDouble tmp(map.size(), vectorDouble(map[0].size(), 0));
    for (int j = 0; j < map.size(); ++j)
        for (int i = 0; i < map[0].size(); ++i) {
            tmp[j][i] = map.at(j).at(i) + num;
        }

    return tmp;
}

void operator+=(mapDouble &map, const double num) {
    mapDouble tmp(map.size(), vectorDouble(map[0].size(), 0));
    for (int j = 0; j < map.size(); ++j)
        for (int i = 0; i < map[0].size(); ++i) {
            map.at(j).at(i) += num;
        }
}


mapDouble operator-(mapDouble &map, const double num) {
    mapDouble tmp(map.size(), vectorDouble(map[0].size(), 0));
    for (int j = 0; j < map.size(); ++j)
        for (int i = 0; i < map[0].size(); ++i) {
            tmp[j][i] = map.at(j).at(i) - num;
        }

    return tmp;
}

void operator-=(mapDouble &map, const double num) {
    mapDouble tmp(map.size(), vectorDouble(map[0].size(), 0));
    for (int j = 0; j < map.size(); ++j)
        for (int i = 0; i < map[0].size(); ++i) {
            map.at(j).at(i) -= num;
        }
}


mapDouble operator*(mapDouble &map, const double num) {
    mapDouble tmp(map.size(), vectorDouble(map[0].size(), 0));
    for (int j = 0; j < map.size(); ++j)
        for (int i = 0; i < map[0].size(); ++i) {
            tmp[j][i] = map.at(j).at(i) * num;
        }

    return tmp;
}

void operator*=(mapDouble &map, const double num) {
    mapDouble tmp(map.size(), vectorDouble(map[0].size(), 0));
    for (int j = 0; j < map.size(); ++j)
        for (int i = 0; i < map[0].size(); ++i) {
            map.at(j).at(i) *= num;
        }
}


mapDouble operator/(mapDouble &map, const double num) {
    mapDouble tmp(map.size(), vectorDouble(map[0].size(), 0));
    for (int j = 0; j < map.size(); ++j)
        for (int i = 0; i < map[0].size(); ++i) {
            tmp[j][i] = map.at(j).at(i) / num;
        }

    return tmp;
}

void operator/=(mapDouble &map, const double num) {
    mapDouble tmp(map.size(), vectorDouble(map[0].size(), 0));
    for (int j = 0; j < map.size(); ++j)
        for (int i = 0; i < map[0].size(); ++i) {
            map.at(j).at(i) /= num;
        }
}



mapDouble operator+(mapDouble &map, const mapDouble &anotherMap) {
    if (map[0].size() != anotherMap[0].size() || map.size() != anotherMap.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    mapDouble tmp(map.size(), vectorDouble(map[0].size(), 0));
    for (int j = 0; j < map.size(); ++j)
        for (int i = 0; i < map[0].size(); ++i) {
            tmp[j][i] = map.at(j).at(i) + anotherMap.at(j).at(i);
        }

    return tmp;
}

void operator+=(mapDouble &map, const mapDouble &anotherMap) {
    if (map[0].size() != anotherMap[0].size() || map.size() != anotherMap.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    mapDouble tmp(map.size(), vectorDouble(map[0].size(), 0));
    for (int j = 0; j < map.size(); ++j)
        for (int i = 0; i < map[0].size(); ++i) {
            map.at(j).at(i) += anotherMap.at(j).at(i);
        }
}


mapDouble operator-(const mapDouble &map, const mapDouble &anotherMap) {
    if (map[0].size() != anotherMap[0].size() || map.size() != anotherMap.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    mapDouble tmp(map.size(), vectorDouble(map[0].size(), 0));
    for (int j = 0; j < map.size(); ++j)
        for (int i = 0; i < map[0].size(); ++i) {
            tmp[j][i] = map.at(j).at(i) - anotherMap.at(j).at(i);
        }

    return tmp;
}

void operator-=(mapDouble &map, const mapDouble &anotherMap) {
    if (map[0].size() != anotherMap[0].size() || map.size() != anotherMap.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    mapDouble tmp(map.size(), vectorDouble(map[0].size(), 0));
    for (int j = 0; j < map.size(); ++j)
        for (int i = 0; i < map[0].size(); ++i) {
            map.at(j).at(i) -= anotherMap.at(j).at(i);
        }
}


double operator*(const mapDouble &map, const mapDouble &anotherMap) {
    if (map[0].size() != anotherMap[0].size() || map.size() != anotherMap.size()) {
        throw std::invalid_argument("Wrond dimensions");
    };

    double tmp = 0;
    for (int j = 0; j < map.size(); ++j)
        for (int i = 0; i < map[0].size(); ++i) {
            tmp += map.at(j).at(i) * anotherMap.at(j).at(i);
        }

    return tmp;
}

std::ostream &operator<< (std::ostream &stream,const mapDouble &map) {
    for (int j = 0; j < map.size(); ++j) {
        std::cout << "| ";
        for (int i = 0; i < map[0].size(); ++i) {
            std::cout << std::setw(3) << map[j][i] << " ";
        }
        std::cout << "|";
        std::cout << std::endl;
    }
}

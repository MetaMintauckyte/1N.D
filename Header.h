#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cctype>
#include <chrono>
#include <list>

using std::string;
using std::cout;

using std::vector;
using std::map;
using std::mt19937;


class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start{ std::chrono::high_resolution_clock::now() } {}
    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
        return std::chrono::duration<double>
            (std::chrono::high_resolution_clock::now() - start).count();
    }
};


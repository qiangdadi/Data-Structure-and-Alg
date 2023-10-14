#pragma once 

#include <random>
#include <chrono>

using std::mt19937;
using std::chrono::steady_clock;
using std::uniform_int_distribution;

int generateARandom(int m, int n);
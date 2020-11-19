#ifndef MAIN_H
#define MAIN_H

#include <fstream>
#include "utils.h"
#include "Solution.h"

std::vector<int> getCost(std::ifstream *instance, int n);
std::vector<std::vector<int>> getCibles(std::ifstream *instance, int m);

#endif // MAIN_H

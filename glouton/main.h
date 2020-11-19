#ifndef MAIN_H
#define MAIN_H

#include <fstream>
#include "utils.h"

void getCost(int *cost, std::ifstream *instance, int n);
void getCibles(int **cibles, std::ifstream *instance, int m);

#endif // MAIN_H
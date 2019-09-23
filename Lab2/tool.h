//
// Created by User on 22.09.2019.
//

#ifndef LAB2_TOOL_H
#define LAB2_TOOL_H

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

void fill(std::vector<int> &, int, std::vector<std::string>);


int selection_sort(std::vector<int> &, int *, int *);

int shell_sort(std::vector<int> &, int *, int *);

void print(std::vector<int> &);

#endif //LAB2_TOOL_H
//
// Created by User on 22.09.2019.
//


#include "tool.h"

void fill(std::vector<int> &arr, int type, std::vector<std::string> f_name) {

    for (int i = 10+type; i >= 0; --i) {
        arr.push_back(i);
    }
}

int selection_sort(std::vector<int> &arr, int* copy, int* cmp) {
    int min_i;
    for (int i = 0; i < arr.size() - 1; ++i) {
        (*cmp)++;
        min_i = i;
        (*copy)++;
        for (int j = i + 1; j < arr.size(); ++j) {
            (*cmp)++;
            if (arr.at(j) < arr.at(min_i)) {
                min_i = j;
                (*copy)++;
            }
        }
        (*cmp)++;
        if(min_i != i) {
            std::swap(arr.at(i), arr.at(min_i));
            (*copy)++;
        }
    }
}

void print(std::vector<int> &arr) {
    for (int i : arr)
        std::cout << i << ", ";
    std::cout << std::endl;
};

//
// Created by User on 22.09.2019.
//


#include "tool.h"

void fill(std::vector<int> &arr, int type, std::vector<std::string> f_name) {
    std::ifstream file(f_name.at(type));
    if (file.is_open()) {
        int num{};
        char c{};
        while (file >> num >> c && c == ',')
            arr.push_back(num);
        arr.push_back(num);
    }
    file.close();
}

void print(std::vector<int> &arr) {
    for (int i : arr)
        std::cout << i << ", ";
    std::cout << "\n\n";
}

int selection_sort(std::vector<int> &arr, int *copy, int *cmp) {
    int min_i;
    for (int i = 0; i < arr.size() - 1; ++i) {
        min_i = i;
        (*copy) += 3;
        for (int j = i + 1; j < arr.size(); ++j) {
            (*cmp)++;
            if (arr.at(j) < arr.at(min_i)) {
                min_i = j;
                (*copy)++;
            }
        }
        if (min_i != i) {
            std::swap(arr.at(i), arr.at(min_i));

        }
    }
}

int shell_sort(std::vector<int> &arr, int *copy, int *cmp) {
    for (int step = arr.size() / 2; step > 0; step /= 2) {
        (*cmp)++;
        for (int i = step; i < arr.size(); i++) {
            (*cmp)++;
            for (int j = i - step; j >= 0 && arr.at(j) > arr.at(j + step); j -= step) {
                (*cmp)++;
                (*copy)++;
                std::swap(arr.at(j), arr.at(j + step));
            }
        }
    }
}



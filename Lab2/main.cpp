#include "tool.h"


int main() {
    std::vector<int> arr;
    int copy[12]{}, cmp[12]{};
    double elapsed_time[12]{};
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::vector<std::string> f_name = {"constant100.txt", "constant1000.txt", "constant10000.txt",
                                       "random100.txt", "random1000.txt", "random10000.txt",
                                       "reversed100.txt", "reversed1000.txt", "reversed10000.txt",
                                       "sorted100.txt", "sorted1000.txt", "sorted10000.txt"};

    std::cout << "Sorting type:\n\t1 - Selection\n\t2 - Shell\n" << std::endl;
    int s{};
    std::cin >> s;
    switch (s) {
        case 1:
            for (int type = 0; type < 12; ++type) {
                fill(arr, type, f_name);
                if (type == 0 || type == 3 || type == 6 || type == 9)
                    print(arr);
                start = std::chrono::high_resolution_clock::now();
                selection_sort(arr, &copy[type], &cmp[type]);
                end = std::chrono::high_resolution_clock::now();
                if (type == 0 || type == 3 || type == 6 || type == 9)
                    print(arr);
                arr.clear();
                elapsed_time[type] = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(
                        end - start).count()) / 1000;
                std::cout << "Was sorted " << f_name[type] << "\ncopy - " << copy[type] << " compare - " << cmp[type]
                          << " Time = " << elapsed_time[type] << " milliseconds" << "\n\n";
            }
            break;
        case 2:
            for (int type = 0; type < 12; ++type) {
                fill(arr, type, f_name);
                if (type == 0 || type == 3 || type == 6 || type == 9)
                    print(arr);
                start = std::chrono::high_resolution_clock::now();
                shell_sort(arr, &copy[type], &cmp[type]);
                end = std::chrono::high_resolution_clock::now();
                if (type == 0 || type == 3 || type == 6 || type == 9)
                    print(arr);
                arr.clear();
                elapsed_time[type] = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(
                        end - start).count()) / 1000;
                std::cout << "Was sorted " << f_name[type] << "\ncopy - " << copy[type] << " compare - " << cmp[type]
                          << " Time = " << elapsed_time[type] << " milliseconds" << "\n\n";
            }
            break;
    }
    std::cout << std::setw(20) << "Array" << std::setw(10) << "Copy" << std::setw(10) << "Compare" << std::setw(10)
              << "Time" << std::endl;
    for (int i = 0; i < 12; ++i) {
        std::cout << std::setw(20) << f_name[i] << std::setw(10) << copy[i] << std::setw(10) << cmp[i] << std::setw(10)
                  << elapsed_time[i] << std::endl;
    }
    system("pause");
    return 0;
}
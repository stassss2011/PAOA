#include "tool.h"
#define n 100

int main() {
    std::vector<int> arr;
    int copy[12]{}, cmp[12]{};
    std::vector<std::string> f_name = {"constant100.txt", "constant1000.txt", "constant10000.txt",
                                       "random100.txt", "random1000.txt", "random10000.txt",
                                       "reversed100.txt", "reversed1000.txt", "reversed10000.txt",
                                       "sorted100.txt", "sorted1000.txt", "sorted10000.txt"};

    std::cout << "Array type:\n\t1 - constant\n\t2 - random\n\t3 - reversed\n\t4 - sorted\n" << std::endl;

    for (int type = 0; type < 12; ++type) {
        fill(arr, type, f_name);
        if (type == 0 || type == 3 || type == 6 || type == 9)
            print(arr);
        selection_sort(arr, &copy[type], &cmp[type]);
        if (type == 0 || type == 3 || type == 6 || type == 9)
            print(arr);
        arr.clear();
        std::cout << "Was sorted " << f_name[type] << "\ncopy - " << copy[type] << " compare - " << cmp[type] << std::endl;
    }
    system("pause");
    return 0;
}
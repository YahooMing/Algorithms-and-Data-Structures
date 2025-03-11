#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& table) {
    int n = table.size();
    for (int i = n-1; i > 0; i--) {
        int max = 0;
        for (int j = 1; j <= i; ++j) {
            if (table[j] > table[max]) {
                max = j;
            }
        }
        std::swap(table[max], table[i]);
    }
}

void seeout(const std::vector<int>& table) {
    for (int el : table) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> table = {29, 10, 14, 37, 13};

    std::cout << "Przed sortowaniem: ";
    seeout(table);

    std::cout << "Po sortowaniu: ";
    selectionSort(table);
    seeout(table);

    return 0;
}

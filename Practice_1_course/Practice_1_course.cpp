#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <Windows.h>

int Get_Random_Number(int, int);
void Cyclic_Shift(std::vector <int>&, int, int);
void print_separator();

int main()
{
    std::cout << "\x1b[36m";
    print_separator();
    setlocale(LC_ALL, "Russian");
    int m, n;
    std::vector <int> data_array;
    std::cout << "Введите размер первой части массива, m = ";
    std::cin >> m;
    std::cout << "Введите размер второй части массива, n = ";
    std::cin >> n;
    srand(time(NULL));
    for (int i = 0; i < m + n; i++) {
        data_array.push_back(Get_Random_Number(1, 50));
    };
    print_separator();
    std::cout << "Изначальный массив:" << std::endl;
    for (int i = 0; i < m; i++) {
        std::cout  << "\x1b[31m" << std::setw(3)  << data_array[i] << "\x1b[36m";
    };
    for (int i = m; i < m + n; i++) {
        std::cout << "\x1b[32m" << std::setw(3) << data_array[i] << "\x1b[36m";
    };
    std::cout << std::endl;
    print_separator();
    print_separator();
    Cyclic_Shift(data_array, data_array.size(), n);
    std::cout << "Измененный массив:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "\x1b[32m" << std::setw(3) << data_array[i] << "\x1b[36m";
    };
    for (int i = n; i < m + n; i++) {
        std::cout << "\x1b[31m" << std::setw(3) << data_array[i] << "\x1b[36m";
    };
    std::cout << std::endl << "\x1b[3m";
    print_separator();
};

int Get_Random_Number(int min, int max) {
    return min + rand() % (max - min + 1);
}; 

void Cyclic_Shift(std::vector <int>& data, int size, int change) {
    for (int i = 0; i < change; i++) {
        int temp = data[size - 1];
        for (int j = size - 2; j >= 0; j--) {
            data[j + 1] = data[j];
        };
        data[0] = temp;
    };
};

void print_separator() {
    HWND hwnd = GetConsoleWindow();
    RECT rc;
    GetClientRect(hwnd, &rc);
    int width = rc.right;
    std::cout << "\x1b[35m";
    for (int i = 0; i < width * 0.125 - 1; i++) {
        std::cout << "#";
    };
    std::cout << "\x1b[36m";
    std::cout << std::endl;
};
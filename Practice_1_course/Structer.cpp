#include "Structer.h"

int Get_Random_Number(int min, int max) {
    return min + rand() % (max - min + 1);
};

int Input_Number(std::string name) {
    int number;
    while (true) {
        std::cin >> number;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Неправильно! Введите число! " + name + " = ";
        }
        else {
            if (number <= 0) {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Неправильно! Введите положительное число! " + name + " = ";
            }
            else {
                break;
            };
        };
    };
    return number;
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

data_array::data_array(int _m, int _n) {
    m = _m;
    n = _n;
    srand(time(NULL));
    for (int i = 0; i < m + n; i++) {
        data.push_back(Get_Random_Number(1, 50));
    };
};

void data_array::print_initial() {
    std::cout << "Изначальный массив:" << std::endl;
    for (int i = 0; i < m; i++) {
        std::cout << "\x1b[31m" << std::setw(3) << data[i] << "\x1b[36m";
    };
    for (int i = m; i < m + n; i++) {
        std::cout << "\x1b[32m" << std::setw(3) << data[i] << "\x1b[36m";
    };
    std::cout << std::endl;
};

void data_array::cyclic_shift(int change) {
    for (int i = 0; i < change; i++) {
        int temp = data[m + n - 1];
        for (int j = m + n - 2; j >= 0; j--) {
            data[j + 1] = data[j];
        };
        data[0] = temp;
    };
};

void data_array::print_modified() {
    std::cout << "Измененный массив:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "\x1b[32m" << std::setw(3) << data[i] << "\x1b[36m";
    };
    for (int i = n; i < m + n; i++) {
        std::cout << "\x1b[31m" << std::setw(3) << data[i] << "\x1b[36m";
    };
    std::cout << std::endl;
};
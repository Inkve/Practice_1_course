#include "Structer.h"

int Input_Number(std::string name) {
    float number;
    while (true) {
        if ((std::cin >> number).good() && (1 <= number) && (number < 11)) {
            return int(number);
        };
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Неверный ввод! Введите число! " + name + " = ";
        }
        else {
            std::cin.clear();
            std::cout << "Значение не в диапазоне! " + name + " = ";
        }
        std::cin.ignore(100, '\n');
    };
};

void print_separator() {
    HWND hwnd = GetConsoleWindow();
    RECT rc;
    GetClientRect(hwnd, &rc);
    int width = rc.right;
    std::cout << "\x1b[35m";
    for (int i = 0; i < width * 0.139 - 1; i++) {
        std::cout << "#";
    };
    std::cout << "\x1b[36m";
    std::cout << std::endl;
};

data_array::data_array(int _m, int _n) {
    m = _m;
    n = _n;
    data = new int[m + n];
    srand(time(NULL));
    const int min = 1;
    const int max = 50;
    for (int i = 0; i < m + n; i++) {
        data[i] = min + rand() % (max - min + 1);
    };
};

void data_array::print_initial() {
    std::cout << "Изначальный массив:" << std::endl;
    for (int i = 0; i < m; i++) {
        std::cout << "\x1b[31m" << data[i] << "\x1b[36m" << " ";
    };
    for (int i = m; i < m + n; i++) {
        std::cout << "\x1b[32m" << data[i] << "\x1b[36m" << " ";
    };
    std::cout << std::endl;
};

void data_array::cyclic_shift() {
    int change = n;
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
        std::cout << "\x1b[32m" << data[i] << "\x1b[36m" << " ";
    };
    for (int i = n; i < m + n; i++) {
        std::cout << "\x1b[31m" << data[i] << "\x1b[36m" << " ";
    };
    std::cout << std::endl;
};

data_array::~data_array() {
    delete[] data;
};
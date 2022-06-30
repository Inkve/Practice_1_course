#include "Structer.h"

int main()
{
    std::cout << "\x1b[36m";
    print_separator();
    setlocale(LC_ALL, "Russian");
    int m, n;
    std::cout << "Введите размер первой части массива, m = ";
    std::cin >> m;
    std::cout << "Введите размер второй части массива, n = ";
    std::cin >> n;
    data_array arr(m, n);
    print_separator();
    arr.print_initial();
    print_separator();
    print_separator();
    arr.cyclic_shift(n);
    arr.print_modified();
    print_separator();
};
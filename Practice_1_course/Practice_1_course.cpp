#include <iostream>
#include <vector>

int GetRandomNumber(int, int);

int main()
{
    setlocale(LC_ALL, "Russian");
    int m, n;
    std::vector <int> data_array;
    std::cout << "Введите размер первой части массива, m = ";
    std::cin >> m;
    std::cout << "Введите размер второй части массива, n = ";
    std::cin >> n;
    
    for (int i = 0; i < m + n; i++) {
        data_array.push_back(GetRandomNumber(-10, 10));
    }
}

int GetRandomNumber(int min, int max) {
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}; 
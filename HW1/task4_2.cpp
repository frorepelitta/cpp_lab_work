#include <iostream>

int findLast(int arr[], int x, int n) {
    int last_point = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            last_point = i + 1;
        }
    }
    return last_point;
}

int main() {
    int n, x;
    std::cout << "Введите сколько элементов будет в массиве - " << std::endl;
    std::cin >> n;
    int array[n];
    std::cout << "Введите массив из " << n << " элементов" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    std::cout << "Введите x, который будем искать в массиве" << std::endl;
    std::cin >> x;
    std::cout << "В массиве элемент " << x << " находится в массиве на месте " << findLast(array, x, n) << std::endl;
    return 0;
}
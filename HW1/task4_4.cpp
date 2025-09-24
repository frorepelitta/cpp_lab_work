#include <iostream>

int* add(int arr[], int x, int pos, int size) {
    int* arr_second = new int[size + 1];
    for (int i = 0; i < pos; i++) {
        arr_second[i] = arr[i];
    } 

    arr_second[pos] = x;

    for (int i = pos; i < size; i++) {
        arr_second[i+1] = arr[i]; 
    } 

    return arr_second;
}


int main() {
    int n, x, pos;
    std::cout << "Введите сколько элементов будет в массиве - " << std::endl;
    std::cin >> n;
    int* array = new int[n]; 
    std::cout << "Введите массив из " << n << " элементов" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    std::cout << "Введите х" << std::endl;
    std::cin >> x;
    std::cout << "Введите позицию на которую выставить х" << std::endl;
    std::cin >> pos;

    if (pos > n) {
        pos = n;
    }
    if (pos < 0) {
        pos = 0;
    }

    int* add_arr = add(array, x, pos, n);
    for (int i = 0; i < n+1; i++) {
        std::cout << add_arr[i] << std::endl;
    }

    return 0;
}
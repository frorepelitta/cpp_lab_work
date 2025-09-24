#include <iostream>

void reverse(int arr[], int size) {
    int temp = 0;
    for (int i = 0; i < size/2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    int n;
    std::cout << "Введите сколько элементов будет в массиве - " << std::endl;
    std::cin >> n;
    int* array = new int[n]; 
    std::cout << "Введите массив из " << n << " элементов" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    reverse(array, n);

    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
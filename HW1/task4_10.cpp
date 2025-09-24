#include <iostream>

int* deleteNegative(int arr[], int& size) {
    int length = 0, j = 0;
    for(int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            length += 1;
        }
    }
    
    int* new_arr = new int[length];
    for(int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            new_arr[j] = arr[i];
            j++;
        }
    }
    size = length;
    return new_arr;
}


int main() {
    int x;
    std::cout << "Введите сколько элементов будет в массиве - " << std::endl;
    std::cin >> x;
    int* array = new int[x]; 
    std::cout << "Введите массив из " << x << " элементов" << std::endl;
    for (int i = 0; i < x; i++) {
        std::cin >> array[i];
    }

    int* positive_arr = deleteNegative(array, x);
    for (int i = 0; i < x; i++) {
        std::cout << positive_arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

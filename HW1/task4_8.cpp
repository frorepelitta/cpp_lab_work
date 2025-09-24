#include <iostream>

int* concat(int arr1[], int arr2[], int size1, int size2){
    int* double_arr = new int[size1 + size2];

    for(int i = 0; i < size1; i++) {
        double_arr[i] = arr1[i];
    }

    for(int i = 0; i < size2; i++) {
        double_arr[size1 + i] = arr2[i];
    }

    return double_arr;
}


int main() {
    int size1, size2;
    std::cout << "Введите сколько элементов будет в первом массиве - " << std::endl;
    std::cin >> size1;
    int* array = new int[size1]; 
    std::cout << "Введите массив из " << size1 << " элементов" << std::endl;
    for (int i = 0; i < size1; i++) {
        std::cin >> array[i];
    }

    std::cout << "Введите сколько элементов будет во втором массиве - " << std::endl;
    std::cin >> size2;
    int* array2 = new int[size2];
    std::cout << "Введите массив из " << size2 << " элементов" << std::endl;
    for (int i = 0; i < size2; i++) {
        std::cin >> array2[i];
    }

    int* new_arr = concat(array, array2, size1, size2);
    for (int i = 0; i < size1+size2; i++) {
        std::cout << new_arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
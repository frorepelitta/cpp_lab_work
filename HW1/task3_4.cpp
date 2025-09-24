#include <iostream>

int pow(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result = result * x;
    }
    return result;
}

int main() {
    int x = 0, y = 0;
    std::cout << "Введите число х и число у, в степень которого будем возводить х" << std::endl;
    std::cin >> x >> y;
    std::cout << pow(x, y) << std::endl;
    return 0;
}
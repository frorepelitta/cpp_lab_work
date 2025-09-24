#include <iostream>

double safeDiv(int x, int y) {
    if (y == 0 || x == 0) {
        return 0;
    }
    return (x + .0) / y;
}

int main() {
    int x = 0, y = 0;
    std::cout << "Введите x и y для операции x / y" << std::endl;
    std::cin >> x >> y;
    std::cout << safeDiv(x, y) << std::endl;
}
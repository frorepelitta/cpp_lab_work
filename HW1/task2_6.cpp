#include <iostream>

bool sum3(int x, int y, int z) {
    if ((x+y) == z) {
        return true;
    }
    else if ((x+z) == y) {
        return true;
    }
    else if ((y+z) == x) {
        return true;
    }
    return false;
}

int main() {
    int x = 0, y = 0, z = 0;
    std::cout << "Ведите три числа, будем проверять можно ли из двух сложить третье" << std::endl;
    std::cin >> x >> y >> z;
    std::cout << sum3(x, y, z) << std::endl;
    return 0;
}
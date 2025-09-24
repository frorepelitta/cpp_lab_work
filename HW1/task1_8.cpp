#include <iostream>

bool isDivisor(int a, int b) {
    if (a == 0 || b == 0){
        return false;
    }
    return (a % b == 0 || b % a == 0);
}

int main() {
    int a, b;
    std::cout << "Введите два числа, которые мы будем проверять на делимость" << std::endl;
    std::cin >> a >> b;
    std::cout << isDivisor(a, b) << std::endl;
}
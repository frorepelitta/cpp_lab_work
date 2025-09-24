#include <iostream>

void leftTriangle(int x) {
    if(x < 0) {
        std::cout << "Число должно быть положительным" << std::endl;
    }
    std::string result = "";
    for (int i = 0; i < x; i++) {
        result = result + "*";
        std::cout << result << std::endl;
    } 
}

int main() {
    int x = 0;
    std::cout << "Введите сколько будет уровней у треугольника" << std::endl;
    std::cin >> x;
    leftTriangle(x);
    return 0;
}
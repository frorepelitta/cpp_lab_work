#include <iostream>
#include <string>

std::string makeDecision(int x, int y) {
    if (x > y) {
        return std::to_string(x)+">"+std::to_string(y);
    }
    else if (x < y) {
        return std::to_string(x)+"<"+std::to_string(y);
    }
    else {
        return std::to_string(x)+"=="+std::to_string(y);
    }
}

int main() {
    int x = 0, y = 0;
    std::cout << "Введите числа x и y, которые будем сравнивать" << std::endl;
    std::cin >> x >> y;
    std::cout << makeDecision(x, y) << std::endl;
    return 0;
}
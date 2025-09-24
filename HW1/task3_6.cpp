#include <iostream>

bool equalNum(int x) {
    x = std::abs(x);
    int temp = x % 10;
    while(x > 0) {
        if(x%10 != temp) {
            return false;
        }
        x = x / 10;
    }
    return true;
}

int main() {
    int x = 0;
    std::cout << "Введите число х, в котором будет проверка на одинаковые цифры" << std::endl;
    std::cin >> x;
    std::cout << equalNum(x) << std::endl;
    return 0;
}
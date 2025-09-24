#include <iostream>

bool isUpperCase(char x) {
    return (x >= 'A' && x <= 'Z');
}

int main() {
    char x;
    std::cout << "Введи букву " << std::endl;
    std::cin >> x;
    std::cout << isUpperCase(x) << std::endl;
}
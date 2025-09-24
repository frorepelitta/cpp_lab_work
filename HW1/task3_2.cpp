#include <iostream>

std::string reverseListNums(int x) {
    std::string result = "";
    if (x > 0) {
        while (x != 0) {
            result = result + std::to_string(x) + " ";
            x = x - 1;
        }
    }
    if (x < 0) {
        while (x != 0) {
            result = result + std::to_string(x) + " ";
            x = x + 1;
        }
    }
    return result + "0";
}

int main() {
    int x = 0;
    std::cout << "Введите число х чтобы вывести все числа от х до 0 с шагом 1" << std::endl;
    std::cin >> x;
    std::cout << reverseListNums(x) << std::endl;
    return 0;
}
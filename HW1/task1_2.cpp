#include <iostream>

int sumLastNums(int x) {
    int digit = std::abs(x);

    int out1 = digit % 10;
    int out2 = (digit/10) % 10;
    int out = out1 + out2;

    return out;
}


int main() {
    int x = 0;
    std::cout << "Введите число, сумму двух последних знаков которого будем складывать" << std::endl;
    std::cin >> x;

    if (x / 10 == 0){
        std::cout << "Произошла ошибка ввода, нужно ввести число, у которого больше двух символов" << std::endl;
        return 0;
    }

    int result = sumLastNums(x);
    std::cout << "Сумма двух последних цифр числа " << x << " это " << result << std::endl;
    return 1;
}
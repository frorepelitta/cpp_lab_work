#include <iostream>
#include <ctime>

void guessGame() {
    std::srand(std::time(0));

    int number = rand() % 10;
    int i;
    std::cout << "Загадано число от 0 до 9, попробуйте угадать - " << std::endl;
    std::cin >> i;

    while (i != number) {
        std::cout << "Число не верно, введите другое" << std::endl;
        std::cin >> i;
    }
    
    std::cout << "Все верно, загаднное число это - " << i << std::endl;
}

int main() {
    guessGame();
    return 0;
}
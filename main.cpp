#include "money.h"


int main() {
    Money also_dengi(10);
    Money dengi(10, 0);
    std::cout << "money - " << dengi << std::endl;
    Money new_money = new_money.create();
    std::cout << "++money - " << ++dengi << std::endl;
    std::cout << "money++ - " << also_dengi++ << std::endl;
    std::cout << "Явное приведение к беззнаковому числовому - " << (unsigned int)new_money << std::endl;
    double double_new_money = new_money;
    std::cout << "Не явное приведение к беззнаковому числовому - " << double_new_money << std::endl;

    new_money = new_money + 10;
    std::cout << "Деньги + 10  -  " << new_money << std::endl;
}
#include <iostream>
#include "lab_work2.h"

int main() {
    int a;
    std::cout << "Введите номер задания" << std::endl;
    std::cin >> a;

    switch (a)
    {
    case 1: task1_3(); break;
    case 2: task2_4(); break;
    case 3: task3_7(); break;
    case 4: task4_1(); break;
    case 5: task5_2(); break;
    case 8: task8_1(); break;
    case 9: task9_1(); break;
    case 10: task10_2(); break;
    
    default:
        break;
    }
}
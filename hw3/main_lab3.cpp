#include "lab_work3.h"
#include <iostream>


int main() {
    int choose;
    std::cout << "Номер задания - " << std::endl;
    std::cin >> choose;
    switch (choose) {
        case 1: task1_2(); break;
        case 2: task1_3(); break;
        case 3: task2_2(); break;
        case 4: task3_3(); break;
    }
}
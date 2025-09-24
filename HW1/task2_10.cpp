#include <iostream>

void printDays(int x) {
    switch(x) {
        case 1:
            std::cout << "понедельник, вторник, среда, четверг, пятница, суббота, воскресенье" << std::endl;
            break;
        case 2:
            std::cout << "вторник, среда, четверг, пятница, суббота, воскресенье" << std::endl;
            break;
        case 3:
            std::cout << "среда, четверг, пятница, суббота, воскресенье" << std::endl;
            break;      
        case 4:
            std::cout << "четверг, пятница, суббота, воскресенье" << std::endl;
            break;
        case 5:
            std::cout << "пятница, суббота, воскресенье" << std::endl;
            break;
        case 6:
            std::cout << "суббота, воскресенье" << std::endl;
            break;
        case 7:
            std::cout << "воскресенье" << std::endl;
            break;
        default:
            std::cout << "Это не день недели" << std::endl;
    }   
}

int main() {
    int x = 0;
    std::cout << "Ведите день недели, и я выведу сегодняшний день и оставшиеся до конца недели" << std::endl;
    std::cin >> x;
    printDays(x);
    return 0;
}
#include <iostream>

std::string age(int x) {
    if (x < 0) {
        return "Ошибка, возраст не может быть меньше 0";
    }

    if (x%10 == 1 and x!=11) {
        return std::to_string(x) + " год";
    }

    else if ((x!=12 and x!=13 and x!=14) and (x%10 == 2 or x%10 == 3 or x%10 == 4)) {
        return std::to_string(x) + " года";
    }
    
    return std::to_string(x) + " лет";
}

int main() {
    int x = 0;
    std::cout << "Введите число, к которому будет добавлено год/года/лет" << std::endl;
    std::cin >> x;
    std::cout << age(x) << std::endl;
    return 0; 
}
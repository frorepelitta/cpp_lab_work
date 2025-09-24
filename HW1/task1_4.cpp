#include <iostream>

bool isPositive(int x) {
    if (x >= 0){
        return true;
    }
    else{
        return false;
    }

}


int main() {
    int x = 0;
    std::cout << "Введите число, проверку на >0 для которого будем делать" << std::endl;
    std::cin >> x;
    std::cout << isPositive(x) << std::endl; 
    return 0;
}
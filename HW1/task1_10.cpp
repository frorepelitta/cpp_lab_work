#include <iostream>

int lastNumSum(int a, int b) {
    return (a%10 + b%10);
}

int main() {
    int a = 5, b = 11, c = 123, d = 14, e = 1;
    a = lastNumSum(a, b);
    std::cout << a << std::endl;
    b = lastNumSum(a, c);
    std::cout << b << std::endl;
    c = lastNumSum(b, d);
    std::cout << c << std::endl;
    d = lastNumSum(c, e);
    std::cout << d << std::endl;
}
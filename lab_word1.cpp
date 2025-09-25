#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

// Задание 1.2 (1)  тест : 121 | результат : 3
int sumLastNums(int x) {
    int digit = std::abs(x);

    int out1 = digit % 10;
    int out2 = (digit/10) % 10;
    int out = out1 + out2;

    return out;
}

void task1_2() {
    int x = 0;
    std::cout << "Введите число, сумму двух последних знаков которого будем складывать" << std::endl;
    std::cin >> x;

    if (x / 10 == 0){
        std::cout << "Произошла ошибка ввода, нужно ввести число, у которого больше двух символов" << std::endl;
        return;
    }

    int result = sumLastNums(x);
    std::cout << "Сумма двух последних цифр числа " << x << " это " << result << std::endl;
}

// Задание 1.4  (2) тест : 1 | результат : true , тест : -1 | результат : false
bool isPositive(int x) {
    if (x >= 0){
        return true;
    }
    else{
        return false;
    }
}

void task1_4() {
    int x = 0;
    std::cout << "Введите число, проверку на >0 для которого будем делать" << std::endl;
    std::cin >> x;
    std::cout << isPositive(x) << std::endl; 
}

// Задание 1.6 (3) тест  : D | результат : true, тест : q | результат : false
bool isUpperCase(char x) {
    return (x >= 'A' && x <= 'Z');
}

void task1_6() {
    char x;
    std::cout << "Введи букву " << std::endl;
    std::cin >> x;
    std::cout << isUpperCase(x) << std::endl;
}

// Задание 1.8 (4) тест : 30 4 | результат : false, тест : 3 6 | результат : true
bool isDivisor(int a, int b) {
    if (a == 0 || b == 0){
        return false;
    }
    return (a % b == 0 || b % a == 0);
}

void task1_8() {
    int a, b;
    std::cout << "Введите два числа, которые мы будем проверять на делимость" << std::endl;
    std::cin >> a >> b;
    std::cout << isDivisor(a, b) << std::endl;
}

// Задание 1.10 (5) тест : 5 11 123 14  1 | результат : 5 + 11 = 6, 6+123=9, 9+14=13, 13+1=4
int lastNumSum(int a, int b) {
    return (abs(a)%10 + abs(b)%10);
}

void task1_10() {
    int a, b, c, d, e;
    std::cout << "Введите a, b, c, d, e" << std::endl;
    std::cin >> a >> b >> c >> d >> e;
    a = lastNumSum(a, b);
    std::cout << a << std::endl;
    b = lastNumSum(a, c);
    std::cout << b << std::endl;
    c = lastNumSum(b, d);
    std::cout << c << std::endl;
    d = lastNumSum(c, e);
    std::cout << d << std::endl;
}

// Задание 2.2 (6) тест : 5 0 | результат : 0 , тест : 8 2 | результат : 4
double safeDiv(int x, int y) {
    if (y == 0) {
        return 0;
    }
    return (x + .0) / y;
}

void task2_2() {
    int x = 0, y = 0;
    std::cout << "Введите x и y для операции x / y" << std::endl;
    std::cin >> x >> y;
    std::cout << safeDiv(x, y) << std::endl;
}

// Задание 2.4 (7) тест : 5 7 | результат : 5<7, тест : 8 -1| результат : 8>-1
std::string makeDecision(int x, int y) {
    if (x > y) {
        return std::to_string(x)+">"+std::to_string(y);
    }
    else if (x < y) {
        return std::to_string(x)+"<"+std::to_string(y);
    }
    else {
        return std::to_string(x)+"=="+std::to_string(y);
    }
}

void task2_4() {
    int x = 0, y = 0;
    std::cout << "Введите числа x и y, которые будем сравнивать" << std::endl;
    std::cin >> x >> y;
    std::cout << makeDecision(x, y) << std::endl;
}

// Задание 2.6 (8) тест : 5 7 2 | результат : true, тест : 8 -1 4 | результат : false
bool sum3(int x, int y, int z) {
    if ((x+y) == z) {
        return true;
    }
    else if ((x+z) == y) {
        return true;
    }
    else if ((y+z) == x) {
        return true;
    }
    return false;
}

void task2_6() {
    int x = 0, y = 0, z = 0;
    std::cout << "Ведите три числа, будем проверять можно ли из двух сложить третье" << std::endl;
    std::cin >> x >> y >> z;
    std::cout << sum3(x, y, z) << std::endl;
}

// Задание 2.8 (9) тест : 5 | результат : 5 лет , тест : 31 | результат : 31 год
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

void task2_8() {
    int x = 0;
    std::cout << "Введите число, к которому будет добавлено год/года/лет" << std::endl;
    std::cin >> x;
    std::cout << age(x) << std::endl;
}

// Задание 2.10 (10) тест : суббота | результат : суббота, воскресенье , тест : 123 | результат : Это не день недели
void printDays(std::string x) {
    int day = -1;
    if (x == "понедельник") day = 1;
    else if (x == "вторник") day = 2;
    else if (x == "среда") day = 3;
    else if (x == "четверг") day = 4;
    else if (x == "пятница") day = 5;
    else if (x == "суббота") day = 6;
    else if (x == "воскресенье") day = 7;

    switch(day) {
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

void task2_10() {
    std::string x;
    std::cout << "Ведите день недели, и я выведу сегодняшний день и оставшиеся до конца недели" << std::endl;
    std::cin >> x;
    printDays(x);
}

// Задание 3.2 (11) тест : 5 | результат : 5 4 3 2 1 0, тест : -5 | результат : -5 -4 -3 -2 -1 0
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

void task3_2() {
    int x = 0;
    std::cout << "Введите число х чтобы вывести все числа от х до 0 с шагом 1" << std::endl;
    std::cin >> x;
    std::cout << reverseListNums(x) << std::endl;
}

// Задание 3.4 (12) тест : 2 5 | результат : 32 
int pow(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result = result * x;
    }
    return result;
}

void task3_4() {
    int x = 0, y = 0;
    std::cout << "Введите число х и число у, в степень которого будем возводить х" << std::endl;
    std::cin >> x >> y;
    std::cout << pow(x, y) << std::endl;
}

// Задание 3.6 (13) тест : 1111 | результат : true, тест : 1211 | результат : false 
bool equalNum(int x) {
    x = std::abs(x);
    int temp = x % 10;
    while(x > 0) {
        if(x%10 != temp) {
            return false;
        }
        x = x / 10;
    }
    return true;
}

void task3_6() {
    int x = 0;
    std::cout << "Введите число х, в котором будет проверка на одинаковые цифры" << std::endl;
    std::cin >> x;
    std::cout << equalNum(x) << std::endl;
}

// Задание 3.8 (14)
void leftTriangle(int x) {
    if(x < 0) {
        std::cout << "Число должно быть положительным" << std::endl;
    }
    std::string result = "";
    for (int i = 0; i < x; i++) {
        result = result + "*";
        std::cout << result << std::endl;
    } 
}

void task3_8() {
    int x = 0;
    std::cout << "Введите сколько будет уровней у треугольника" << std::endl;
    std::cin >> x;
    leftTriangle(x);
}

// Задание 3.10 (15)
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

void task3_10() {
    guessGame();
}

// Задание 4.2 (16) тест : [1,2,3,4,5,2] | результат : 5
int findLast(int arr[], int x, int n) {
    int last_point = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            last_point = i;
        }
    }
    return last_point;
}

void task4_2() {
    int n, x;
    std::cout << "Введите сколько элементов будет в массиве - " << std::endl;
    std::cin >> n;
    int array[n];
    std::cout << "Введите массив из " << n << " элементов" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    std::cout << "Введите x, который будем искать в массиве" << std::endl;
    std::cin >> x;
    std::cout << "В массиве элемент " << x << " находится в массиве на месте " << findLast(array, x, n) << std::endl;
}

// Задание 4.4 (17) тест : [1,2,3,4,5] 9 3 | результат : 1 2 3 9 4 5 
int* add(int arr[], int x, int pos, int size) {
    int* arr_second = new int[size + 1];
    for (int i = 0; i < pos; i++) {
        arr_second[i] = arr[i];
    } 

    arr_second[pos] = x;

    for (int i = pos; i < size; i++) {
        arr_second[i+1] = arr[i]; 
    } 

    return arr_second;
}

void task4_4() {
    int n, x, pos;
    std::cout << "Введите сколько элементов будет в массиве - " << std::endl;
    std::cin >> n;
    int* array = new int[n]; 
    std::cout << "Введите массив из " << n << " элементов" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    std::cout << "Введите х" << std::endl;
    std::cin >> x;
    std::cout << "Введите позицию на которую выставить х" << std::endl;
    std::cin >> pos;

    if (pos > n) {
        pos = n;
    }
    if (pos < 0) {
        pos = 0;
    }

    int* add_arr = add(array, x, pos, n);
    for (int i = 0; i < n+1; i++) {
        std::cout << add_arr[i] << " ";
    }
    std::cout << std::endl;
}

// Задание 4.6 (18) тест : [1,2,3,4,5] | результат : [5,4,3,2,1]
void reverse(int arr[], int size) {
    int temp = 0;
    for (int i = 0; i < size/2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void task4_6() {
    int n;
    std::cout << "Введите сколько элементов будет в массиве - " << std::endl;
    std::cin >> n;
    int* array = new int[n]; 
    std::cout << "Введите массив из " << n << " элементов" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    reverse(array, n);

    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// Задание 4.8 (19) тест : [1,2,3] [4,5,6] | результат : [1,2,3,4,5,6]
int* concat(int arr1[], int arr2[], int size1, int size2){
    int* double_arr = new int[size1 + size2];

    for(int i = 0; i < size1; i++) {
        double_arr[i] = arr1[i];
    }

    for(int i = 0; i < size2; i++) {
        double_arr[size1 + i] = arr2[i];
    }

    return double_arr;
}

void task4_8() {
    int size1, size2;
    std::cout << "Введите сколько элементов будет в первом массиве - " << std::endl;
    std::cin >> size1;
    int* array = new int[size1]; 
    std::cout << "Введите массив из " << size1 << " элементов" << std::endl;
    for (int i = 0; i < size1; i++) {
        std::cin >> array[i];
    }

    std::cout << "Введите сколько элементов будет во втором массиве - " << std::endl;
    std::cin >> size2;
    int* array2 = new int[size2];
    std::cout << "Введите массив из " << size2 << " элементов" << std::endl;
    for (int i = 0; i < size2; i++) {
        std::cin >> array2[i];
    }

    int* new_arr = concat(array, array2, size1, size2);
    for (int i = 0; i < size1+size2; i++) {
        std::cout << new_arr[i] << " ";
    }
    std::cout << std::endl;
}

// Задание 4.10 (20) тест : [1,2,-1,-2] | результат : [1,2]
int* deleteNegative(int arr[], int& size) {
    int length = 0, j = 0;
    for(int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            length += 1;
        }
    }
    
    int* new_arr = new int[length];
    for(int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            new_arr[j] = arr[i];
            j++;
        }
    }
    size = length;
    return new_arr;
}

void task4_10() {
    int x;
    std::cout << "Введите сколько элементов будет в массиве - " << std::endl;
    std::cin >> x;
    int* array = new int[x]; 
    std::cout << "Введите массив из " << x << " элементов" << std::endl;
    for (int i = 0; i < x; i++) {
        std::cin >> array[i];
    }

    int* positive_arr = deleteNegative(array, x);
    for (int i = 0; i < x; i++) {
        std::cout << positive_arr[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    int choice;
    
    std::cout << "Выберите задание (1-20): ";
    std::cin >> choice;
    
    switch(choice) {
        case 1: task1_2(); break;
        case 2: task1_4(); break;
        case 3: task1_6(); break;
        case 4: task1_8(); break;
        case 5: task1_10(); break;
        case 6: task2_2(); break;
        case 7: task2_4(); break;
        case 8: task2_6(); break;
        case 9: task2_8(); break;
        case 10: task2_10(); break;
        case 11: task3_2(); break;
        case 12: task3_4(); break;
        case 13: task3_6(); break;
        case 14: task3_8(); break;
        case 15: task3_10(); break;
        case 16: task4_2(); break;
        case 17: task4_4(); break;
        case 18: task4_6(); break;
        case 19: task4_8(); break;
        case 20: task4_10(); break;
    }
    
    return 0;
}
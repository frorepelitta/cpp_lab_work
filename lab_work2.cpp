#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include <string>
#include <iterator>
#include <deque>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>


void task1_3() {
    bool flag = false;
    int numbers[10] {0, 1, 2, 3, 4, -5, -6, -7, -8, -9};

    std::vector<int> v(numbers, numbers + sizeof(numbers) / sizeof(numbers[0]));

    std::vector<int>::iterator iter = v.begin();
    std::vector<int>::iterator mid = v.begin() + v.size()/2;

    for(iter = mid; iter != v.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    for(iter = v.begin(); iter != mid; iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}


void task2_4() {
    int numbers[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int digits[10] {10, 100, 200, 300, 400, 500, 600, 700, 800, 900};

    std::vector<int> v(std::begin(numbers), std::end(numbers));
    std::list<int> l(std::begin(digits), std::end(digits));

    std::vector<int>::reverse_iterator iter_vector = v.rbegin();
    std::list<int>::iterator iter_list = l.begin();

    for(int i = 0; i<5; i++) {
        iter_list++;
    }

    l.insert(iter_list, iter_vector + (v.size() - 5), v.rend());

    for(iter_list = l.begin(); iter_list!=l.end(); iter_list++) {
        std::cout << *iter_list << " ";
    }
    std::cout << std::endl;
    
}


void task3_7() {

    int numbers[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> l1(std::begin(numbers), std::end(numbers));
    std::list<int> l2(std::begin(numbers), std::end(numbers));
    int count_l2_half_elem = 0;
    std::list<int>::iterator iter_l1 = l1.begin();
    std::list<int>::iterator iter_l2 = l2.begin();
    std::list<int>::iterator iter_l1_second = l1.begin();

    for(int i = 0; i < l2.size()/2; i++) {
        iter_l2++;
        count_l2_half_elem++;
    }

    l1.splice(l1.begin(), l2, iter_l2, l2.end());
    iter_l1 = l1.begin();

    for(int i = 0; i < count_l2_half_elem; i++) {
        iter_l1++;
    }

    for(int i = 0; i < (l1.size() - count_l2_half_elem)/2; i++) {
        iter_l1_second++;
    }
    l2.splice(l2.end(), l1, iter_l1, iter_l1_second);


    for(iter_l1 = l1.begin(); iter_l1 != l1.end(); iter_l1++) {
        std::cout << *iter_l1 << " ";
    }
    std::cout << std::endl;

    for(iter_l2 = l2.begin(); iter_l2 != l2.end(); iter_l2++) {
        std::cout << *iter_l2 << " ";
    }
    std::cout << std::endl;
}


void task4_1() {
    int k;
    std::cout << "Введите  К, которое будет служить ограничением по длине слов" << std::endl;
    std::cin >> k;

    std::ifstream input("name1.txt");
    std::ofstream output("name2.txt");

    std::remove_copy_if(
        std::istream_iterator<std::string>(input),
        std::istream_iterator<std::string>(),
        std::ostream_iterator<std::string>(output, "\n"),
        [k](std::string word){
            return word.length() > k;
        }
    );
}


void task5_2() {

    int numbers[10] {1, 2, 3, 4, 5, 6, 0, 7, 8, 9};    
    std::deque<int> d(std::begin(numbers), std::end(numbers));

    std::deque<int>::reverse_iterator find_iter = std::find(d.rbegin(), d.rend(), 0);
    
    if(*find_iter == 0){
        std::deque<int>::iterator iter = find_iter.base();
        iter--;
        d.erase(iter);
        std::cout << "Последний ноль успешно удален" << std::endl;
    }else{
        std::cout << "В деке нету нуля" << std::endl;
    }

    std::deque<int>::iterator iter;
    for(iter = d.begin(); iter!=d.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}


void task8_1() {
    std::list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<double> v;
    
    struct Average {
        double operator() (double a, double b) {
            return (a+b) / 2.0;
        }
    };
    Average average;

    std::adjacent_difference(l.begin(), l.end(), std::back_inserter(v), average);
    v.erase(v.begin());

    for(std::vector<double>::iterator iter = v.begin(); iter!=v.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}


void task9_1() {
    std::srand(std::time(0));
    int k;

    std::vector<int> v0{1, 2, 3};

    std::cout << "Введите сколько векторов создать, вектора будут случайной длины от 5 до 10 и со случайчными элементами" << std::endl;
    std::cin >> k;

    std::vector<std::vector<int>> vi;

    for(int i = 0; i < k; i++) {
        int lenght = 5 + std::rand() % 6;
        std::vector<int> vector;

        for(int j = 0; j < lenght; j++) {
            int rand_elem = std::rand() % 10;
            vector.push_back(rand_elem);
        }

        vi.push_back(vector);
    }

    std::cout << "Список сформированных векторов: " << std::endl;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < vi[i].size(); j++) {
            std::cout << vi[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::set<int> set0(v0.begin(), v0.end());
    int count = 0;
    for(int i = 0; i < k; i++) {
        std::set<int> set_i(vi[i].begin(), vi[i].end());
        if(std::includes(set_i.begin(), set_i.end(), set0.begin(), set0.end())) {
            count++;
        }
    }
    std::cout << "Векторов с совпадающим содержимым - " << count << std::endl;
}


void task10_2() {
    std::vector<std::string> v{"APPLE", "FUN", "CAT", "ALPHABET", "ARRAY", "FOREHEAD"};

    std::map<char, int> m;

    for(int i = 0; i < v.size(); i++) {
        m[v[i][0]] += v[i].size();
    }

    for(std::map<char, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
        std::cout << iter->first << iter->second << std::endl;
    }

}



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
    case 6: task8_1(); break;
    case 7: task9_1(); break;
    case 8: task10_2(); break;
    
    default:
        break;
    }
}
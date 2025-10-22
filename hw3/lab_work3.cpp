#include "lab_work3.h"


Human::Human(Name names, int height): names(names), height(height){}
Human::Human(std::string name, int height): name(name), height(height){}



void Human::get_human_info(){
    std::cout << name << ", рост: " << height << std::endl;
}    

void Human::get_human_info_for_task2_2(){
    std::cout <<"Человек, с именем "<< names.toString() << ", и ростом: " << height << std::endl;
}    

void Human::print() {
    std::cout << name << ", рост: " << height << std::endl;

}    

void Human::set_name(std::string name) {
    this->name = name;
}

void Human::set_height(int height) {
    this->height = height;
}


Name::Name(std::string second_name, std::string personal_name, std::string patronymic): 
    second_name(second_name), personal_name(personal_name), patronymic(patronymic){};


void Name::set_second_name(std::string second_name) { this->second_name = second_name; }
void Name::set_personal_name(std::string personal_name) { this->personal_name = personal_name; }
void Name::set_patronymic(std::string patronymic) { this->patronymic = patronymic; }


bool contains_digits(std::string str) {
    for (char c : str) {
        if (std::isdigit(c)) {
            return true;
        }
    }
    return false;
}

Name input_create_name() {
    std::string second_name, personal_name, patronymic;
    
    std::cout << "Введите фамилию: ";
    std::cin >> second_name;
    if(std::cin.fail() || contains_digits(second_name)) {
        std::cout << "Ошибка ";
        exit(1);
    }
    
    std::cout << "Введите имя: ";
    std::cin >> personal_name;
    if(std::cin.fail() || contains_digits(personal_name)) {
        std::cout << "Ошибка ";
        exit(1);
    }
    
    std::cout << "Введите отчество: ";
    std::cin >> patronymic;
    if(std::cin.fail() || contains_digits(patronymic)) {
        std::cout << "Ошибка ";
        exit(1);
    }
    
    Name name = Name(second_name, personal_name, patronymic);
    std::cout << "Получился персонаж - " << name.toString() << std::endl;
    return name;
}


Human input_create_human() {
    Name name = input_create_name();
    
    int height;
    std::cout << "Введите рост: ";
    std::cin >> height;
    if(std::cin.fail()) {
        std::cout << "Ошибка!";
        exit(1);
    }
    Human human = Human(name, height);
    std::cout << "Вы создали " << name.toString() << " ростом " << height << std::endl;
    return human;
}


std::string Name::toString(){
    std::string result = second_name + " " + personal_name + " " + patronymic;
    return result;
}

void Name::print() {
    std::cout << toString() << std::endl;
}

City::City(std::string name): name(name){}
City::City(std::string name, const std::map<std::string, int>& road_value_dict): name(name), road_value_dict(road_value_dict){}


void City::set_new_city(std::string new_city) {
    this->name = new_city;
}


void City::set_new_road(std::string new_city, int road_distanse) {
    road_value_dict[new_city] = road_distanse;
}


void City::print() {
    std::cout << "Город " << name << " связан с городами:" << std::endl;
    
    if(road_value_dict.empty()){
        std::cout << "У этого города нету маршрутов" << std::endl;
    } else {
    for(auto it = road_value_dict.begin(); it != road_value_dict.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
    }
}


void task1_2() {
    Human Cleopatra("Клеопатра", 152);
    Human Pushkin("Пушкин", 167);
    Human Vladimir("Владимир", 189);
    Cleopatra.get_human_info();
    Pushkin.get_human_info();
    Vladimir.get_human_info();
    
    //Human abrakadabra = input_create_human();
}


void task1_3() {
    Name Cleopatra("Клеопатра");
    Name Pushkin("Пушкин", "Александр", "Сергеевич");
    Name Mayacowski("Маяковский", "Владимир");

    std::cout << Cleopatra.toString() << std::endl;
    std::cout << Pushkin.toString() << std::endl;
    std::cout << Mayacowski.toString() << std::endl;

    //Name abrakadabra = input_create_name();
}


void task2_2() {
    Human Cleopatra(Name("Клеопатра"), 152);
    Human Pushkin(Name("Пушкин", "Александр", "Сергеевич"), 167);
    Human Mayacowski(Name("Маяковский", "ВЛадимир"), 189);
    Cleopatra.get_human_info_for_task2_2();
    Pushkin.get_human_info_for_task2_2();
    Mayacowski.get_human_info_for_task2_2();
}

void task3_3() {    
    std::map<std::string, int> routesA = {{"B", 5}, {"D", 6},{"F", 1}};
    std::map<std::string, int> routesB = {{"A", 5}, {"C", 3}};
    std::map<std::string, int> routesC = {{"B", 3}, {"D", 4}};
    std::map<std::string, int> routesD = {{"A", 6}, {"C", 4}, {"E", 2}};
    std::map<std::string, int> routesE = {{"F", 2}};
    std::map<std::string, int> routesF = {{"B", 1}, {"E", 2}};

    City A("A", routesA);
    City B("B", routesB);
    City C("C", routesC);
    City D("D", routesD);
    City E("E", routesE);
    City F("F", routesF);

    A.print();
    B.print();
    C.print();
    D.print();
    E.print();
    F.print();
    
}
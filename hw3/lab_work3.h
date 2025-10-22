#ifndef LAB_WORK3_H
#define LAB_WORK3_H
#include <iostream>
#include <string>
#include <vector>
#include <map>


class Name {
private:
    std::string second_name;
    std::string personal_name;
    std::string patronymic;

public:
    Name(std::string second_name="", std::string personal_name="", std::string patronymic="");
    
    void set_second_name(std::string second_name);
    void set_personal_name(std::string personal_name);
    void set_patronymic(std::string patronymic);

    std::string toString();
    void print();
};



class Human {
private:
    std::string name;
    Name names;
    int height;
public:
    Human(Name names, int height=0);
    Human(std::string name = "", int height=0);

    void get_human_info();
    void get_human_info_for_task2_2();
    void print();

    void set_name(std::string name);
    void set_height(int height);
};



class City {
private:
    std::string name;
    std::map<std::string, int> road_value_dict; 

public:
    City(std::string name="");
    City(std::string name, const std::map<std::string, int>& road_value_dict);

    void print();
    void set_new_city(std::string new_city);
    void set_new_road(std::string new_city, int road_distance);
};
bool contains_digits(std::string str);
Human input_create_human();
Name input_create_name();

void task1_2();
void task1_3();
void task2_2();
void task3_3();

#endif
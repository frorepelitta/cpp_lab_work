#ifndef NAME_H
#define NAME_H

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


#endif
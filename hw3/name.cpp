#include "lab_work3.h"
#include "human.h"
#include "name.h"



Name::Name(std::string second_name, std::string personal_name, std::string patronymic): 
    second_name(second_name), personal_name(personal_name), patronymic(patronymic){};


void Name::set_second_name(std::string second_name) { this->second_name = second_name; }
void Name::set_personal_name(std::string personal_name) { this->personal_name = personal_name; }
void Name::set_patronymic(std::string patronymic) { this->patronymic = patronymic; }


std::string Name::toString(){
    std::string result = second_name + " " + personal_name + " " + patronymic;
    return result;
}

void Name::print() {
    std::cout << toString() << std::endl;
}



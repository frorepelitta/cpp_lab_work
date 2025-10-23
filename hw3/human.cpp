#include "lab_work3.h"
#include "human.h"
#include "name.h"



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
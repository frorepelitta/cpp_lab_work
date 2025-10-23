#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "name.h"



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


#endif
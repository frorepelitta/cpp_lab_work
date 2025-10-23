#ifndef CITY_H
#define CITY_H
#include <iostream>
#include <string>
#include <vector>
#include <map>


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



#endif
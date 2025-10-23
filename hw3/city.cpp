#include "city.h"



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
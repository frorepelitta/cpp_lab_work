#include "city.h"



City::City(std::string name): name(name){}
City::City(std::string name, const std::map<std::string, int>& road_value_dict): name(name), road_value_dict(road_value_dict){}


void City::set_new_city(std::string new_city) {
    this->name = new_city;
}


void City::set_new_road(std::string new_city, int road_distanse) {
    road_value_dict[new_city] = road_distanse;
}


City City::create_city_with_roads() {
    std::string city_name;
    std::cout << "Введите название нового города - ";
    std::cin >> city_name;
    
    int road_count;
    std::cout << "Введите с какмм количеством городов он связан - ";
    std::cin >> road_count;
    
    if (std::cin.fail() || road_count < 0) {
        std::cout << "Ошибка " << std::endl;
        exit(1);
    }
    
    City new_city(city_name);
    
    for (int i = 0; i < road_count; i++) {
        std::string connected_city;
        int distance;
        
        std::cout << "Введите название города - " << (i + 1) << ": ";
        std::cin >> connected_city;
        
        std::cout << "Введите расстояние до города - " << connected_city << ": ";
        std::cin >> distance;
        
        if (std::cin.fail() || distance < 0) {
            std::cout << "Ошибка" << std::endl;
            exit(1);
        }
        
        new_city.set_new_road(connected_city, distance);
    }
    
    std::cout << "Город " << city_name << " создан" << std::endl;
    return new_city;
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
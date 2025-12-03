#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>  
#include <cstdlib>
#include <vector>
#include <sstream> 

class work_with_files {
public:
    static void fill_binary_file_with_random_digits(std::string& filename);  
    static void read_binary_file(std::string& filename);
    static double multiply_negative_odd_digits(std::string& filename);

    static std::vector<std::vector<int>> copy_to_matrix(const std::string& filename, int n);
    static int get_user_input_n();
    static void print_matrix(const std::vector<std::vector<int>>& matrix);
    static void swap_min_max_in_columns(std::vector<std::vector<int>>& matrix);

    static void fill_text_file_with_random_digits(std::string& filename, int flag = 0);
    static double sum_of_squares_from_text_file(std::string& filename);
    static void read_text_file(std::string& filename);

    static double multiply_elements(std::string& filename);

    static void copy_lines_by_length(std::string& source_file, std::string& destintaion_file, int m);
};

#endif
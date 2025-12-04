#include "func.h"


void work_with_files::fill_binary_file_with_random_digits(std::string& filename){
    std::ofstream file(filename, std::ios::binary);
    if(!file.is_open()) {
        std::cout << "Ошибка" << std::endl;
        return ; 
    }
    std::srand(time(nullptr));
    
    int count = rand()%41 + 10;
    file.write(reinterpret_cast<const char*>(&count), sizeof(count));
    
    for(int i = 0; i < count; i++) {
        int digit = (rand() % 101) - 50;
        file.write(reinterpret_cast<const char*>(&digit), sizeof(digit));
    }
    file.close();
}


void work_with_files::read_binary_file(std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if(!file.is_open()) {
        std::cout << "Ошибка открытия файла для чтения" << std::endl;
        return;
    }
    
    int count;
    file.read(reinterpret_cast<char*>(&count), sizeof(count));
    
    std::cout << "В файле " << count << " чисел: ";
    
    for(int i = 0; i < count; i++) {
        int digit;
        file.read(reinterpret_cast<char*>(&digit), sizeof(digit));
        std::cout << digit << " ";
    }
    std::cout << std::endl;
    file.close();
}


double work_with_files::multiply_negative_odd_digits(std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if(!file.is_open()) {
        std::cout << "Ошибка открытия файла для чтения" << std::endl;
        return 1.0;
    }

    int count;
    double multiply = 1;
    file.read(reinterpret_cast<char*>(&count), sizeof(count));

    for(int i = 0; i < count; i++) {
        int digit;
        file.read(reinterpret_cast<char*>(&digit), sizeof(digit));
        if ((digit < 0) and (digit % 2 != 0)) {
            multiply *= digit;
        }
    }
    file.close();
    return multiply;
}


std::vector<std::vector<int>> work_with_files::copy_to_matrix(const std::string& filename, int n) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла: " << filename << std::endl;
        return std::vector<std::vector<int>>();
    }
    int ignore;
    file.read(reinterpret_cast<char*>(&ignore), sizeof(ignore));
    
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            if (file.read(reinterpret_cast<char*>(&value), sizeof(value))) {
                matrix[i][j] = value;
            }
        }
    }
    
    file.close();
    return matrix;
}


int work_with_files::get_user_input_n() {
    int n;
    while (true) {
        std::cout << "\nВведите размер квадратной матрицы n (n > 0): ";
        
        if (!(std::cin >> n)) {
            std::cout << "Ошибка ввода. Пожалуйста, введите целое число." << std::endl;
        } else if (n <= 0) {
            std::cout << "Размер матрицы должен быть положительным числом. Попробуйте снова." << std::endl;
        } else {
            break;
        }
    }
    return n;
}


void work_with_files::print_matrix(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) {
        std::cout << "Матрица пуста." << std::endl;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << "|";
        for (int j = 0; j < n; j++) {
            printf("%5d|", matrix[i][j]);
        }
        std::cout << std::endl;
        std::cout << std::string(6 * n + 1, '-') << std::endl;
    }
}


void work_with_files::swap_min_max_in_columns(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) {
        std::cout << "Матрица пуста." << std::endl;
        return;
    }
    
    for (int col = 0; col < n; col++) {
        int min_row = 0;
        int max_row = 0;
        int min_val = matrix[0][col];
        int max_val = matrix[0][col];
        
        for (int row = 1; row < n; row++) {
            if (matrix[row][col] < min_val) {
                min_val = matrix[row][col];
                min_row = row;
            }
            if (matrix[row][col] > max_val) {
                max_val = matrix[row][col];
                max_row = row;
            }
        }
        
        if (min_row != max_row) {
            std::swap(matrix[min_row][col], matrix[max_row][col]);
        }
    }
}



void work_with_files::fill_text_file_with_random_digits(std::string& filename, int flag){
    std::ofstream file(filename);
    if(!file.is_open()) {
        std::cout << "Ошибка" << std::endl;
        return ; 
    }
    std::srand(time(nullptr));
    
    int count = rand()%11 + 5;
        
    if (flag == 0) {
        int num_rows = rand() % 5 + 2;  
        
        for (int row = 0; row < num_rows; row++) {
            int nums_in_row = rand() % 5 + 1;  
            
            for (int i = 0; i < nums_in_row; i++) {
                int digit = (rand() % 11) + 1;  

                file << digit;
                if (i < nums_in_row - 1) {
                    file << " "; 
                }
                std::cout << digit << " ";
            }
            file << std::endl;  
            std::cout << std::endl;
        }
    } else{
        int count = rand() % 11 + 5;  
        
        for (int i = 0; i < count; i++) {
            int digit = (rand() % 21) - 10;
            file << digit << std::endl;
            std::cout << digit << std::endl;
        }
    }
    file.close();
}


void work_with_files::read_text_file(std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия текстового файла для чтения: " << filename << std::endl;
        return;
    }
    
    std::string line;
    int line_number = 1;
    while (std::getline(file, line)) {
        std::cout << line << " ";
    }
    std::cout << std::endl;
    file.close();
}


double work_with_files::sum_of_squares_from_text_file(std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Ошибка открытия текстового файла: " << filename << std::endl;
        return 0;
    }
    
    double sum_of_squares = 0;
    std::string line;
        
    while (std::getline(file, line)) {
        if (!line.empty()) {
                int number = std::stoi(line);
                sum_of_squares += number * number;

        }
    }
    file.close();
    return sum_of_squares;
}


double work_with_files::multiply_elements(std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Ошибка открытия текстового файла: " << filename << std::endl;
        return 0;
    }
    
    double result = 1;
    std::string line;
        
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int number;
        
        while (iss >> number) {
            result *= number;
        }
    }
    
    file.close();
    return result;
}



void work_with_files::copy_lines_by_length(std::string& source_file, std::string& destintaion_file, int m) {
    std::ifstream source(source_file);
    std::ofstream dest(destintaion_file);
    
    if (!source || !dest) {
        std::cout << "Ошибка открытия файлов" << std::endl;
        return;
    }
    
    std::string line;
    
    while (std::getline(source, line)) {
        if (line.length() == m) {
            dest << line << std::endl;
            std::cout << "Скопирована строка: " << line << " (длина: " << m << ")" << std::endl;
        }
    }
    
    source.close();
    dest.close();
}
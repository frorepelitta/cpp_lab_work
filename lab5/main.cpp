#include "func.h"

int main() {
    work_with_files things;
    int choice;
    
    while (true) {
        std::cout << "\nВыберите задание" << std::endl;
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                std::string filename = "file.bin";
                things.fill_binary_file_with_random_digits(filename);
                things.read_binary_file(filename);
                std::cout << "Произведение нечетных отрицательных чисел файла: " 
                          << things.multiply_negative_odd_digits(filename) << std::endl;
                break;
            }
            
            case 2: {
                std::string filename = "file.bin";
                things.fill_binary_file_with_random_digits(filename);
                
                int n = things.get_user_input_n();
                std::vector<std::vector<int>> matrix = things.copy_to_matrix(filename, n);
                
                std::cout << "Исходная матрица:" << std::endl;
                things.print_matrix(matrix);
                
                things.swap_min_max_in_columns(matrix);
                
                std::cout << "Матрица после swap" << std::endl;
                things.print_matrix(matrix);
                break;
            }
            
            case 4: {
                std::string file = "nums.txt";
                things.fill_text_file_with_random_digits(file, 1); // в столбец
                std::cout << "Сумма квадратов элементов файла: " 
                          << things.sum_of_squares_from_text_file(file) << std::endl;
                break;
            }
            
            case 5: {
                std::string file = "nums.txt";
                things.fill_text_file_with_random_digits(file, 0); // в строку
                std::cout << "Произведение элементов файла: " 
                          << things.multiply_elements(file) << std::endl;
                break;
            }
            
            case 6: {
                std::string source_file = "source.txt";
                std::string destination_file = "destination.txt";
                
                std::cout << "Содержимое исходного файла:" << std::endl;
                things.read_text_file(source_file);
                
                int m;
                std::cout << "Введите длину строки для копирования (m): ";
                std::cin >> m;
                things.copy_lines_by_length(source_file, destination_file, m);
                
                std::cout << "\nСодержимое нового файла:" << std::endl;
                things.read_text_file(destination_file);
                break;
            }
                default: {
                    std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
                    break;
            }
        }
        break;
    }
    return 0;
}




/**
 * Данная бибилиотека содержит классы и константы для работы с опциями приложения


 * Область имен:
 * ---------
 *     * opt - Данная область содержит классы и константы для работы с опциями приложения
 * 
 * 
 * Константы:
 * ---------
 * 
 * 
 * Классы:
 * ------
 *     * Options - Данный класс необходим для работы с параметрами приложения
 * 
 * Структуры:
 * ------
 *     * File_options - Данный структура необходима для хранения параметоров приложения
 * 
 * 
*/


//#pragma once
#include "./Options_file.cpp"



#include <iostream>
using namespace std;



namespace opt{

/**
 * @brief 
 * Данный класс необходим для работы с параметрами приложения
*/
class Options{
private:
    string roat_file ; // Путь до файла с параметрами приложения

    // Опции приложения выкачаные из файла параметров приложения 
    File_options file_options = File_options();
    

public:
    /**
     * @brief 
     * Конструктор для инициализации объекта класса Options
     * @param 
     * roat_file - путь до файла с параметрами приложения
     */
    Options(string roat_file = "путь до файла параметров по умолчанию"){
        this->roat_file = roat_file;
    };


    /**
     * @brief 
     * Загрузка параметров из файла параметров и возращение загруженых опций приложения
     * @return 
     * map<string, float>  - словарь с опциями приложения
     */
    File_options load_options(){
        // Выполняем загрузку параметров из файла и обновляем file_options (this->file_options)
        return this->file_options;
    }

    /**
     * @brief 
     * Установка и запись новых параметров приложения
     * @param 
     * option  - новые параметры приложения
     */
    void set_options(File_options option){
        // Производим проверку параметров и запись в файл 
        this->file_options = option;

    }

    
};

};




#define DEBUG // Для тестирования модуля


#ifdef DEBUG 
/**
 * @brief 
 * Функия для тестирования модуля
 */
int main(int argc, char* argv[]){
    system("chcp 65001");

    // экземпляр класса параметров приложения
    opt::Options program_option = opt::Options();
    // загрузка параметров
    opt::File_options options_program = program_option.load_options();

    // Смотрим на параметры
    cout << "some_options: " << options_program.some_options << "\n";

    // Меняем параметры
    options_program.some_options = 8;

    // Устанавливаем новые параметры
    program_option.set_options(options_program);

    // Проверяем изменение параметров
    options_program = program_option.load_options();

    // Смотрим на параметры
    cout << "some_options: " << options_program.some_options << "\n";



    system("pause");
}


#endif 

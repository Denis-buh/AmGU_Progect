



/**
 * Данный модуль содержит необходим для реализации объекта в котором будут хранится параметры приложения

 * 
 * 
 * Константы:
 * ---------
 * 
 * 
 * Структуры:
 * ------
 *     * File_options - Данный структура необходима для храниения параметоров приложения
 * 
 * 
*/


#pragma once



#include <iostream>
using namespace std;



namespace opt{
/**
 * @brief 
 * Структора в которой находятся параметры приложения
 * Содержит параметры по умолчанию
 */
struct File_options{
    // Пример параметра
    float some_options =  1.898;
};

};


// #define DEBUG // Для тестирования модуля


#ifdef DEBUG 
/**
 * @brief 
 * Функия для тестирования модуля
 */
int main(int argc, char* argv[]){
    system("chcp 65001");

    // Создаем объект с параметрами приложения
    opt::File_options file_options = opt::File_options();

    cout << "Значение параметра 'some_options': " << file_options.some_options << "\n"; 



    system("pause");
}


#endif 

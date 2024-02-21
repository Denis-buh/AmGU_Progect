



#include <iostream>
#include <map>
// Подключаем библиотеку параметров
#include "Options\options.cpp"
// Подключаем библиотеку графического дизайна
#include "GUI\GUI.h"
// Подключаем библиотеку для работы с файлами
#include "Courses\courses.h"

using namespace std;


int main(int argc, char* argv[]){
    system("chcp 65001");
    // argc - количество аргументов
    /*argv - массив аргументов
        Первым аргументом массива всегда будет путь к исполняему файлу exe
        Последующие аргументы - то что передано командной строке (файлы по асоциациям/открытиям с помощью )
    */

    // Создаем экземпляр класса параметров приложения
    opt::Options program_option = opt::Options();
    // Загрузка параметров
    opt::File_options program_options = program_option.load_options();


    // Создаем экземпляр класса графического дизайна приложения
    // gui::GUI program_gui = gui::GUI();
    

    cout << "Hello word\n";
    
    system("pause");
}
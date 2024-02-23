



#include <iostream>
#include <QApplication>
#include <QMessageBox>


// Времено вырезано 
// Подключаем библиотеку параметров
// #include "Options\options.cpp"
// Подключаем библиотеку графического дизайна
#include "GUI\GUI.cpp"
//#include "GUI\MainWindow\Main_Window.h"
// Подключаем библиотеку для работы с файлами
//#include "Courses\courses.h"


using namespace std;


/*
Структура в которой будут хранится значения типа:
    "Имя окна"{
        "название элемента интерфейса окна" = "функция которая должна быть подвязана на интерфейс"
    }
*/



class Program: public GUI{
private:

protected:
    // locale // локализация
    // options // опции приложения
    // list_tab // список вкладок (вкладки - специальный класс/структура)



public:
    /*void set_locale(){
        // Установка глобальной локализации для программы
        GUI.set_locale();
    }*/

    /*void set_optios(){
        // Установка глобальных опций для программы
        GUI.set_optios();
    }*/

    void bind_command(){
        // Пишем какие функции на какой элемент итерфейса;

        // Бинды функций на интерфейс приложения
        GUI::bind_command();
    }

    void closeEvent(QCloseEvent *event){
        // Реакция на закрытия окна (тут будем юзера упрашивать сохранить файлы)
        cout << "Close window\n";

    }

    void open_file(string roat_file){
        // Открываем файл и создаем новую вкладку
    }

    void close_file(){
        // Закрываем вкладку приложения и сохраняем файл
    }

};








int main(int argc, char* argv[]){
    system("chcp 65001");

    QApplication applicate(argc, argv);


    // Времено вырезано 
    // Создаем экземпляр класса параметров приложения
    //opt::Options program_option = opt::Options();
    // Загрузка параметров
    //opt::File_options program_options = program_option.load_options();

    
    // Создаем основное окно программы
    Program wind;
    // Показываем основное окно программы
    wind.show();

    return applicate.exec();
    
}

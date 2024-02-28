



#include <iostream>
#include <QApplication>
//#include <QMessageBox>
//#include <typeinfo>

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
    struct Command_for_"Имя окна"{
        "название элемента интерфейса окна" = "функция которая должна быть подвязана на элемент интерфейса"
    }
*/
struct coomand_for_bild{
    /*
     Данная структура необходима для хранения команд для окон
    */
    struct Command_for_MainWindow{
        // Для основного окна
        void (*options_all)();
    };
    Command_for_MainWindow MainWindow;

};


class Program: public GUI{
private:

protected:
    // locale // локализация
    // options // опции приложения
    // list_tab // список вкладок (вкладки - специальный класс/структура)

public:
    /*void set_optios(){
        // Установка глобальных опций для программы
        GUI.set_optios();
    }*/

    /*void set_locale(){
        // Установка глобальной локализации для программы
        GUI.set_locale();
    }*/

    void bind_command(coomand_for_bild binds){
        // Билдим функции на элементы итерфейса;
        GUI::bind_command(binds);
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
        cout << "call close_file\n";
    }

};



// Глобальный указатель на класс программы
Program* link_program = {nullptr};



int main(int argc, char* argv[]){
    system("chcp 65001");
    // cout <<  typeid(named).name() << "\n";

    QApplication applicate(argc, argv);

    // Времено вырезано 
    // Создаем экземпляр класса параметров приложения
    //opt::Options program_option = opt::Options();
    // Загрузка параметров
    //opt::File_options program_options = program_option.load_options();

    
    // Создаем основной класс программы
    Program  prog;
    // Ссылаем указатель на основной класс
    link_program = &prog;

    // БИНДИМ ИНТЕРФЕЙС //

    coomand_for_bild binds;
    // Лямбда функция для теста
    binds.MainWindow.options_all = [](){link_program->close_file();};
    // binds.MainWindow.options_all();


    // Добавляем команды на элементы интерфейс
    prog.bind_command(binds);

    // БИНДИМ ИНТЕРФЕЙС //


    // Показываем основное окно программы
    prog.show();

    return applicate.exec();
    
}

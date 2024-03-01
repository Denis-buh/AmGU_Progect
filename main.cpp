



#include <iostream>
#include <QApplication>
//#include <QMessageBox>
//#include <typeinfo>

// Времено вырезано 
// Подключаем библиотеку графического дизайна
#include "MainWindow\MainWindow.h"
// Подключаем библиотеку параметров
#include "Options\Options.h"

//#include "GUI\MainWindow\Main_Window.h"
// Подключаем библиотеку для работы с файлами
//#include "Courses\courses.h"


using namespace std;



struct TabWidget{

public:
    // Если виждет - параметры
    Options* Option_Widget = {nullptr};
    TabWidget(Options* Option_Widget){
        this->Option_Widget = Option_Widget;
    }

    void show(){
        if (this->Option_Widget == nullptr){
            this->Option_Widget->show();
        }
    }


};


class Program: public MainWindow{
private:

protected:
    // locale // локализация
    // options // опции приложения
    // list_tab // список вкладок (вкладки - специальный класс/структура)
    Options* dialog = {nullptr};

public:
    /*void set_optios(){
        // Установка глобальных опций для программы
        GUI.set_optios();
    }*/

    /*void set_locale(){
        // Установка глобальной локализации для программы
        GUI.set_locale();
    }*/

    void bind_command(){
        // Билдим функции на элементы итерфейса;
        MainWindow::bind_command();
    }

    void closeEvent(QCloseEvent *event){
        // Реакция на закрытия окна (тут будем юзера упрашивать сохранить файлы)
        cout << "Close window\n";

    }

    void test(){
        cout << "call test function\n";

        //dialog = new Options;
        TabWidget new_tab(new Options);
        //new_tab.Option_Widget = ();
        tabWidget->addTab(new_tab.Option_Widget, "test");
        new_tab.show();
    }


    /*void open_file(string roat_file){
        // Открываем файл и создаем новую вкладку
    }

    void close_file(){
        // Закрываем вкладку приложения и сохраняем файл
        cout << "call close_file\n";
    }*/

};



// Глобальный указатель на класс программы
Program* link_program = {nullptr};


// РЕАЛИЗУЕМ ФУНКЦИИ БИНДА ИНТЕРФЕЙСА //
// Основное окно
void MainWindow::options_all_clicked(){
    link_program->test();
}


int main(int argc, char* argv[]){
    //system("chcp 65001");
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

    // Биндим интерфейс всей программы
    prog.bind_command();



    // Показываем основное окно программы
    prog.show();

    return applicate.exec();
    
}





#include <iostream>
#include <QApplication>
#include <list>
#include <map>
#include <string>
//#include <QtWidgets/QS>
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


// Структура вкладки
struct Tab{
public:
    // Интерфейс вкладки //
    // Если вкладка - параметры
    Options* Option_Widget = {nullptr};
    // Имя вкладки
    string* name_tab = {nullptr};
    // Создаем вкладку
    Tab(Options* Option_Widget, string* name_tab){
        this->Option_Widget = Option_Widget;
        this->name_tab = name_tab;

    }
    // Убиваем вкладку
    ~Tab(){

        delete this->Option_Widget;
        delete this->name_tab;

    }
    // Показываем вкладку
    void show(){
        if (this->Option_Widget == nullptr){
            this->Option_Widget->show();
        }
    }

    // Проверяем каково типа эта вкладка
    string type(){
        if (this->Option_Widget != nullptr) {return "option";}
    }

};



class Program: public MainWindow{
private:

protected:
    // locale // локализация
    // options // опции приложения
    list <Tab*> Tab_list; // список вкладок (вкладки - специальный класс/структура)

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

    /*void closeEvent(QCloseEvent *event){
        // Реакция на закрытия окна (тут будем юзера упрашивать сохранить файлы)
        cout << "Close window\n";

    }*/

    void test(){cout << "call test function\n";}



    /*
    Открытие файлов в программе
    */
    void open_file(string roat_file){
        cout << "Open tab: " << roat_file << "\n";
        // Если пользователь решился открыть параметры
        if (roat_file == "option"){
            string* name =  new string("Опции приложения: " + to_string(Tab_list.size()));
            char name2[255];
            // Из строка делаем массив символов
            strcpy(name2, name->c_str());

            // Делаем новую вкладку
            Tab* new_tab_widget = new Tab(new Options, name);
            //Tab new_tab_widget(new Options, name);
            // Добавляем вкладку в список вкладок
            Tab_list.push_back(new_tab_widget);
            // Отображаем вкладку на интерфейсе
            tabWidget->addTab(new_tab_widget->Option_Widget, name2);
            // Отображаем интерфейс вкладки
            new_tab_widget->show();
        }

    }

    void close_file(int index_tab){
        // Закрываем вкладку приложения и сохраняем файл
        cout << "close tab with index = " << index_tab << "\n";

        // Ловим вкладку
        int i = 0; // Переменная счетчик

        for (auto ind3 = Tab_list.begin(); ind3 != Tab_list.end(); ind3++){
            // Проверка на нужную на вкладку
            Tab* tab3 = *ind3;
            cout << *tab3->name_tab << "\n";
        }
        cout << "\n";


        auto ind = Tab_list.begin(); // Индекс вкладки по списку
        for (; ind != Tab_list.end(); ind++){
            // Проверка на нужную на вкладку
            if (i == index_tab){break;}
            i += 1;
        }

        // Провиряем что эта за вкладка и просим сохранить изменения
        Tab* tab = *ind; // Указатель на вкладку
        // Если это параметры
        if (tab->type() == "option"){
            // Анигилируем вкладку (позже бутем просить сохрания)
            // Удаляем вкладку с интерфейса окна
            tabWidget->removeTab(index_tab);
            // Удаляем вкладку из списка
            Tab_list.erase(ind);
            // Удаляем вкладку
            delete tab;
        }


        cout << "\n";
        for (auto ind39 = Tab_list.begin(); ind39 != Tab_list.end(); ind39++){
            // Проверка на нужную на вкладку
            Tab* tab39 = *ind39;
            cout << *tab39->name_tab << "\n";
        }
    }

};



// Глобальный указатель на класс программы
Program* link_program = {nullptr};


// РЕАЛИЗУЕМ ФУНКЦИИ БИНДА ИНТЕРФЕЙСА //
// Основное окно
void MainWindow::options_all_clicked(){
    link_program->open_file("option");
}

void MainWindow::close_tab_clicked(int index){
    link_program->close_file(index);

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

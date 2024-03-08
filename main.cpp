



#include <iostream>
#include <QApplication>
#include <list>
#include <map>
#include <string>
//#include <QtWidgets/QS>
//#include <QMessageBox>
//#include <typeinfo>
#include <QDebug>

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
    const char* name_tab = {nullptr};



    // Создаем вкладку
    Tab(Options* Option_Widget, const char* name_tab){
        // Виджет
        this->Option_Widget = Option_Widget;
        // Имя вкладки
        this->name_tab = name_tab;

    }

    // Убиваем вкладку
    ~Tab(){

        delete this->Option_Widget;
        //delete this->name_tab;

    }
    // Показываем вкладку
    void show(){
        if (this->Option_Widget == nullptr){
            this->Option_Widget->show();
        }
    }

    void append_watthis(){

    }

    // Проверяем каково типа эта вкладка
    string type(){
        if (this->Option_Widget != nullptr)  {return "option";}
    }

};



class Program: public MainWindow{
private:
    /*
    Дает ключь которого не существует в словаре
    */
    int get_key_for_dict(){
        int key_for_dict = 0;
        while(true){
            bool flag = true;
            // Проверка по словарю на существование ключа
            for (auto i : dict_tab){
                if (i.first == key_for_dict){
                    // Такой ключ есть
                    flag = false;
                    break;
                }
            }
            // Такого ключа нет
            if (flag){
                break;
            }
            // Если такой ключь уже есть в словаре
            key_for_dict += 1;
        }
        return key_for_dict;
    }

protected:
    // locale // локализация
    // options // опции приложения

    map<const int, Tab*> dict_tab;

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
        cout << "BEFORE OPEN FILE\n";
        cout << "Open tab: " << roat_file << "\n";

        for ( auto& tab : dict_tab){
            cout << tab.first << "\t" << tab.second << "\n";
        };
        cout << "\n";

        // Если пользователь решился открыть параметры
        if (roat_file == "option"){
            // Имя вкладки
            string name_tab = string("Опции приложения: " + to_string(dict_tab.size()));
            const char* name_tab2 = {name_tab.c_str()};

            // Опозавательный знак вкладки (для словаря + индекс вкладки)
            int index_name = this->get_key_for_dict();
            // Опозавательный знак переводим в массив символов
            const char* name2 = to_string(index_name).c_str();


            // Добавляем вкладку в словарь вкладок (сделать провеку на пустоту ключа
            dict_tab[index_name] = new Tab(new Options, name2);
            Tab* new_tab_widget =  dict_tab[index_name];

            // Добавляем вкладку на виджет вкладок
            tabWidget->addTab(new_tab_widget->Option_Widget, QString(name_tab2/*"Опции приложения"*/));

            // Позиция созданой вкладки (необходима для крепления обвесов)
            int index_tab = tabWidget->indexOf(new_tab_widget->Option_Widget);

            // Добавляем опозавательный знак вкладки
            tabWidget->setTabWhatsThis(index_tab, QString(name2));

            // Коментарий к вкладки
            tabWidget->setTabToolTip(index_tab, QString(name2/*"this options (эти опции)"*/) );

            // Отображаем интерфейс вкладки
            new_tab_widget->show();

            for ( auto& tab : dict_tab){
                cout << tab.first << "\t" << tab.second << "\n";
            };
            cout << "\n";

        }
        cout << "AFTER OPEN FILE\n";

    }

    void close_file(int index_tab){
        // Закрываем вкладку приложения и сохраняем файл
        cout << "BEFORE DELETE TAB\n";

        // Опозавательный знак вкладки
        const char* flag = tabWidget->tabWhatsThis(index_tab).toStdString().c_str();

        int flag_index;
        // Блок в котором масив символов переводим в строку
        {
            // Строка в которую засунем масив символов
            string nu = "";
            int i = -1;
            char cha;
            do{
                i += 1;
                cha = flag[i];
                nu += cha;
            }
            while(cha != '\0');
            flag_index = stoi(nu);
        }


        // Получаем вкладу
        Tab* tab = dict_tab[flag_index];


        // Если это параметры
        if (tab->type() == "option"){
            // Анигилируем вкладку (позже бутем просить сохрания)
            // Удаляем вкладку с интерфейса окна
            tabWidget->removeTab(index_tab);
            cout << "Before deleting a tab\n";
            for ( auto& tab : dict_tab){
                cout << tab.first << "\t" << tab.second << "\n";
            }

            cout << "\n";

            // Удаляем вкладку из словаря
            dict_tab.erase(flag_index);

            cout << "After deleting a tab\n";
            for ( auto& tab : dict_tab){
                cout << tab.first << "\t" << tab.second << "\n";
            }
           // cout << "index_new_tab = " << dict_tab.size() << "\n";
            cout << "\n";

            // Удаляем вкладку
            delete tab;
        }

        cout << "AFTER DELETE TAB\n";
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
    setlocale(LC_ALL, "");
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

    // Биндим интерфейс всей программы
    prog.bind_command();



    // Показываем основное окно программы
    prog.show();

    return applicate.exec();
    
}

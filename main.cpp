



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
        this->Option_Widget = Option_Widget;
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
    map<const char*, Tab*> dict_tab;

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
        //cout << "Open tab: " << roat_file << "\n";
        // Если пользователь решился открыть параметры
        if (roat_file == "option"){
            // Определяем индекс вкладки будующей вкладки
            const int index_new_tab = dict_tab.size();


            // Имя вкладки
            string name_tab = "Опции приложения: " + to_string(index_new_tab);
            // Из строки делаем массив символов и засовываем его в созданый массив
            const char* name2 = {name_tab.c_str()};
           //strcpy(name2, name_tab.c_str());

            // Создаем новую вкладку
            //Tab* new_tab_widget = new Tab(new Options, name2);

            // Добавляем вкладку в словарь вкладок
            // Tab_list.push_back(new_tab_widget);
            dict_tab[name2] = new Tab(new Options, name2);
            Tab* new_tab_widget =  dict_tab[name2];

            // Добавляем вкладку на виджет вкладок
            tabWidget->addTab(new_tab_widget->Option_Widget, name2);

            // Добавляем штуку по которой будем ловить вкладку
            tabWidget->setTabWhatsThis(index_new_tab,  QString(name2));

            // Коментарий к вкладки
            tabWidget->setTabToolTip(index_new_tab, QString("this options (эти опции)") );

            // Отображаем интерфейс вкладки
            new_tab_widget->show();

            for ( auto& product : dict_tab){
                // product - элемент словаря (пара ключь -> значение)
                // product.first - ключь
                // product.second - значение по ключю (Аналог products[product.first])
                cout << &product.first << "\t" << product.second << "\n";
            };


        }

    }

    void close_file(int index_tab){
        // Закрываем вкладку приложения и сохраняем файл
        //cout << "close tab with index = " << index_tab << "\n";
        //auto res = tabWidget->tabText(index_tab);
        //qDebug() << res;

        //cout << "Tab name: " << (tabWidget->tabText(index_tab)).toStdString().c_str() << "\n";
        //cout << "Flag: " <<  tabWidget->tabWhatsThis(index_tab).toStdString().c_str() << "\n";

        const char* flag = tabWidget->tabWhatsThis(index_tab).toStdString().c_str();


        Tab* tab = dict_tab[flag];
        // Если это параметры
        if (/*tab->type() == "option"*/true){
            // Анигилируем вкладку (позже бутем просить сохрания)
            // Удаляем вкладку с интерфейса окна
            tabWidget->removeTab(index_tab);

            for ( auto& product : dict_tab){
                // product - элемент словаря (пара ключь -> значение)
                // product.first - ключь
                // product.second - значение по ключю (Аналог products[product.first])
                cout << &product.first << "\t" << product.second << "\n";
            };
            // Удаляем вкладку из списка
            dict_tab.erase(flag);
            for ( auto& product : dict_tab){
                // product - элемент словаря (пара ключь -> значение)
                // product.first - ключь
                // product.second - значение по ключю (Аналог products[product.first])
                cout << &product.first << "\t" << product.second << "\n";
            };
            // Удаляем вкладку
            delete tab;
        }

        //cout << tab_widget->name_tab << "\n";

        /*// Ловим вкладку
        int i = 0; // Переменная счетчик

        for (auto ind3 = Tab_list.begin(); ind3 != Tab_list.end(); ind3++){
            // Проверка на нужную на вкладку
            Tab* tab3 = *ind3;
            cout << tab3->name_tab << "\n";
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
            cout << tab39->name_tab << "\n";
        }*/
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
    //cout <<
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





#include <iostream>
#include <QApplication>
#include <map>
#include <string>
//#include <QDrag>


// Подключаем библиотеку графического дизайна
#include "MainWindow\MainWindow.h"
// Подключаем библиотеку параметров
#include "Options\Options.h"

// Подключаем библиотеку для работы с файлами
//#include "Courses\courses.h"


using namespace std;


// Структура вкладки
struct Tab{
public:
    // Интерфейс вкладки //
        // Если вкладка - параметры
        Options* Option_Widget = {nullptr};

    // Опознавательный знак вкладки
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
        delete this->name_tab;
    }

    // Показываем вкладку
    void show(){
        if (this->Option_Widget == nullptr)  {this->Option_Widget->show();}
    }

    // Проверяем каково типа эта вкладка
    string type(){
        if (this->Option_Widget != nullptr)  {return "option";};
    }
    const char get_name()  {return *name_tab;}
};



class Program: public MainWindow{
private:
    /* Дает ключь которого не существует в словаре */
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
            if (flag)  {break;}
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
    /* Инициализация класса */
    Program(){
        // Биндим интерфейс всей программы
        this->bind_command();
        this->set_optios();
        this->set_locale();
    }

    /* Установка параметров приложения */
    void set_optios()  {cout << "set_optios\n";}

    /* Установка локализации для главного окна программы*/
    void set_locale()  {cout << "set_locale\n";}


    /* */
    void dragEnterEvent(QDragEnterEvent *event){
        cout << "iugigiogogoi\n";
        //const QMimeData mine = event->mimeData();
        //const QMimeData mime = event.mimeData();
        // Если перемещаются ссылки
        //if (mime.thasUrls()){
            // Разрешаем
            //event->acceptProposedAction();}
    }

    /* Открытие файлов/вкладок в программе */
    void open_file(string roat_file){

        // Если пользователь решился открыть параметры
        if (roat_file == "option"){
            // Опозавательный знак вкладки (для словаря + индекс вкладки)
            int index_name = this->get_key_for_dict();
            // Опозавательный знак переводим в массив символов
             const char* name2 = to_string(index_name).c_str();


            // Добавляем вкладку в словарь вкладок (сделать провеку на пустоту ключа
            dict_tab[index_name] = new Tab(new Options, name2);
            Tab* new_tab_widget =  dict_tab[index_name];

            // Добавляем вкладку на виджет вкладок
            tabWidget->addTab(new_tab_widget->Option_Widget, QString("Опции приложения"));

            // Позиция созданой вкладки (необходима для крепления обвесов)
            int index_tab = tabWidget->indexOf(new_tab_widget->Option_Widget);

            // Добавляем опозавательный знак вкладки
            tabWidget->setTabWhatsThis(index_tab, QString(name2));

            // Коментарий к вкладки
            tabWidget->setTabToolTip(index_tab, QString(name2/*"Вкладка опций приложения. Необходима для изменения параметров приложения"*/) );

            // Отображаем интерфейс вкладки
            new_tab_widget->show();
        }

    }

    /* Закрытие файлов/вкладок в программе */
    void close_file(int index_tab){

        int flag_index;
        // Блок в котором масив символов переводим в строку
        {
            // Опозавательный знак вкладки
            const char* flag = tabWidget->tabWhatsThis(index_tab).toStdString().c_str();
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

        // Получаем вкладу (из словаря)
        Tab* tab = dict_tab[flag_index];


        // Если это параметры
        if (tab->type() == "option"){
            // Анигилируем вкладку (позже бутем просить сохрания)
            // Удаляем вкладку с интерфейса окна
            tabWidget->removeTab(index_tab);
            // Удаляем вкладку из словаря
            dict_tab.erase(flag_index);
            // Удаляем вкладку
            delete tab;
        }
    }


    void closeEvent(QCloseEvent *event){
        // Реакция на закрытия окна (тут будем юзера упрашивать сохранить файлы)
        cout << "Close window\n";

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



    // Показываем основное окно программы
    prog.show();

    return applicate.exec();
    
}

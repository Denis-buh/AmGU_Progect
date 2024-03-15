



#include <iostream>
#include <map>
#include <string>
#include "nlohmann\json.hpp"

#include <QApplication>
#include <QFileDialog>
#include <QDebug> // Дебагер
#include <QMessageBox>
//#include <QDrag>


// Подключаем библиотеку графического дизайна
#include "MainWindow\MainWindow.h"
// Подключаем библиотеку параметров
#include "Options\Options.h"

// Подключаем библиотеку для работы с файлами
#include "Courses\Courses.h"


using namespace std;


// Структура вкладки
struct Tab{
public:
    // Интерфейс вкладки //
        // Если вкладка - параметры
        Options* Option_Widget = {nullptr};
        // Если вкладка - курс
        Cour* cour_widgwt = {nullptr};

    // Опознавательный знак вкладки
    const char* name_tab = {nullptr};

    // Создаем вкладку
    Tab(Options* Option_Widget, const char* name_tab){
        // Виджет
        this->Option_Widget = Option_Widget;
        // Имя вкладки
        this->name_tab = name_tab;
    }

    // Создаем вкладку
    Tab(Cour* cour_widgwt, const char* name_tab){
        // Виджет
        this->cour_widgwt = cour_widgwt;
        // Имя вкладки
        this->name_tab = name_tab;

    }

    // Убиваем вкладку
    ~Tab(){
        delete this->Option_Widget;
        delete this->cour_widgwt;
        delete this->name_tab;
    }

    // Показываем вкладку
    void show(){
        if (this->Option_Widget != nullptr)  {this->Option_Widget->show();}
        else if (this->cour_widgwt != nullptr)  {this->cour_widgwt->show();}
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
        // Опозавательный знак вкладки (для словаря + индекс вкладки)
        int index_name = this->get_key_for_dict();
        // Опозавательный знак переводим в массив символов
        const char* name2 = to_string(index_name).c_str();
        // Если это особые вкладки
        if (roat_file == "option"){ // Если пользователь решился открыть параметры
            // Добавляем вкладку в словарь вкладок
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
        else{
            // Если это не особые вкладки
            int len_string = roat_file.size();
            // Возращает расширение файла
            //cout << roat_file.substr(len_string - 4) << "\n";
            if (roat_file.substr(len_string - 4) == "cour"){
                //try{
                //Cour crop = {roat_file};
                dict_tab[index_name] = new Tab(new Cour(roat_file), name2);
                Tab* new_tab_widget =  dict_tab[index_name];

                tabWidget->addTab(new_tab_widget->cour_widgwt, QString(name2));
                // Позиция созданой вкладки (необходима для крепления обвесов)
                int index_tab = tabWidget->indexOf(new_tab_widget->cour_widgwt);

                // Добавляем опозавательный знак вкладки
                tabWidget->setTabWhatsThis(index_tab, QString(name2));

                // Коментарий к вкладки
                tabWidget->setTabToolTip(index_tab, QString(name2/*"Вкладка опций приложения. Необходима для изменения параметров приложения"*/) );

                // Отображаем интерфейс вкладки
                new_tab_widget->show();

                //}
                /*catch(...){
                    qDebug() << "Невозможно открыть файл или распарсить json";
                }*/

                //qDebug() << "cour";
            }
        }


    }

    /* Закрытие файлов/вкладок в программе */
    void close_file(int index_tab){

        int flag_index = stoi(tabWidget->tabWhatsThis(index_tab).toStdString());

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
// Основное окно -> параметры
void MainWindow::options_all_clicked(){
    link_program->open_file("option");
}
// Основное окно -> вкладки
void MainWindow::close_tab_clicked(int index){ // Закрытие вкладок
    link_program->close_file(index);
}

// Основное окно -> курсы
void MainWindow::course_open(){ // Открытие курсов
    qDebug() << "call course_open";
    QStringList fname = QFileDialog::getOpenFileNames(link_program, "Имя окна", "Имя файла которое хотим выбрать", "Файл курса(*.cour)");
    int len_fname = int(fname.size());

    if(len_fname != 0){
        // Если список не пустой
        string name_file = fname[0].toStdString();
        //int len_string = name_file.size();
        // Возращает расширение файла
        link_program->open_file(name_file);
    }
    else{
          QMessageBox msg; // Всплывающее окно
          msg.setIcon(QMessageBox::Warning);
          msg.setWindowTitle("Вы не выбрали файл");
          msg.setText("Для открытия курса необходимо выбрать файл с расширением \'.cour\'");
          msg.setStandardButtons(QMessageBox::Cancel);
          msg.exec();
          //auto res = msg.result();
    }
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





/**
 * Данный модуль содержит класс и константы для работы с курсами
 *
 *
 * Константы:
 * ---------
 *
 *
 * Классы:
 * ------
 *     * Cours - Данный класс необходим для работы с курсами
 *
 *
*/

#pragma once
#include <iostream>
#include <fstream> // Для открытия файлов
#include <nlohmann\json.hpp> // Для парсинга json файлов
#include <cstdio>
#include <windows.h>


#include <QtWidgets/QWidget>
#include <QDebug> // Дебагер


#include "./ui_Courses.h"


using json = nlohmann::json;
using namespace std;


// Абстрактный класс курсов
class Abstract_Cour{
protected:
    string dir_cour; // Директория курса
    void set_dir_cour(string); // Определяет папку курса
    json cour_json; // json словарь (главный файл)
    void set_cour_json(string); // Считывает json файл
    // Под вопросом: list<string> topic_list; // Темы курса
    list<string> get_topic_list();

public:
    Abstract_Cour(string roat_file){
        this->set_dir_cour(roat_file);
        this->set_cour_json(roat_file);
    }
    Abstract_Cour(){}
};




class Cour: public QWidget, public Ui_GUI_cour, public Abstract_Cour{
    Q_OBJECT
protected:
    // Устанавливаем информацию  для виджета обзора тем курса
    void set_inform_on_course_tree(){
        QTreeWidgetItem* qtreeitem = this->course_tree->headerItem();
        qtreeitem->setText(0, QString(string(cour_json["name_course"]).c_str()));

        // Получаем список тем
        list<string> topic_list = this->get_topic_list();
        for (auto iter = topic_list.begin(); iter != topic_list.end(); iter++){
            QTreeWidgetItem *cities = new QTreeWidgetItem(this->course_tree);
            cities->setText(0, QString((*iter).c_str()));
            this->course_tree->setCurrentItem(cities);
        }
    }


public:
    Cour(string roat_file): Abstract_Cour(roat_file){
        // Загружаем интерфейс
        this->setupUi(this);
        // Биндим интерфейс
        this->bind_command();
        // Устанавливаем информацию для виджета обзора тем курса
        this->set_inform_on_course_tree();
    }


    void bind_command(){
        connect(this->course_tree, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(get_activ_item(QTreeWidgetItem*, int)));
    }


public slots:
    // Возвращает название активной темы
    void get_activ_item(QTreeWidgetItem*item, int column){
        name_current_topic->setText(item->text(column));
        qDebug() << item->text(column);
        cout << item->text(column).toStdString() << "\n";
        // Считываем файл
        qDebug() << (dir_cour + "/" + string(cour_json["inform_to_couse"][item->text(column).toStdString()])).c_str();


        ifstream file;
        file.exceptions(ifstream::badbit | ifstream::failbit);
        file.open((dir_cour + "/" + string(cour_json["inform_to_couse"][item->text(column).toStdString()])).c_str());

        string file_inform = "";
        while (not file.eof()){
            string temp = "";
            getline(file, temp);
            file_inform += temp;
        }
        cout << file_inform << "\n";
        file.close();

        subject_field->setHtml(file_inform.c_str());
    }


};



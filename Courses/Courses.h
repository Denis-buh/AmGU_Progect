



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
#include <nlohmann\json.hpp>
#include <fstream>
#include <cstdio>
#include <windows.h>

#include <QtWidgets/QWidget>
#include <QDebug> // Дебагер

#include "./ui_Courses.h"


using json = nlohmann::json;
using namespace std;


class Cour;


class GUI_Cours: public QWidget, public Ui_GUI_cour{
    Q_OBJECT
public:
    string dir_cour; // Директория курса
    json cour_json; // json словарь (главный файл)
    list<string> topic_list; // Темы курса
    /**
    Необходим для иницииализации класса
    Загружает интерфейс из ui файла
    */
    GUI_Cours(){
        // Загружаем интерфейс
        this->setupUi(this);
        // Биндим интерфейс
        this->bind_command();
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



class Cour: public GUI_Cours{
private:
    //string dir_cour; // Директория курса
    // Определяет директорию курса
    void set_dir_cour(string roat_file){
        int cout_split;
        for (int i = 0; i < roat_file.size(); i += 1){
            if (roat_file[i] == '/')  {cout_split = i;}
        }
        // Обрубаем строку
        this->dir_cour = roat_file.substr(0, cout_split);
    }

    // json словарь (главный файл)
    //json cour_json;
    // Считваем json файл
    void set_cour_json(string roat_file){
        // Открываем и парсим json
        ifstream file;
        file.exceptions(ifstream::badbit | ifstream::failbit);

        file.open(roat_file.c_str());
        // Считываем файл
        string file_inform = "";
        while (not file.eof()){
            string temp = "";
            file >> temp;
            file_inform += temp;
        }
        file.close();
        // Парсим json
        cour_json = json::parse(file_inform);
    }

    // Темы курса
    //list<string> topic_list;
    // Читываем темы курса
    void set_topic_list(){
        json inform_to_couse = cour_json["inform_to_couse"];
        for (auto& el : inform_to_couse.items()){
            topic_list.push_back(el.key());
        }
    }

    // Устанавливаем информацию на для виджета обзора тем курса
    void set_inform_on_course_tree(){
        QTreeWidgetItem* qtreeitem = this->course_tree->headerItem();
        qtreeitem->setText(0, QString(string(cour_json["name_course"]).c_str()));

        for (auto iter = topic_list.begin(); iter != topic_list.end(); iter++){
            QTreeWidgetItem *cities = new QTreeWidgetItem(this->course_tree);
            cities->setText(0, QString((*iter).c_str()));
            this->course_tree->setCurrentItem(cities);
        }
    }



public:
    Cour(string roat_file){
        this->set_dir_cour(roat_file);
        this->set_cour_json(roat_file);
        this->set_topic_list();
        this->set_inform_on_course_tree();
        cout << string(cour_json["name_course"]).c_str() << "\n";
        GUI_Cours();

    }


};





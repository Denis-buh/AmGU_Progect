



/**
 * Данный модуль содержит класс и константы для работы с интерфейсом главного окна программы
 * Использовать для очень тонкой настройки окна
 * + когда нужно настраивать только главное окно
 *
 *
 * Константы:
 * ---------
 *
 *
 * Классы:
 * ------
 *     * MainWindow - Данный класс является интерфейсом главного окна программы
 *
 *
*/

#pragma once
#include <QMainWindow>
#include <iostream>

#include "./ui_Main_Window.h"

using namespace std;





class MainWindow: public QMainWindow, public Ui_MainWindow{
    Q_OBJECT
protected:


public:
    /**
    Необходим для иницииализации класса
    Загружает интерфейс из ui файла
    */
    MainWindow(){
        // Загружаем интерфейс
        this->setupUi(this);
    }

    void bind_command(){
        connect(this->options_all, SIGNAL(triggered()), this, SLOT(options_all_clicked()));
        connect(this->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(close_tab_clicked(int)));
    }

//signals:

public slots:
    void options_all_clicked();
    void close_tab_clicked(int index);

};


/*
 // Курсы
 file
    // Открыть недавний курс
    file_opened_recently
        // Очистить недавно открытые
        file_clear_opened_recently
 // Добавить курс
 file_append_course
    // Локальный
    file_append_course_local
    // Из официального сообщества
    file_append_course_global
 // Создать курс
 file_made_course

 // Опции
 options
    // Параметры начальной вкладки
    option_start_tab
    // Локализация
    option_locale
    // Персонализация
    option_personalisation
    // Горячие клавиши
    option_hotkeys
    // О приложении
    option_inform_program
    // Все
    options_all

 // Прочее
 other
    // Отобразить начальную вкладку
    other_show_strart_tab
    // Отправить сообщение об ошибке
    other_inform_error

*/

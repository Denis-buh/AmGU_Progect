



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
        // ДЛЯ ПАРАМЕТРОВ //
        connect(this->options_all, SIGNAL(triggered()), this, SLOT(options_all_clicked()));
        // ДЛЯ ВКЛАДОК //
        connect(this->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(close_tab_clicked(int)));
        // ДЛЯ КУРСОВ //
        connect(this->file_open_course, SIGNAL(triggered()), this, SLOT(course_open()));
    }

//signals:

public slots:
    // ДЛЯ ПАРАМЕТРОВ //
    void options_all_clicked(); // Открытие параметров
    // ДЛЯ ВКЛАДОК //
    void close_tab_clicked(int index); // Закрытие вкладок
    // ДЛЯ КУРСОВ //
    void course_open(); // Открытие курса

};


/*
 // Курсы
 file
    // Открыть курс
    file_open_course

    // Открыть недавний курс
    file_opened_recently
        // Очистить недавно открытые
        file_clear_opened_recently
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

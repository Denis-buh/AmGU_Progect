



/**
 * Данная бибилиотека содержит классы и константы для работы с графикой приложения
 *
 *
 * Константы:
 * ---------
 *
 *
 * Классы:
 * ------
 *     * GUI -  Данный класс необходим для управления интерфейсом программы
 *
 *
*/



#pragma once


// Добавляем интерфейс главного окна программы
#include ".\MainWindow\MainWindow.cpp"



/**
 * @brief
 * Данная структура необходима для работы с интерфейсом вкладки
*/
struct Tab{

};




/**
 * @brief
 * Данный класс необходим для работы с главным окном приложения
*/
class GUI: public MainWindow{
private:

protected:
   /* void set_locale(){
        // Установка локализации для интерфейса приложения
        Tab_Window.set_locale();
    }*/

    /*void set_optios(){
        // Установка опций для интерфейса приложения
        Tab_Window.set_optios();
    }*/

    template< typename binds_command>
    void bind_command(binds_command commad_for_bind){
        // Добавляет бинды функций на  интерфейс приложения
        MainWindow::bind_command(commad_for_bind.MainWindow);
    }

    void open_tab(){
        // Данный метод создает вкладку (возможно в новую вкладку указатель на обьекты интерфейса)
    }

    void close_tab(){
        // Данный метод удаляет вкладку (возможно в новую вкладку указатель на обьекты интерфейса)
    }

public:

};





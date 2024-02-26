



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
 *     * Tab_Window - Данный класс является интерфейсом главного окна программы
 *
 *
*/




#pragma once


#include ".\Main_Window.h"


class Tab_Window: public MainWindow{
protected:
    /*void set_locale(){
        // Добавляет локализацию на элементы интерфейса главного окна программы
    }*/

    /*void set_optios(){
        // Установка опций для интерфейса главного окна приложения
    }*/

    template< typename Command_for_MainWindow>
    void bind_command(Command_for_MainWindow commad_for_bind_MainWindow){
        // Добавляет бинды функций на элементы интерфейса главного окна программы
        //commad_for_bind_MainWindow.options_all();
        //connect(options_all, SIGNAL(triggered()),this,SLOT(dosmt()));
        //options_all->addAction("Open", this, SLOT(open_file()) );
        //MainWindow::options_all;
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

    }

};

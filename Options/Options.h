



/**
 * Данный модуль содержит класс и константы для работы с параметрами программы
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
 *     * Options - Данный класс необходим для работы с параметрами программы
 *
 *
*/

#pragma once
#include <QtWidgets/QWidget>
#include <iostream>
#include "./ui_Options.h"

using namespace std;





class Options: public QWidget, public Ui_Form{
    Q_OBJECT
public:
    /**
    Необходим для иницииализации класса
    Загружает интерфейс из ui файла
    */
    Options(){
        // Загружаем интерфейс
        this->setupUi(this);
        // Биндим интерфейс
        this->bind_command();
    }

    void bind_command(){
        connect(this->pushButton, SIGNAL(clicked()), this, SLOT(coomande()));
    }

public slots:
    // Какая то реакция на кнопку
    void coomande(){
        cout << "clicked button in options\n";
    }


};




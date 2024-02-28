



//#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QWidget>

// Создаем свое собственное окно
// Наследуемся от QMainWindow (окно стандартное) и Ui_MainWindow (интерфейс для окна)
// Ui_MainWindow (имя клааса интерфейс для окна) смотреть в QtDesigner
class My_Window: public QMainWindow, public Ui_MainWindow{
public:
    My_Window(){
        // Загружаем интерфейс
        this->setupUi(this);
    }
};




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    My_Window wind;
    // Показываем окно
    wind.show();
    // Обращаемся к элементам интерфейса
    wind.pushButton;

    /*QMainWindow *w = new QMainWindow;
    Ui_MainWindow ui;
    ui.setupUi(w);
    w->show();
    ui.pushButton;*/

    return a.exec();
}


/*
#include "ui_mainwindow.h"
#include <QApplication>
#include<QMainWindow>
#include<QWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *widget = new QWidget;
    Ui::CalculatorForm ui;
    ui.setupUi(widget);

    widget->show();
    return a.exec();
}



*/

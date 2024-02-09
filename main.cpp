



#include <iostream>

using namespace std;


int main(int argc, char* argv[]){
    system("chcp 65001");
    // argc - количество аргументов
    /*argv - массив аргументов
        Первым аргументом массива всегда будет путь к исполняему файлу exe
        Последующие аргументы - то что передано командной строке (файлы по асоциациям/открытиям с помощью )
    */
    cout << "Hello word\n";
    
    system("pause");
}
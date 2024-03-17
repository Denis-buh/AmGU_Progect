



#pragma once



#include "Courses.h"


using json = nlohmann::json;


void Abstract_Cour::set_dir_cour(string roat_file){
    int cout_split; // Номер где последний раз встечается символ разоединитель
    for (int i = 0; i < roat_file.size(); i += 1){
        if (roat_file[i] == '/')  {cout_split = i;}
    }
    // Обрубаем строку и устанавливаем полученый результат
    this->dir_cour = roat_file.substr(0, cout_split);
}


void Abstract_Cour::set_cour_json(string roat_file){
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


list<string> Abstract_Cour::get_topic_list(){
    list<string> topic_list;
    json inform_to_couse = cour_json["inform_to_couse"];
    for (auto& el : inform_to_couse.items()){
        topic_list.push_back(el.key());
    }
    return topic_list;
}




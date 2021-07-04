#pragma once
#include "menu.hpp"


void addToDataBase(DataBase& base){
    

}


void display(DataBase& base){


}


void help(){
    std::cout << "a - add student        r - remove student\n";
    std::cout << "d - display base       n - sort by lastame \n";
    std::cout << "p - sort by PESEL      c - search student(PESLE)L\n";
    std::cout << "s - save data base     o - search students(last name)\n";
    std::cout << "l - load data base     h - help";
}


Sex stringToSex(const std::string& sex)
{
        if(sex == "Male")
            return Sex::Male;
        return Sex::Female; 
}


void addStudentToBase(DataBase& base){
    std::string name, lastName, addres, pesel, gender;
    int index;
    std::cout <<"First name: ";   getline(std::cin, name);
    std::cout <<"Last name: ";    getline(std::cin, lastName);
    std::cout <<"Addres: ";       getline(std::cin, addres);
    std::cout <<"Index nr: ";     std::cin >> index; std::cin.get();
    std::cout <<"PESEL: ";        getline(std::cin, pesel);
    std::cout <<"Gender(Male/Female): ";   getline(std::cin, gender);

    if(base.isInDataBase(index)) {
        std::cout <<"index already exists\n";
    }

    if(base.addStudent(name,lastName,addres,index,pesel, stringToSex(gender))){
        std::cout <<"Added to data data base\n";
    }
    else{
        std::cout <<"Incorrect PESEL\n";
    }
}


void removeStudentFromBase(DataBase& base){
    std::cout <<"Index to remove: ";
    int indexToRemove;
    std::cin >> indexToRemove;
    if(base.isInDataBase(indexToRemove)){
        base.remove(indexToRemove);
        std::cout <<"removed\n";
        return;
    }
    std::cout <<"Index not found\n";
}


void loadFromDataBase(DataBase& base){
    if(base.loadDataBase("st.txt")){
        std::cout <<"Success\n";
    }
    else{
        std::cout <<"Loading failed\n";
    }
}


char getChar(){
    char choice;
    std::cin >> choice;
    while (std::cin.get() !='\n'){
        continue;
    }
    return choice;
}
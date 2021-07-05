#pragma once
#include "menu.hpp"


void help(){
    std::cout << "a - add student        r - remove student\n";
    std::cout << "d - display base       n - sort by lastame \n";
    std::cout << "p - sort by PESEL      c - search student(PESLE)L\n";
    std::cout << "s - save data base     o - search students(last name)\n";
    std::cout << "l - load data base     h - help\n";
    std::cout << "q - quit ";
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

    if(base.addStudent(name, lastName, addres, index, pesel, stringToSex(gender))){
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
    if(base.loadDataBase("students.txt")){
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


void BaseManager(DataBase& base){
    std::cout <<"Students data base\n";
    help();
    std::cout <<"\n";

    bool continueProgram {true};
    char choice {};
    std::string temp;

    do
    {
        std::cout<<"Select options: ";
        choice = getChar();
        switch (choice)
        {
        case 'a':
            addStudentToBase(base);
            break;
        case 'r':
            removeStudentFromBase(base);
            break;
        case 'd':
            base.display();
            break;
        case 's':
            base.saveDataBase("students.txt");
            break;
        case 'l':
            loadFromDataBase(base);
            break;
        case 'n':
            base.sortByLastName();
            break;
        case 'p':
            base.sortByPesel();
            break;
        case 'c':
            std::cout <<"Pesel: ";
            std::cin >> temp;
            base.searchPesel(temp);
            break;
        case 'o':
            std::cout <<"Last name: ";
            getline(std::cin, temp);
            base.searchLastName(temp);
            break;
        case 'h':
            help();
            break;
        case 'q':
            continueProgram = false;
            break;
        default:
            break;
        }

    }while (continueProgram);
}
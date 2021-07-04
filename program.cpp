#pragma once
#include "menu.hpp"

int main(){

    DataBase data;
    data.addStudent("Anna", "Nowak","Kraków",51233, "93021095265",Sex::Female);
    data.addStudent("Alicja", "Rak","Wrocław",51200, "93101253549",Sex::Female);
    data.addStudent("Paulina", "Lina","Tarnów",51280, "97111158324",Sex::Female);
    data.addStudent("Patrycja", "Partycja","Nowy Sącz",51201, "93010277746",Sex::Female);
    data.addStudent("Magdalena", "Kapusta","Kraków",51202, "98082738269",Sex::Female);
    data.addStudent("Anna", "Kapusta","Kraków",51203, "95081058822",Sex::Female);



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
            addStudentToBase(data);
            break;
        case 'r':
            removeStudentFromBase(data);
            break;
        case 'd':
            data.display();
            break;
        case 's':
            data.saveDataBase("st.txt");
            break;
        case 'l':
            loadFromDataBase(data);
            break;
        case 'n':
            data.sortByLastName();
            break;
        case 'p':
            data.sortByPesel();
            break;
        case 'c':
            std::cout <<"Pesel: ";
            std::cin >> temp;
            data.searchPesel(temp);
            break;
        case 'o':
            std::cout <<"Last name: ";
            getline(std::cin, temp);
            data.searchLastName(temp);
            break;
        case 'h':
            help();
            break;
    
        default:
        continueProgram = false;
            break;
        }

    }while (continueProgram);

}
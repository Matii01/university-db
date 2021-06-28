#include <algorithm>
#include <fstream>

#include "DataBase.hpp"


int DataBase::charToInt(char z)
{
    return (z-48);
}


bool DataBase::validPesel(std::string pesel)
{
    if(pesel.length() != 11) {
        return false;
    }
    const int digitWeight[11] {1,3,7,9,1,3,7,9,1,3,1};
    int sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += digitWeight[i] * charToInt(pesel[i]);
    }
    int M = sum % 10;
    return (M == 0 && charToInt(pesel[10]) == 0)
            || (10 - M == charToInt(pesel[10]));
}


bool DataBase::addStudent(std::string firstName, std::string lastName, std::string address,
             int indexNumber, std::string pesel, Sex sex)
{             
    if(!validPesel(pesel)){
        std::cout <<"Error incorrecd PESEL";
        return false;
    }
    Students.push_back({firstName, lastName, address, indexNumber, pesel, sex});
    return true;
}


void DataBase::sortByLastName() {
    std::sort(Students.begin(), Students.end(),
    [](const Student& lhs, const Student& rhs) {
        return lhs.getlastName() < rhs.getlastName();
    });
}


void DataBase::sortByPesel() {
    std::sort(Students.begin(), Students.end(),
    [](const Student& lhs, const Student& rhs){
        return lhs.getPesel() > rhs.getPesel();
    });
}


void DataBase::display() {
    for(const auto &item : Students){
        item.display();
        std::cout << std::endl;
    }
}


void DataBase::saveDataBase(std::string path){
    std::fstream file;
    file.open(path, std::ios::out);
    if(file.is_open()){
        for(const auto& it : Students) {
            file << it.getFirstName() <<"\n";
            file << it.getlastName() <<"\n";
            file << it.getAddress() <<"\n";
            file << it.getIndexNumber() <<"\n";
            file << it.getPesel() <<"\n";
            file << it.sexToString(it.getSex()) <<"\n";
        }
    }
    file.close();
}


void DataBase::loadDataBase(std::string path){
    std::fstream file;
    file.open(path, std::ios::in);
    if(file.is_open()){
        std::string name, lastName, addres, pesel, sex, temp;
        int index;
        int a = 30;
        while (!file.eof())
        {
            std::getline(file, name);   
            std::getline(file, lastName);
            std::getline(file, addres); 
            file >> index; file.get(); // file.get() removes '\n'
            std::getline(file, pesel); 
            std::getline(file, sex); 
            if(name.size() > 1 ){
                Students.push_back({ name, lastName, addres, index, pesel, Sex::Female});
            }
        }
    }
    file.close();
}

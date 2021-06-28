#include <algorithm>
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
    using std::cout;
    for(const auto &item : Students){
        cout.width(10); cout <<std::left <<item.getFirstName();
        cout.width(10); cout <<std::left <<item.getlastName();
        cout.width(10); cout <<std::left <<item.getAddress();
        cout.width(10); cout <<std::left <<item.getIndexNumber();
        cout.width(10); cout <<std::left <<item.getPesel();
        cout << std::endl;
    }
}

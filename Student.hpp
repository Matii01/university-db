#pragma once
#include <iostream>

enum class Sex
{
    Male,
    Female
};

class Student
{
private:
    std::string firstName_;
    std::string lastName_;
    std::string address_;
    int indexNumber_;
    std::string pesel_;
    Sex sex_;

public:
    Student(std::string firstName, std::string lastName, std::string address,
            int indexNumber, std::string pesel, Sex sex)
            :firstName_(firstName)
            ,lastName_(lastName)
            ,address_(address)
            ,indexNumber_(indexNumber)
            ,pesel_(pesel)
            ,sex_(sex) 
            {}

    std::string getFirstName() const {return firstName_;}
    std::string getlastName() const {return lastName_;}
    std::string getAddress() const {return address_;}
    int getIndexNumber() const {return indexNumber_;}
    std::string getPesel() const {return pesel_;}
    Sex getSex() const {return sex_;}
    
};

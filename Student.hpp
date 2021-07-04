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
    std::string sexToString(const Sex& sex)const {return sex == Sex::Male ? "Male" : "Female";}
    
    bool operator ==(const Student& b) const
    {
        if(b.getFirstName() != firstName_)
            return false;
        if(b.getlastName() != lastName_)
            return false;
        if(b.getAddress() != address_)
            return false;
        if(b.getIndexNumber() != indexNumber_)
            return false;
        if(b.getPesel() != pesel_)
            return false;
        if(b.getSex() != sex_)
            return false;

        return true;
    }

    void display()const {
        using std::cout;
        cout.width(10); cout <<std::left << firstName_;
        cout.width(10); cout <<std::left << lastName_;
        cout.width(15); cout <<std::left << address_;
        cout.width(10); cout <<std::left << indexNumber_;
        cout.width(15); cout <<std::left << pesel_;
        cout.width(10); cout <<std::left << sexToString(sex_);
    }
};

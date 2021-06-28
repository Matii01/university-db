#include <vector>
#include "Student.hpp"

class DataBase
{
private:
    std::vector<Student>Students;
    bool validPesel(std::string pesel);
    int charToInt(char z);

public:

    bool addStudent(std::string firstName, std::string lastName, std::string address,
             int indexNumber, std::string pesel, Sex sex);

    void display();
    std::vector<const Student *> searchLastName();
    Student* searchPesel(std::string pesel);
    void sortByPesel();
    void sortByLastName();
    void remove(std::string indexNumber);
    void saveDataBase(std::string path);
    void loadDataBase(std::string path);
    int size() {return Students.size();}
    Student& operator[](int i) {return Students[i];}
};

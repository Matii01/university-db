#include "gtest/gtest.h"
#include "DataBase.hpp"

#include <algorithm>


bool isSortedByPesel(DataBase base){
    for(int i = 0;i < base.size()-1; i++){
        if(base[i].getPesel() < base[i+1].getPesel()){
            return false;
        }
    }
    return true;
}

bool isSortedByLastName(DataBase base){
    for(int i = 0;i < base.size()-1; i++){
        if(base[i].getlastName() > base[i+1].getlastName()){
            return false;
        }
    }
    return true;
}



TEST(SortTest, ShouldSortStudents){
    DataBase data;
    data.addStudent("Anna", "Nowak","Kraków",51233, "93021095265",Sex::Female);
    data.addStudent("Alicja", "Rak","Wrocław",51200, "93101253549",Sex::Female);
    data.addStudent("Paulina", "Kwiatkowska","Tarnów",51280, "97111158324",Sex::Female);
    data.addStudent("Patrycja", "Kozłowska","Nowy Sącz",51201, "93010277746",Sex::Female);
    data.addStudent("Magdalena", "Dąbrowska","Kraków",51202, "98082738269",Sex::Female);
    data.addStudent("Anna", "Dąbrowska","Kraków",51203, "95081058822",Sex::Female);
    data.addStudent("Krzysztof","Wiśniewski","Kraków",54100,"03270886598",Sex::Male);
    data.addStudent("Dariusz","Zieliński","Kraków",54101,"97092468438",Sex::Male);
    data.addStudent("Adam","Zieliński","Kraków",54102,"99080191533",Sex::Male);
    data.addStudent("Beata","Kowalczyk","Kraków",54103,"99042175825",Sex::Female);
    data.addStudent("Krystyna","Kamińska","Kraków",54104,"96081135421",Sex::Female);
    data.addStudent("Robert","Nowak","Kraków",54105,"98112038495",Sex::Male);
    data.addStudent("Wiktoria","Szymańska","Kraków",54106,"97111622942",Sex::Female);
    data.addStudent("Filip","Brzoza","Kraków",54107,"95012578696",Sex::Male);
    data.addStudent("Karolina","Woźniak","Kraków",54108,"95033072566",Sex::Female);


    data.sortByPesel();
    ASSERT_EQ(isSortedByPesel(data), true);
    data.sortByLastName();
    ASSERT_EQ(isSortedByLastName(data), true);

}



TEST(AddTest, ShouldAddNewStudent){
    DataBase data;
    data.addStudent("Anna", "Nowak","Kraków",51233, "93021095265",Sex::Female);
    ASSERT_EQ(data.size(), 1);
    ASSERT_EQ(data.addStudent("Anna", "Nowak","Kraków",51233, "930",Sex::Female), false);
    ASSERT_EQ(data.size(), 1);
    ASSERT_EQ(data.addStudent("Alicja", "Rak","Wrocław",51200, "93101253549",Sex::Female),true);
    ASSERT_EQ(data.size(), 2);
    ASSERT_EQ(data[0].getFirstName(), "Anna");
}



TEST(SaveAndLoad, ShouldLoadingAndSaveingDataBase){
    DataBase data;
    ASSERT_EQ(data.loadDataBase("asd.txt"), false);
    data.addStudent("Anna", "Nowak","Kraków",51233, "93021095265",Sex::Female);
    data.addStudent("Alicja", "Rak","Wrocław",51200, "93101253549",Sex::Female);
    data.saveDataBase("students.txt");
    ASSERT_EQ(data.loadDataBase("students.txt"), true);
    data.saveDataBase("students.txt");
    int expected = data.size();
    ASSERT_EQ(data.loadDataBase("students.txt"), true);
    ASSERT_EQ(data.size(), expected);
}


TEST(removeTest, ShouldRemoveStudent){
    DataBase data;
    data.addStudent("Anna", "Nowak","Kraków",51233, "93021095265",Sex::Female);
    data.addStudent("Alicja", "Rak","Wrocław",51200, "93101253549",Sex::Female);
    int expected = data.size();
    ASSERT_EQ(data.isInDataBase(51233),true);
    data.remove(51233);
    ASSERT_EQ(data.size(), expected-1);
    ASSERT_EQ(data.isInDataBase(51233),false);
}


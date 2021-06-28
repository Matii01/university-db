#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"
#include "DataBase.hpp"


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

TEST_CASE( "Sorting a DataBase", "[sort]" ) {
    DataBase data;
    data.addStudent("Anna", "Nowak","Kraków",51233, "93021095265",Sex::Female);
    data.addStudent("Alicja", "Rak","Wrocław",51200, "93101253549",Sex::Female);
    data.addStudent("Paulina", "Lina","Tarnów",51280, "97111158324",Sex::Female);
    data.addStudent("Patrycja", "Partycja","Nowy Sącz",51201, "93010277746",Sex::Female);
    data.addStudent("Magdalena", "Kapusta","Kraków",51202, "98082738269",Sex::Female);
    data.addStudent("Anna", "Kapusta","Kraków",51203, "95081058822",Sex::Female);
    SECTION("Sorting by Pesel"){
        data.sortByPesel();
        REQUIRE( isSortedByPesel(data) == true );
        data.addStudent("Adam","Kit","Tarnów", 51999,"93010773297",Sex::Male);
        data.sortByPesel();
        REQUIRE( isSortedByPesel(data) == true );
    }
    SECTION("Sorting by Last Name"){
        data.sortByLastName();
        REQUIRE( isSortedByLastName(data) == true );
        data.addStudent("Adam","Kit","Tarnów", 51999,"93010773297",Sex::Male);
        data.sortByLastName();
        REQUIRE( isSortedByLastName(data) == true );
    }
}

TEST_CASE( "Pesel check", "[pesel]" ) {
    DataBase data;
    data.addStudent("Anna", "Nowak","Kraków",51233, "93021095265",Sex::Female);
    data.addStudent("Alicja", "Rak","Wrocław",51200, "93101253549",Sex::Female);
    data.addStudent("Paulina", "Lina","Tarnów",51280, "97111158324",Sex::Female);
    data.addStudent("Patrycja", "Partycja","Nowy Sącz",51201, "93010277746",Sex::Female);
    data.addStudent("Magdalena", "Kapusta","Kraków",51202, "98082738269",Sex::Female);
    data.addStudent("Anna", "Kapusta","Kraków",51203, "95081058822",Sex::Female);
    int expected = data.size();

    SECTION("Add Student, pesel uncorect"){
        REQUIRE(data.addStudent("Adam","Kit","Tarnów", 51999,"90010773297",Sex::Male) == false);
        REQUIRE( data.size() == expected );
    }
    SECTION("Add Student, pesel corect"){
        REQUIRE(data.addStudent("Adam","Kit","Tarnów", 51999,"93010773297",Sex::Male) == true); 
        REQUIRE( data.size() == expected + 1);
    }
}

#pragma once
#include "DataBase.hpp"

void BaseManager(DataBase& base);
void addStudentToBase(DataBase& base);
void removeStudentFromBase(DataBase& base);
void loadFromDataBase(DataBase& base);
void help();
char getChar();
Sex stringToSex(const std::string& sex);
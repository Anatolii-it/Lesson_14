#ifndef LIB_H
#define LIB_H


#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

const int MAX_EMPLOYEES = 100; // бо я не знаю скільки буде строк

struct Employee {
    string surname;
    string name;
    int age;
};

Employee enterEmployeeData();
void printEmployee(const Employee& emp);
int findEmployeesByAge(const Employee employees[], int size, int age, Employee foundEmployees[]);
int findEmployeesBySurname(const Employee employees[], int size, const string& surname, Employee foundEmployees[]);
int findEmployeesByPartialSurname(const Employee employees[], int size, const string& partialSurname, Employee foundEmployees[]);
void saveEmployeesToFile(const Employee employees[], int size, const string& filename);
void loadEmployeesFromFile(Employee employees[], int& size, const string& filename);
void editEmployee(Employee employees[], int size, const string& surname);
void deleteEmployee(Employee employees[], int& size, const string& surname);
void saveSearchResultsToFile(const Employee employees[], int size, const string& filename);

#endif  LIB_H

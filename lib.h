#ifndef LIB_H
#define LIB_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Employee {
     string surname;
     string name;
    int age;
};

Employee enterEmployeeData();
void printEmployee(const Employee& emp);
 vector<Employee> findEmployeesByAge(const  vector<Employee>& employees, int age);
 vector<Employee> findEmployeesBySurname(const  vector<Employee>& employees, const  string& surname);
 vector<Employee> findEmployeesByPartialSurname(const  vector<Employee>& employees, const  string& partialSurname);
void saveEmployeesToFile(const  vector<Employee>& employees, const  string& filename);
void loadEmployeesFromFile( vector<Employee>& employees, const  string& filename);
void editEmployee( vector<Employee>& employees, const  string& surname);
void deleteEmployee( vector<Employee>& employees, const  string& surname);
void saveSearchResultsToFile(const  vector<Employee>& searchResults, const  string& filename);

#endif  LIB_H


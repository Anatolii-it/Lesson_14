#include "lib.h"


Employee enterEmployeeData() {
    Employee emp;
     cout << "Введіть призвіще: ";
     cin >> emp.surname;
     cout << "Введіть ім'я: ";
     cin >> emp.name;
     cout << "Повних років: ";
     cin >> emp.age;
    return emp;
}

void printEmployee(const Employee& emp) {
     cout << "#---------------------------------#" <<  endl;
     cout << "     Призвище: " << emp.surname <<  endl;
     cout << "         Ім'я: " << emp.name <<  endl;
     cout << "        Років: " << emp.age <<  endl;
}

 vector<Employee> findEmployeesByAge(const  vector<Employee>& employees, int age) {
     vector<Employee> foundEmployees;
    for (const auto& emp : employees) {
        if (emp.age == age) {
            foundEmployees.push_back(emp);
        }
    }
    return foundEmployees;
}

 vector<Employee> findEmployeesBySurname(const  vector<Employee>& employees, const  string& surname) {
     vector<Employee> foundEmployees;
    for (const auto& emp : employees) {
        if (emp.surname == surname) {
            foundEmployees.push_back(emp);
        }
    }
    return foundEmployees;
}

 vector<Employee> findEmployeesByPartialSurname(const  vector<Employee>& employees, const  string& partialSurname) {
     vector<Employee> foundEmployees;
    for (const auto& emp : employees) {
        if (emp.surname.find(partialSurname) !=  string::npos) {
            foundEmployees.push_back(emp);
        }
    }
    return foundEmployees;
}

void saveEmployeesToFile(const  vector<Employee>& employees, const  string& filename) {
     ofstream outputFile(filename);
    if (!outputFile) {
         cerr << "неможливо почитати." <<  endl;
        return;
    }

    for (const auto& emp : employees) {
        outputFile << emp.surname << " " << emp.name << " " << emp.age <<  endl;
    }

    outputFile.close();
     cout << "#---------------------------------#" <<  endl;
     cout << " збережено у файл employees.txt " <<  endl;
}

void loadEmployeesFromFile( vector<Employee>& employees, const  string& filename) {
     ifstream inputFile(filename);
    if (!inputFile) {
         cout << "#---------------------------------#" <<  endl;
         cerr << "Error opening file for reading." <<  endl;
        return;
    }

    employees.clear();

    Employee emp;
    while (inputFile >> emp.surname >> emp.name >> emp.age) {
        employees.push_back(emp);
    }

    inputFile.close();
     cout << "#---------------------------------#" <<  endl;
     cout << " успішно зчитано з employees.txt" <<  endl;
}

void editEmployee( vector<Employee>& employees, const  string& surname) {
    for (auto& emp : employees) {
        if (emp.surname == surname) {
             cout << "Введіть нові дані для працівника '" << surname << "':" <<  endl;
            emp = enterEmployeeData();
             cout << "Дані про працівника оновлено." <<  endl;
            return;
        }
    }
     cout << "Працівника з прізвищем '" << surname << "' не знайдено." <<  endl;
}

void deleteEmployee( vector<Employee>& employees, const  string& surname) {
    auto it =  remove_if(employees.begin(), employees.end(), [&](const Employee& emp) {
        return emp.surname == surname;
        });
    if (it != employees.end()) {
        employees.erase(it, employees.end());
         cout << "Працівника з прізвищем '" << surname << "' видалено." <<  endl;
    }
    else {
         cout << "Працівника з прізвищем '" << surname << "' не знайдено." <<  endl;
    }
}

void saveSearchResultsToFile(const  vector<Employee>& searchResults, const  string& filename) {
     ofstream outputFile(filename);
    if (!outputFile) {
         cerr << "неможливо почитати." <<  endl;
        return;
    }

    for (const auto& emp : searchResults) {
        outputFile << emp.surname << " " << emp.name << " " << emp.age <<  endl;
    }

    outputFile.close();
     cout << "Результати пошуку збережено у файл " << filename <<  endl;
}

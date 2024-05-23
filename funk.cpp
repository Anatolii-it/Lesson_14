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
    cout << "#---------------------------------#" << endl;
    cout << "     Призвище: " << emp.surname << endl;
    cout << "         Ім'я: " << emp.name << endl;
    cout << "        Років: " << emp.age << endl;
}

int findEmployeesByAge(const Employee employees[], int size, int age, Employee foundEmployees[]) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (employees[i].age == age) {
            foundEmployees[count++] = employees[i];
        }
    }
    return count;
}

int findEmployeesBySurname(const Employee employees[], int size, const string& surname, Employee foundEmployees[]) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (employees[i].surname == surname) {
            foundEmployees[count++] = employees[i];
        }
    }
    return count;
}

int findEmployeesByPartialSurname(const Employee employees[], int size, const string& partialSurname, Employee foundEmployees[]) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (employees[i].surname.find(partialSurname) != string::npos) {
            foundEmployees[count++] = employees[i];
        }
    }
    return count;
}

void saveEmployeesToFile(const Employee employees[], int size, const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "неможливо почитати." << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        outputFile << employees[i].surname << " " << employees[i].name << " " << employees[i].age << endl;
    }

    outputFile.close();
    cout << "#---------------------------------#" << endl;
    cout << " збережено у файл employees.txt " << endl;
}

void loadEmployeesFromFile(Employee employees[], int& size, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "#---------------------------------#" << endl;
        cerr << "Error opening file for reading." << endl;
        return;
    }

    size = 0;

    while (inputFile >> employees[size].surname >> employees[size].name >> employees[size].age) {
        size++;
    }

    inputFile.close();
    cout << "#---------------------------------#" << endl;
    cout << " успішно зчитано з employees.txt" << endl;
}

void editEmployee(Employee employees[], int size, const string& surname) {
    for (int i = 0; i < size; ++i) {
        if (employees[i].surname == surname) {
            cout << "Введіть нові дані для працівника '" << surname << "':" << endl;
            employees[i] = enterEmployeeData();
            cout << "Дані про працівника оновлено." << endl;
            return;
        }
    }
    cout << "Працівника з прізвищем '" << surname << "' не знайдено." << endl;
}

void deleteEmployee(Employee employees[], int& size, const string& surname) {
    for (int i = 0; i < size; ++i) {
        if (employees[i].surname == surname) {
            for (int j = i; j < size - 1; ++j) {
                employees[j] = employees[j + 1];
            }
            size--;
            cout << "Працівника з прізвищем '" << surname << "' видалено." << endl;
            return;
        }
    }
    cout << "Працівника з прізвищем '" << surname << "' не знайдено." << endl;
}

void saveSearchResultsToFile(const Employee employees[], int size, const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "неможливо почитати." << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        outputFile << employees[i].surname << " " << employees[i].name << " " << employees[i].age << endl;
    }

    outputFile.close();
    cout << "Результати пошуку збережено у файл " << filename << endl;
}

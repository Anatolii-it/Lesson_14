﻿#include <Windows.h>
#include "lib.h"

int x = -1;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
     vector<Employee> employees;
    loadEmployeesFromFile(employees, "employees.txt");

    while (x != 0) {
        system("cls");
         cout << "#----------------------------------------------------------#" <<  endl;
         cout << "#                          Меню                            #" <<  endl;
         cout << "#                      \033[1;31mЗчитати з файлу           - 1\033[0m       #" <<  endl;
         cout << "#                Занести нового працівника       - 2       #" <<  endl;
         cout << "#                      \033[1;32mЗбереження у файл         - 3\033[0m       #" <<  endl;
         cout << "#                      \033[1;33mПошук за віком            - 4 \033[0m      #" <<  endl;
         cout << "#                    \033[1;33mзі збереженням у файл       - 40    \033[0m  #" <<  endl;
         cout << "#                    Пошук за Прізвищем          - 5       #" <<  endl;
         cout << "#                    зі збереженням у файл       - 50      #" <<  endl;
         cout << "#                 \033[1;36mПошук за часткою Прізвища-     - 6\033[0m       #" <<  endl;
         cout << "#                 \033[1;36mзі збереженням у файл          - 60\033[0m      #" <<  endl;
         cout << "#                 Редагування за Прізвищем       - 7       #" <<  endl;
         cout << "#                 Видалення за Прізвищем         - 8       #" <<  endl;
         cout << "#                          Вихід                 - 0       #" <<  endl;
         cout << "#----------------------------------------------------------#" <<  endl;
         cout << "                           мій вибір - ";
        if (!( cin >> x)) {
             cout << "Помилка: Введено не число!" <<  endl;
             cin.clear();
             cin.ignore(INT_MAX, '\n');
        }

        if (x == 1) {
            loadEmployeesFromFile(employees, "employees.txt");
        }
        if (x == 2) {
            employees.push_back(enterEmployeeData());
        }
        if (x == 3) {
            saveEmployeesToFile(employees, "employees.txt");
        }
        if (x == 4) {
            int searchAge;
             cout << "Введіть вік: ";
             cin >> searchAge;
            system("cls");
             vector<Employee> employeesByAge = findEmployeesByAge(employees, searchAge);
            for (const auto& emp : employeesByAge) {
                printEmployee(emp);
            }
        }
        if (x == 5) {
             string searchSurname;
             cout << "Введить призвище для пошуку: ";
             cin >> searchSurname;
            system("cls");
             vector<Employee> employeesBySurname = findEmployeesBySurname(employees, searchSurname);
            for (const auto& emp : employeesBySurname) {
                printEmployee(emp);
            }
        }
        if (x == 6) {
             string searchPartialSurname;
             cout << "Введіть частку призвища для пошуку: ";
             cin >> searchPartialSurname;
            system("cls");
             vector<Employee> employeesByPartialSurname = findEmployeesByPartialSurname(employees, searchPartialSurname);
             cout <<  endl;
            for (const auto& emp : employeesByPartialSurname) {
                printEmployee(emp);
            }
        }
        if (x == 7) { //для редагування працівника
             string editSurname;
             cout << "Введіть прізвище працівника для редагування: ";
             cin >> editSurname;
            system("cls");
            editEmployee(employees, editSurname);
        }
        if (x == 8) { //  видалення працівника
             string deleteSurname;
             cout << "Введіть прізвище працівника для видалення: ";
             cin >> deleteSurname;
            system("cls");
            deleteEmployee(employees, deleteSurname);
        }

        if (x == 0) {
             cout << "До побачення." <<  endl;
            saveEmployeesToFile(employees, "employees.txt");
            return 0;
        }
        if (x == 40) {
            int searchAge;
             cout << "Введіть вік: ";
             cin >> searchAge;
            system("cls");
             vector<Employee> employeesByAge = findEmployeesByAge(employees, searchAge);
            for (const auto& emp : employeesByAge) {
                printEmployee(emp);
            }
            saveSearchResultsToFile(employeesByAge, "by_age.txt");
        }
        if (x == 50) {
             string searchSurname;
             cout << "Введіть призвище для пошуку: ";
             cin >> searchSurname;
            system("cls");
             vector<Employee> employeesBySurname = findEmployeesBySurname(employees, searchSurname);
            for (const auto& emp : employeesBySurname) {
                printEmployee(emp);
            }
            saveSearchResultsToFile(employeesBySurname, "by_surname.txt");
        }
        if (x == 60) {
             string searchPartialSurname;
             cout << "Введіть частку призвища для пошуку: ";
             cin >> searchPartialSurname;
            system("cls");
             vector<Employee> employeesByPartialSurname = findEmployeesByPartialSurname(employees, searchPartialSurname);
             cout <<  endl;
            for (const auto& emp : employeesByPartialSurname) {
                printEmployee(emp);
            }
            saveSearchResultsToFile(employeesByPartialSurname, "l_surname.txt");
        }

         cout << "#---------------------------------#" <<  endl;
         cout << "Натисніть будь-яку клавішу для продовження..." <<  endl;

        _getch();
    }

    return 0;
}

#include "lib.h"

int x = -1;
int employeesSize = 0;
Employee employees[MAX_EMPLOYEES];

int main() {
    loadEmployeesFromFile(employees, employeesSize, "employees.txt");

    while (x != 0) {
        system("cls");
        cout << "#----------------------------------------------------------#" << endl;
        cout << "#                          Меню                            #" << endl;
        cout << "#                      \033[1;31mЗчитати з файлу           - 1\033[0m       #" << endl;
        cout << "#                Занести нового працівника       - 2       #" << endl;
        cout << "#                      \033[1;32mЗбереження у файл         - 3\033[0m       #" << endl;
        cout << "#                      \033[1;33mПошук за віком            - 4 \033[0m      #" << endl;
        cout << "#                    \033[1;33mзі збереженням у файл       - 40    \033[0m  #" << endl;
        cout << "#                    Пошук за Прізвищем          - 5       #" << endl;
        cout << "#                    зі збереженням у файл       - 50      #" << endl;
        cout << "#                 \033[1;36mПошук за часткою Прізвища-     - 6\033[0m       #" << endl;
        cout << "#                 \033[1;36mзі збереженням у файл          - 60\033[0m      #" << endl;
        cout << "#                 Редагування за Прізвищем       - 7       #" << endl;
        cout << "#                 Видалення за Прізвищем         - 8       #" << endl;
        cout << "#                          Вихід                 - 0       #" << endl;
        cout << "#----------------------------------------------------------#" << endl;
        cout << "                           мій вибір - ";

        if (!(cin >> x)) {
            cout << "Помилка: Введено не число!" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

        if (x == 1) {
            loadEmployeesFromFile(employees, employeesSize, "employees.txt");
        }
        else if (x == 2) {
            if (employeesSize < MAX_EMPLOYEES) {
                employees[employeesSize++] = enterEmployeeData();
            }
            else {
                cout << "Помилка: Масив працівників вже заповнений." << endl;
            }
        }
        else if (x == 3) {
            saveEmployeesToFile(employees, employeesSize, "employees.txt");
        }
        else if (x == 4) {
            int searchAge;
            cout << "Введіть вік: ";
            cin >> searchAge;
            system("cls");
            Employee foundEmployees[MAX_EMPLOYEES];
            int count = findEmployeesByAge(employees, employeesSize, searchAge, foundEmployees);
            for (int i = 0; i < count; ++i) {
                printEmployee(foundEmployees[i]);
            }
        }
        else if (x == 5) {
            string searchSurname;
            cout << "Введіть призвище для пошуку: ";
            cin >> searchSurname;
            system("cls");
            Employee foundEmployees[MAX_EMPLOYEES];
            int count = findEmployeesBySurname(employees, employeesSize, searchSurname, foundEmployees);
            for (int i = 0; i < count; ++i) {
                printEmployee(foundEmployees[i]);
            }
        }
        else if (x == 6) {
            string searchPartialSurname;
            cout << "Введіть частку призвища для пошуку: ";
            cin >> searchPartialSurname;
            system("cls");
            Employee foundEmployees[MAX_EMPLOYEES];
            int count = findEmployeesByPartialSurname(employees, employeesSize, searchPartialSurname, foundEmployees);
            for (int i = 0; i < count; ++i) {
                printEmployee(foundEmployees[i]);
            }
        }
        else if (x == 7) {
            string editSurname;
            cout << "Введіть прізвище працівника для редагування: ";
            cin >> editSurname;
            system("cls");
            editEmployee(employees, employeesSize, editSurname);
        }
        else if (x == 8) {
            string deleteSurname;
            cout << "Введіть прізвище працівника для видалення: ";
            cin >> deleteSurname;
            system("cls");
            deleteEmployee(employees, employeesSize, deleteSurname);
        }
        else if (x == 40) {
            int searchAge;
            cout << "Введіть вік: ";
            cin >> searchAge;
            system("cls");
            Employee foundEmployees[MAX_EMPLOYEES];
            int count = findEmployeesByAge(employees, employeesSize, searchAge, foundEmployees);
            saveSearchResultsToFile(foundEmployees, count, "by_age.txt");
        }
        else if (x == 50) {
            string searchSurname;
            cout << "Введіть призвище для пошуку: ";
            cin >> searchSurname;
            system("cls");
            Employee foundEmployees[MAX_EMPLOYEES];
            int count = findEmployeesBySurname(employees, employeesSize, searchSurname, foundEmployees);
            for (int i = 0; i < count; ++i) {
                printEmployee(foundEmployees[i]);
            }
            saveSearchResultsToFile(foundEmployees, count, "by_surname.txt");
        }
        else if (x == 60) {
            string searchPartialSurname;
            cout << "Введіть частку призвища для пошуку: ";
            cin >> searchPartialSurname;
            system("cls");
            Employee foundEmployees[MAX_EMPLOYEES];
            int count = findEmployeesByPartialSurname(employees, employeesSize, searchPartialSurname, foundEmployees);
            for (int i = 0; i < count; ++i) {
                printEmployee(foundEmployees[i]);
            }
            saveSearchResultsToFile(foundEmployees, count, "l_surname.txt");
        }
        else if (x == 0) {
            cout << "До побачення." << endl;
            saveEmployeesToFile(employees, employeesSize, "employees.txt");
            return 0;
        }
        else {
            cout << "Невідома опція. Будь ласка, спробуйте ще раз." << endl;
        }

        cout << "#---------------------------------#" << endl;
        cout << "Натисніть будь-яку клавішу для продовження..." << endl;
        _getch();
    }

    return 0;
}

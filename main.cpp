#include "lib.h"


int main() {

    Fraction f1, f2;
    cout << "Введіть першу дроб:" << std::endl;
    f1.input();

    cout << "Введіть другу дроб:" << std::endl;
    f2.input();
    

    Fraction sum = f1 + f2;
    Fraction diff = f1 - f2;
    Fraction prod = f1 * f2;
    Fraction quot = f1 / f2;

    cout << "-----------------------------------------" << endl;
     cout << "Перша дроб: ";
    f1.print();

     cout << "Друга дроб: ";
    f2.print();

    cout << "-----------------------------------------" << endl;

     cout << "Сума: ";
    sum.print();

     cout << "Віднімання: ";
    diff.print();

     cout << "Множення: ";
    prod.print();

     cout << "Ділення: ";
    quot.print();
    cout << "-----------------------------------------" << endl;
    
    return 0;
}

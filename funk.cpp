#include "lib.h"

int Fraction::gcd(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::reduce() {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denom == 0) {
         cerr << "Помилка: знаменник не може дорівнювати нулю. За умовчанням встановлено 1." <<  endl;
        denominator = 1;
    }
    reduce();
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setNumerator(int num) {
    numerator = num;
    reduce();
}

void Fraction::setDenominator(int denom) {
    if (denom == 0) {
         cerr << "Помилка: знаменник не може дорівнювати нулю. За умовчанням встановлено 1." <<  endl;
        denominator = 1;
    }
    else {
        denominator = denom;
    }
    reduce();
}

void Fraction::input() {
    cout << "Введіть чисельник: ";
    cin >> numerator;
    cout << "Введіть знаменник: ";
    cin >> denominator;
    if (denominator == 0) {
        cerr << "Помилка: знаменник не може дорівнювати нулю. За умовчанням встановлено 1." << std::endl;
        denominator = 1;
    }
    reduce();
}

Fraction Fraction::operator+(const Fraction& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Fraction(num, denom);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Fraction(num, denom);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int num = numerator * other.numerator;
    int denom = denominator * other.denominator;
    return Fraction(num, denom);
}

Fraction Fraction::operator/(const Fraction& other) const {
    int num = numerator * other.denominator;
    int denom = denominator * other.numerator;
    return Fraction(num, denom);
}


void Fraction::print() const {
     cout << numerator << "/" << denominator <<  endl;
}

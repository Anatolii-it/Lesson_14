#ifndef LIB_H
#define LIB_H
#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const;
    void reduce();

public:
    Fraction(int num = 0, int denom = 1);

    
    int getNumerator() const;
    int getDenominator() const;

    
    void setNumerator(int num);
    void setDenominator(int denom);

    
    Fraction operator+(const Fraction& other) const;

    
    Fraction operator-(const Fraction& other) const;

    
    Fraction operator*(const Fraction& other) const;

    
    Fraction operator/(const Fraction& other) const;
    void input();

    
    void print() const;
};

#endif

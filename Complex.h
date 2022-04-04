#pragma once

#include "Fraction.h"

class Complex {
private:
    Fraction real;
    Fraction imag;
public:
    // Constructors
    Complex(const Fraction& real, const Fraction& imag);
    Complex(const Complex& complex);
    Complex(const Fraction& number);
    Complex();
    // Getters and Setters
    Fraction get_real() const;
    Fraction get_imag() const;
    void set_real(const Fraction& real);
    void set_imag(const Fraction& imag);
    // Operations methods
    Complex add(const Complex& complex) const;
    void add_mut(const Complex& complex);

    Complex subtract(const Complex& complex) const;
    void subtract_mut(const Complex& complex);

    Complex multiply(const Complex& complex) const;
    void multiply_mut(const Complex& complex);

    Complex divide(const Complex& complex) const;
    void divide_mut(const Complex& complex);

    Complex conjugate() const;
    void conjugate_mut();

    Complex scale(const Fraction& fraction) const;
    void scale_mut(const Fraction& fraction);

    Fraction abs() const;

    // Comparison methods
    bool eq(const Complex& complex) const;
    bool ne(const Complex& complex) const;
    // Operator overload
    Complex& operator=(const Complex& complex);
    //
    Complex operator+(const Complex& complex) const;
    Complex operator-(const Complex& complex) const;
    Complex operator*(const Complex& complex) const;
    Complex operator/(const Complex& complex) const;
    //
    Complex& operator+=(const Complex& complex);
    Complex& operator-=(const Complex& complex);
    Complex& operator*=(const Complex& complex);
    Complex& operator/=(const Complex& complex);
    // Comparison operators overloads
    bool operator==(const Complex& complex) const;
    bool operator!=(const Complex& complex) const;
    // Stream overloads
    friend std::ostream& operator<<(std::ostream& os, const Complex& fraction);
    friend std::istream& operator>>(std::istream& is, Complex& fraction);
    //
    std::string to_string(bool reduced=false, bool as_doubles=false) const;
    void print(bool reduced=false, bool as_doubles=false) const;
};
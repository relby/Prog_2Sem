#include <string>
#include <iostream>
#include <cmath>
#include "Complex.h"
#include "Fraction.h"

// Constructors
Complex::Complex(const Fraction& real, const Fraction& imag) : real(real), imag(imag) {}
Complex::Complex(const Complex& complex) : real(complex.real), imag(complex.imag) {}
Complex::Complex(const Fraction& number) : real(number), imag(0) {}
Complex::Complex() {}

// Getters and Setters
Fraction Complex::get_real() const {
    return this->real;
}
Fraction Complex::get_imag() const {
    return this->imag;
}
void Complex::set_real(const Fraction& real) {
    this->real = real;
}
void Complex::set_imag(const Fraction& imag) {
    this->imag = imag;
}
// Operations methods
Complex Complex::add(const Complex& complex) const
{
    return Complex(
        this->real + complex.real,
        this->imag + complex.imag);
}
void Complex::add_mut(const Complex& complex)
{
    this->real += complex.real;
    this->imag += complex.imag;
}
Complex Complex::subtract(const Complex& complex) const
{
    return Complex(
        this->real - complex.real,
        this->imag - complex.imag);
}
void Complex::subtract_mut(const Complex& complex)
{
    this->real -= complex.real;
    this->imag -= complex.imag;
}
Complex Complex::multiply(const Complex& complex) const
{
    return Complex(
        this->real * complex.real - this->imag * complex.imag,
        this->imag * complex.real + this->real * complex.imag);
};
void Complex::multiply_mut(const Complex& complex)
{
    auto _real = this->real;
    auto _imag = this->imag;
    this->real = _real * complex.real - _imag * complex.imag;
    this->imag = _imag * complex.real + _real * complex.imag;
}
Complex Complex::divide(const Complex& complex) const
{
    if (complex.real == Fraction(0) && complex.imag == Fraction(0))
        throw std::invalid_argument("Can't divide by zero!");
    return Complex(
        (this->real * complex.real + this->imag * complex.imag) / (complex.real * complex.real + complex.imag * complex.imag),
        (this->imag * complex.real - this->real * complex.imag) / (complex.real * complex.real + complex.imag * complex.imag));
}
void Complex::divide_mut(const Complex& complex)
{
    auto _real = this->real;
    auto _imag = this->imag;
    this->real = (_real * complex.real + _imag * complex.imag) / (complex.real * complex.real + complex.imag * complex.imag);
    this->imag = (_imag * complex.real - _real * complex.imag) / (complex.real * complex.real + complex.imag * complex.imag);
}

Complex Complex::conjugate() const
{
    return Complex(
        this->real,
        -this->imag);
}
void Complex::conjugate_mut()
{
    this->imag = -this->imag;
}
Complex Complex::scale(const Fraction& fraction) const
{
    return Complex(
        this->real * fraction,
        this->imag * fraction);
}
void Complex::scale_mut(const Fraction& fraction)
{
    this->real *= fraction;
    this->imag *= fraction;
}

Fraction Complex::abs() const
{
    return Fraction(std::sqrt((this->real*this->real + this->imag*this->imag).to_double()));
}
// Comparison methods
bool Complex::eq(const Complex& complex) const
{
    return this->real == this->imag;
}

bool Complex::ne(const Complex& complex) const
{
    return this->real != this->imag;
}

// Operator overload
Complex& Complex::operator=(const Complex& complex)
{
    this->real = complex.real;
    this->imag = complex.imag;
    return *this;
}
//
Complex Complex::operator+(const Complex& complex) const
{
    return this->add(complex);
}
Complex Complex::operator-(const Complex& complex) const
{
    return this->subtract(complex);
}
Complex Complex::operator*(const Complex& complex) const
{
    return this->multiply(complex);
}
Complex Complex::operator/(const Complex& complex) const
{
    return this->divide(complex);
}
//
Complex& Complex::operator+=(const Complex& complex)
{
    this->add_mut(complex);
    return *this;
}
Complex& Complex::operator-=(const Complex& complex)
{
    this->subtract_mut(complex);
    return *this;
}
Complex& Complex::operator*=(const Complex& complex)
{
    this->multiply_mut(complex);
    return *this;
}
Complex& Complex::operator/=(const Complex& complex)
{
    this->divide_mut(complex);
    return *this;
}
// Comparison operators overload
bool Complex::operator==(const Complex& complex) const
{
    return this->eq(complex);
}

bool Complex::operator!=(const Complex& complex) const
{
    return this->ne(complex);
}
// Stream overloads
std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
    os << complex.to_string(true, true);
    return os;
}
std::istream& operator>>(std::istream& is, Complex& complex)
{
    is >> complex.real >> complex.imag;
    return is;
}

std::string Complex::to_string(bool reduced, bool as_double) const
{
    if (this->real != Fraction(0))
        return "(" + this->real.to_string(reduced, as_double) + (this->imag >= Fraction(0) ? "+" : "") + this->imag.to_string(reduced, as_double) + "i)";
    else
    {
        return this->imag.to_string(reduced, as_double) + "i";
    }
}

void Complex::print(bool reduced, bool as_double) const
{
    std::cout << this->to_string(reduced, as_double);
}
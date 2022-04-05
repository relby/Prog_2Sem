#include <iostream>
#include <stdexcept>
#include <numeric>
#include <string>
#include "Fraction.h"

// Constructors
Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    this->check_input(denominator);
}
Fraction::Fraction(const Fraction& fraction) : numerator(fraction.numerator), denominator(fraction.denominator) {}
Fraction::Fraction(int number) : numerator(number), denominator(1) {}
Fraction::Fraction(double number) : numerator(static_cast<int>(number * 10)), denominator(10) {}
Fraction::Fraction() : numerator(0), denominator(1) {}

// Getters and Setters
int Fraction::get_numerator() const {
    return this->numerator;
}
int Fraction::get_denominator() const {
    return this->denominator;
}
void Fraction::set_numerator(int numerator) {
    this->numerator = numerator;
}
void Fraction::set_denominator(int denominator) {
    this->denominator = denominator;
}

// Operations methods
Fraction Fraction::add(const Fraction& fraction) const {
    return Fraction(
        this->numerator * fraction.denominator + fraction.numerator * this->denominator,
        this->denominator * fraction.denominator
    ).reduce();
}

void Fraction::add_mut(const Fraction& fraction) {
    this->numerator = this->numerator * fraction.denominator + fraction.numerator * this->denominator;
    this->denominator = this->denominator * fraction.denominator;
    this->reduce_mut();
}

Fraction Fraction::subtract(const Fraction& fraction) const {
    return Fraction(
        this->numerator * fraction.denominator - fraction.numerator * this->denominator,
        this->denominator * fraction.denominator
    ).reduce();
}

void Fraction::subtract_mut(const Fraction& fraction) {
    this->numerator = this->numerator * fraction.denominator - fraction.numerator * this->denominator;
    this->denominator = this->denominator * fraction.denominator;
    this->reduce_mut();
}

Fraction Fraction::multiply(const Fraction& fraction) const {
    return Fraction(
        this->numerator * fraction.numerator,
        this->denominator * fraction.denominator
    ).reduce();
}

void Fraction::multiply_mut(const Fraction& fraction) {
    this->numerator *= fraction.numerator;
    this->denominator *= fraction.denominator;
    this->reduce_mut();
}

Fraction Fraction::divide(const Fraction& fraction) const {
    return Fraction(
        this->numerator * fraction.denominator,
        this->denominator * fraction.numerator
    ).reduce();
}

void Fraction::divide_mut(const Fraction& fraction) {
    int sign = fraction.numerator < 0 ? -1 : 1;
    this->numerator *= sign * fraction.denominator;
    this->denominator *= sign * fraction.numerator;
    this->reduce_mut();
}

Fraction Fraction::reduce() const {
    int gcd = std::gcd(this->numerator, this->denominator);
    return Fraction(
        this->numerator / gcd,
        this->denominator / gcd
    );
}

void Fraction::reduce_mut() {
    int gcd = std::gcd(this->numerator, this->denominator);
    this->numerator /= gcd;
    this->denominator /= gcd;
}

Fraction Fraction::opposite() const {
    return Fraction(
        -this->numerator,
        this->denominator
    );
}
void Fraction::opposite_mut() {
    this->numerator = -this->numerator;
}

// Comparison methods
bool Fraction::eq(const Fraction& fraction) const {
    Fraction a = this->reduce();
    Fraction b = fraction.reduce();
    return a.numerator == b.numerator && a.denominator == b.denominator;
}

bool Fraction::ne(const Fraction& fraction) const {
    Fraction a = this->reduce();
    Fraction b = fraction.reduce();
    return a.numerator != b.numerator || a.denominator != b.denominator;
}

bool Fraction::lt(const Fraction& fraction) const {
    Fraction a = this->reduce();
    Fraction b = fraction.reduce();
    int lcm = std::lcm(a.denominator, fraction.denominator);
    a = a.multiply(lcm / a.denominator);
    b = b.multiply(lcm / b.denominator);
    return a.numerator < b.numerator;
}

bool Fraction::gt(const Fraction& fraction) const {
    Fraction a = this->reduce();
    Fraction b = fraction.reduce();
    int lcm = std::lcm(a.denominator, fraction.denominator);
    a = a.multiply(lcm / a.denominator);
    b = b.multiply(lcm / b.denominator);
    return a.numerator > b.numerator;
}

bool Fraction::le(const Fraction& fraction) const {
    Fraction a = this->reduce();
    Fraction b = fraction.reduce();
    int lcm = std::lcm(a.denominator, fraction.denominator);
    a = a.multiply(lcm / a.denominator);
    b = b.multiply(lcm / b.denominator);
    return a.numerator <= b.numerator;
}

bool Fraction::ge(const Fraction& fraction) const {
    Fraction a = this->reduce();
    Fraction b = fraction.reduce();
    int lcm = std::lcm(a.denominator, fraction.denominator);
    a = a.multiply(lcm / a.denominator);
    b = b.multiply(lcm / b.denominator);
    return a.numerator >= b.numerator;
}

// Operator overload
Fraction& Fraction::operator=(const Fraction& fraction) {
    this->numerator = fraction.numerator;
    this->denominator = fraction.denominator;
    return *this;
}
//
Fraction Fraction::operator+(const Fraction& fraction) const {
    return this->add(fraction);
}
Fraction Fraction::operator-(const Fraction& fraction) const {
    return this->subtract(fraction);
}
Fraction Fraction::operator-() const {
    return this->opposite();
}
Fraction Fraction::operator*(const Fraction& fraction) const {
    return this->multiply(fraction);
}
Fraction Fraction::operator/(const Fraction& fraction) const {
    return this->divide(fraction);
}
//
Fraction& Fraction::operator+=(const Fraction& fraction) {
    this->add_mut(fraction);
    return *this;
}
Fraction& Fraction::operator-=(const Fraction& fraction) {
    this->subtract_mut(fraction);
    return *this;
}
Fraction& Fraction::operator*=(const Fraction& fraction) {
    this->multiply_mut(fraction);
    return *this;
}
Fraction& Fraction::operator/=(const Fraction& fraction) {
    this->divide_mut(fraction);
    return *this;
}
// Comparison operators overload
bool Fraction::operator==(const Fraction& fraction) const {
    return this->eq(fraction);
}
bool Fraction::operator!=(const Fraction& fraction) const {
    return this->ne(fraction);
}
bool Fraction::operator<(const Fraction& fraction) const {
    return this->lt(fraction);
}
bool Fraction::operator>(const Fraction& fraction) const {
    return this->gt(fraction);
}
bool Fraction::operator<=(const Fraction& fraction) const {
    return this->le(fraction);
}
bool Fraction::operator>=(const Fraction& fraction) const {
    return this->ge(fraction);
}
// Stream overloads
std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.to_string(true, true);
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& fraction) {
    is >> fraction.numerator >> fraction.denominator;
    fraction.check_input(fraction.denominator);
    return is;
}
//
Fraction::operator double() const {
    return this->to_double();
}
//
std::string Fraction::to_string(bool reduced, bool as_double) const {
    if (as_double)
        return std::to_string(this->numerator / (double)this->denominator);
    if (!reduced)
        return std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
    Fraction a = this->reduce();
    if (a.numerator == 0)
        return "0";
    if (a.denominator == 1)
        return std::to_string(a.numerator);
    return std::to_string(a.numerator) + "/" + std::to_string(a.denominator);
}

double Fraction::to_double() const {
    return static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
}

void Fraction::print(bool reduced, bool as_double) const {
    std::cout << this->to_string(reduced, as_double) << '\n';
}

// Private methods
void Fraction::check_input(int denominator) {
    if (denominator <= 0)
        throw std::invalid_argument("denominator must be greater than zero");
}
#pragma once

class Fraction {
private:
    int numerator;
    int denominator;

    void check_input(int denominator);
public:
    // Constructors
    Fraction(int numerator, int denominator);
    Fraction(const Fraction& fraction);
    Fraction(int number);
    Fraction(double number);
    Fraction();
    // Getters and Setters
    int get_numerator() const;
    int get_denominator() const;
    void set_numerator(int numerator);
    void set_denominator(int denominator);
    // Operations methods
    Fraction add(const Fraction& fraction) const;
    void add_mut(const Fraction& fraction);

    Fraction subtract(const Fraction& fraction) const;
    void subtract_mut(const Fraction& fraction);

    Fraction multiply(const Fraction& fraction) const;
    void multiply_mut(const Fraction& fraction);

    Fraction divide(const Fraction& fraction) const;
    void divide_mut(const Fraction& fraction);

    Fraction reduce() const;
    void reduce_mut();

    Fraction opposite() const;
    void opposite_mut();

    // Comparison methods
    bool eq(const Fraction& fraction) const;
    bool ne(const Fraction& fraction) const;
    bool lt(const Fraction& fraction) const;
    bool gt(const Fraction& fraction) const;
    bool le(const Fraction& fraction) const;
    bool ge(const Fraction& fraction) const;

    // Operator overload
    Fraction& operator=(const Fraction& fraction);
    //
    Fraction operator+(const Fraction& fraction) const;
    Fraction operator-(const Fraction& fraction) const;
    Fraction operator-() const;
    Fraction operator*(const Fraction& fraction) const;
    Fraction operator/(const Fraction& fraction) const;
    //
    Fraction& operator+=(const Fraction& fraction);
    Fraction& operator-=(const Fraction& fraction);
    Fraction& operator*=(const Fraction& fraction);
    Fraction& operator/=(const Fraction& fraction);
    // Comparison operators overloads
    bool operator==(const Fraction& fraction) const;
    bool operator!=(const Fraction& fraction) const;
    bool operator<(const Fraction& fraction) const;
    bool operator>(const Fraction& fraction) const;
    bool operator<=(const Fraction& fraction) const;
    bool operator>=(const Fraction& fraction) const;
    // Stream overloads
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& is, Fraction& fraction);
    //
    operator double() const;
    //
    std::string to_string(bool reduced=false, bool as_double=false) const;
    double to_double() const;
    void print(bool reduced=false, bool as_double=false) const;
};
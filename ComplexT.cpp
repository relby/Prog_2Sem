#include <iostream>

template <typename T>
class Complex {
private:
    T real;
    T imag;
public:
    // Constructors
    Complex(const T& real, const T& imag) : real(real), imag(imag) {}
    Complex(const Complex<T>& complex) : real(complex.real), imag(complex.imag) {}
    Complex(const T& number) : real(number), imag((T)0) {}
    Complex() {}
    // Getters and Setters
    T get_real() const {
        return this->real;
    }
    T get_imag() const {
        return this->imag;
    }
    void set_real(const T& real) {
        this->real = real;
    }
    void set_imag(const T& imag) {
        this->imag = imag;
    }
    // Operations methods
    Complex<T> add(const Complex<T>& complex) const {
        return {this->real + complex.real,
                this->imag + complex.imag};
    }
    void add_mut(const Complex<T>& complex) {
        this->real += complex.real;
        this->imag += complex.imag;
    }

    Complex<T> subtract(const Complex<T>& complex) const {
        return {this->real - complex.real,
                this->imag - complex.imag};
    }
    void subtract_mut(const Complex<T>& complex) {
        this->real -= complex.real;
        this->imag -= complex.imag;
    }

    Complex<T> multiply(const Complex<T>& complex) const {
        return {this->real * complex.real - this->imag * complex.imag,
                this->imag * complex.real + this->real * complex.imag};
    }
    void multiply_mut(const Complex<T>& complex) {
        T _real = this->real;
        T _imag = this->imag;
        this->real = _real * complex.real - _imag * complex.imag;
        this->imag = _imag * complex.real + _real * complex.imag;
    }

    Complex<T> divide(const Complex<T>& complex) const {
        if (complex.real == 0 && complex.imag == 0)
            throw std::invalid_argument("Can't divide by zero!");
        return {(this->real * complex.real + this->imag * complex.imag) / (complex.real * complex.real + complex.imag * complex.imag),
                (this->imag * complex.real - this->real * complex.imag) / (complex.real * complex.real + complex.imag * complex.imag)};
    }
    void divide_mut(const Complex<T>& complex) {
        if (complex.real == 0 && complex.imag == 0)
            throw std::invalid_argument("Can't divide by zero!");
        T _real = this->real;
        T _imag = this->imag;
        this->real = (_real * complex.real + _imag * complex.imag) / (complex.real * complex.real + complex.imag * complex.imag);
        this->imag = (_imag * complex.real - _real * complex.imag) / (complex.real * complex.real + complex.imag * complex.imag);
    }
    Complex<T> conjugate() const {
        return {this->real, -this->imag};
    }
    void conjugate_mut() {
        this->imag = -this->imag;
    }
    Complex<T> opposite() const {
        return {-this->real, -this->imag};
    }
    void opposite_mut() {
        this->real = -this->real;
        this->imag = -this->imag;
    }
    // Comparison methods
    bool eq(const Complex<T>& complex) const {
        return this->real == complex.real && this->imag == complex.imag;
    }
    bool ne(const Complex<T>& complex) const {
        return this->real != complex.real || this->imag != complex.imag;
    }
    // Operator overload
    Complex<T>& operator=(const Complex<T>& complex) {
        this->real = complex.real;
        this->imag = complex.imag;
        return *this;
    }
    //
    Complex<T> operator+(const Complex<T>& complex) const {
        return this->add(complex);
    }
    Complex<T> operator-(const Complex<T>& complex) const {
        return this->subtract(complex);
    }
    Complex<T> operator*(const Complex<T>& complex) const {
        return this->multiply(complex);
    }
    Complex<T> operator/(const Complex<T>& complex) const {
        return this->divide(complex);
    }
    //
    Complex<T>& operator+=(const Complex<T>& complex) {
        this->add_mut(complex);
        return *this;
    }
    Complex<T>& operator-=(const Complex<T>& complex) {
        this->subtract_mut(complex);
        return *this;
    }
    Complex<T>& operator*=(const Complex<T>& complex) {
        this->multiply_mut(complex);
        return *this;
    }
    Complex<T>& operator/=(const Complex<T>& complex) {
        this->divide_mut(complex);
        return *this;
    }
    // Unary operators
    Complex<T> operator~() {
        return this->conjugate();
    }
    Complex<T>& operator+() {
        return *this;
    }
    Complex<T> operator-() {
        return this->opposite();
    }
    Complex<T>& operator++() {
        this->real++;
        this->imag++;
        return *this;
    }
    Complex<T> operator++(int) {
        Complex<T> temp = *this;
        ++*this;
        return temp;
    }
    Complex<T>& operator--() {
        this->real--;
        this->imag--;
        return *this;
    }
    Complex<T> operator--(int) {
        Complex<T> temp = *this;
        --*this;
        return temp;
    }
    // Comparison operators overloads
    bool operator==(const Complex<T>& complex) const {
        return this->eq(complex);
    }
    bool operator!=(const Complex<T>& complex) const {
        return this->ne(complex);
    }
    // Stream overloads
    template <typename V>
    operator Complex<V>() {
        return {(V)this->real, (V)this->imag};
    }
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex) {
        std::cout << '(' << complex.real << ',' << complex.imag << ')';
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Complex& complex) {
        std::cin >> complex.real >> complex.imag;
        return is;
    }
    //
    void print() const {
        std::cout << '(' << this->real << ',' << this->imag << ")\n";
    }
};
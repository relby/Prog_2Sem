#include <cassert>
#include <iostream>
#include <cmath>
#include <initializer_list>

template <typename T>
class Vector {
protected:
    T* array;
    size_t size;
public:
    Vector(size_t _size) : size(_size) {
        array = new T[_size];
    }
    Vector(T* _array, size_t _size) : size(_size) {
        array = new T[_size];
        for (size_t i = 0; i < _size; i++) {
            array[i] = _array[i];
        }
    }
    Vector(std::initializer_list<T> list) : size(list.size()) {
        array = new T[size];
        for (size_t i = 0; i < size; i++) {
            array[i] = list.begin()[i];
        }
    }
    Vector(const Vector<T>& vector) : size(vector.size) {
        array = new T[size];
        for (size_t i = 0; i < size; i++) {
            array[i] = vector.array[i];
        }
    }

    size_t get_size() {
        return size;
    }
    T* begin() {
        return array;
    }
    T* end() {
        return array + size;
    }

    T& operator[](size_t index) {
        assert(index < size);
        return array[index];
    }

    friend std::ostream& operator<<(std::ostream& os, Vector<T>& vector) {
        for (size_t i = 0; i < vector.size; i++) {
            os << vector[i] << ' ';
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Vector<T>& vector) {
        for (size_t i = 0; i < vector.size; i++) {
            is >> vector[i];
        }
        return is;
    }

    virtual ~Vector() {
        delete[] array;
    }
};

template<typename T>
class MathVector : public Vector<T> {
public:
    MathVector(size_t _size) : Vector<T>(_size) {}
    MathVector(T* _array, size_t _size) : Vector<T>(_array, _size) {}
    MathVector(std::initializer_list<T> list) : Vector<T>(list) {}
    MathVector(const Vector<T>& vector) : Vector<T>(vector) {}
    MathVector(const MathVector<T>& math_vector) : Vector<T>(math_vector.array, math_vector.size) {}
    //Math
    double length() const {
        T sum = T();
        for (size_t i = 0; i < this->size; i++) {
            sum += this->array[i] * this->array[i];
        }
        return std::sqrt((double)sum);
    }

    T dot_product(const MathVector<T>& vector) const {
        assert(this->size == vector.size);
        T sum = T();
        for (size_t i = 0; i < this->size; i++) {
            sum += this->array[i] * vector.array[i];
        }
        return sum;
    }

    double angle(const MathVector<T>& vector) const {
        return this->dot_product(vector) / (this->length() * vector.length());
    }

    MathVector<T> operator+(const MathVector<T>& rhs) const {
        assert(this->size == rhs.size);
        T* a = new T[this->size];
        for (size_t i = 0; i < this->size; i++) {
            a[i] = this->array[i] + rhs.array[i];
        }
        MathVector<T> out(a, this->size);
        delete[] a;
        return out;
    }
    MathVector<T> operator-(const MathVector<T>& rhs) const {
        assert(this->size == rhs.size);
        T* a = new T[this->size];
        for (size_t i = 0; i < this->size; i++) {
            a[i] = this->array[i] - rhs.array[i];
        }
        MathVector<T> out(a, this->size);
        delete[] a;
        return out;
    }
    MathVector<T> operator*(T scale) const {
        T* a = new T[this->size];
        for (size_t i = 0; i < this->size; i++) {
            a[i] =this->array[i] * scale;
        }
        MathVector<T> out(a, this->size);
        delete[] a;
        return out;
    }
    T operator*(const MathVector<T>& rhs) const {
        return this->dot_product(rhs);
    }

    bool operator==(const MathVector<T>& rhs) const {
        if (this->size != rhs.size) return false;
        for (size_t i = 0; i < this->size; i++) {
            if (this->array[i] != rhs.array[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const MathVector<T>& rhs) const {
        if (this->size != rhs.size) return true;
        for (size_t i = 0; i < this->size; i++) {
            if (this->array[i] != rhs.array[i]) {
                return true;
            }
        }
        return false;
    }
};
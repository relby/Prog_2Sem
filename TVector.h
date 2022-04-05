#include <cassert>
#include <iostream>
#include <cmath>
#include <initializer_list>

template <typename T>
class TVector {
private:
    T* array;
    size_t size;
public:
    TVector(size_t _size) : size(_size) {
        array = new T[_size];
    }
    TVector(const TVector<T>& vector) : size(vector.size) {
        array = new T[size];
        for (size_t i = 0; i < size; i++) {
            array[i] = vector.array[i];
        }
    }
    TVector(T* _array, size_t _size) : size(_size) {
        array = new T[_size];
        for (size_t i = 0; i < _size; i++) {
            array[i] = _array[i];
        }
    }
    TVector(std::initializer_list<T> list) : size(list.size()) {
        array = new T[size];
        for (size_t i = 0; i < size; i++) {
            array[i] = list.begin()[i];
        }
    }

    size_t get_size() {
        return size;
    }
    T* begin() {
        return array[0];
    }
    T* end() {
        return array[size];
    }
    
    //Math
    double length() {
        T sum = T();
        for (size_t i = 0; i < size; i++) {
            sum += array[i] * array[i];
            std::cout << sum << '\n';
        }
        return std::sqrt((double)sum);
    }
    int angle() {
        //
    }
    TVector<T> operator+(const TVector<T>& rhs) const {
        assert(size == rhs.size);
        T* out = new T[size];
        for (size_t i = 0; i < size; i++) {
            out[i] = array[i] + rhs.array[i];
        }
        return out;
    }
    TVector<T> operator-(const TVector<T>& rhs) const {
        assert(size == rhs.size);
        T* out = new T[size];
        for (size_t i = 0; i < size; i++) {
            out[i] = array[i] - rhs.array[i];
        }
        return out;
    }
    T operator*(const TVector<T>& rhs) const {
        assert(size == rhs.size);
        T sum = T();
        for (size_t i = 0; i < size; i++) {
            sum += array[i] * rhs.array[i];
        }
        return sum;
    }

    bool operator==(const TVector<T>& rhs) const {
        if (size != rhs.size) return false;
        for (size_t i = 0; i < size; i++) {
            if (array[i] != rhs.array[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const TVector<T>& rhs) const {
        if (size != rhs.size) return true;
        for (size_t i = 0; i < size; i++) {
            if (array[i] != rhs.array[i]) {
                return true;
            }
        }
        return false;
    }

    T& operator[](size_t index) {
        assert(index < size);
        return array[index];
    }

    friend std::ostream& operator<<(std::ostream& os, TVector<T>& vector) {
        for (size_t i = 0; i < vector.len(); i++) {
            os << vector[i] << ' ';
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, TVector<T>& vector) {
        for (size_t i = 0; i < vector.len(); i++) {
            is >> vector[i];
        }
        return is;
    }

    ~TVector() {
        delete[] array;
    }
};
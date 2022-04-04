#include <cassert>

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
            array[i] = vector[i];
        }
    }
    TVector(T* _array, size_t _size) : size(_size) {
        array = new T[_size];
        for (size_t i = 0; i < _size; i++) {
            array[i] = _array[i];
        }
    }


    TVector<T> operator+(const TVector<T>& rhs) const {
        assert(size == rhs.size);
        T* out = new T[size];
        for (size_t i = 0; i < size; i++) {
            out[i] = array[i] + rhs[i];
        }
        return out;
    }
    TVector<T> operator-(const TVector<T>& rhs) const {
        assert(size == rhs.size);
        T* out = new T[size];
        for (size_t i = 0; i < size; i++) {
            out[i] = array[i] - rhs[i];
        }
        return out;
    }
    T operator*(const TVector<T>& rhs) const {
        assert(size == rhs.size);
        T sum = T();
        for (size_t i = 0; i < size; i++) {
            sum += array[i] * rhs[i];
        }
        return sum;
    }
    T& operator[](size_t index) {
        assert(index < this->size);
        return this->array[index];
    }
    ~TVector() {
        delete[] this->array;
    }
};
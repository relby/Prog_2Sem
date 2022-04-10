#include <iostream>
#include "Fraction.h"
#include "Vector.h"
#include <cmath>

using namespace std;

int main() {
    Vector<int> v1 = {1, -2, 3};
    Vector<int> v2 = {2, 3, -1};
    MathVector<int> mv1 = v1;
    MathVector<int> mv2 = v2;
    MathVector<Fraction> mv3 = {Fraction(3, 4), Fraction(-1, 2)};
    cout << v1 << '\n';
    for (int& x : v1) {
        x = 4;
    }
    cout << v1 << '\n';
    cout <<  (mv1 * mv2) << '\n';
    cout << mv1.length() << '\n';
    cout << mv3.length() << '\n';

    cout << mv1.angle(v2);
}
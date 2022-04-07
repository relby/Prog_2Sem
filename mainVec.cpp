#include <iostream>
#include "Fraction.h"
#include "TVector.h"
#include <cmath>

using namespace std;

int main() {
    TVector<int> v1 = {1, -2, 3};
    TVector<int> v2 = {2, 3, -1};
    TVector<Fraction> v3 = {Fraction(3, 4), Fraction(-1, 2)};

    cout <<  (v1 * v2) << '\n';
    cout << v1.length() << '\n';
    cout << v3.length() << '\n';

    cout << v1.angle(v2);
}
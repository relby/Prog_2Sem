#include <iostream>
#include "Fraction.h"
#include "Vector.h"
#include "test.h"
#include <cmath>

using namespace std;

int main() {
    // Master m("test");
    // Slave s(3.54, 4.3);
    // cout << m.get_a() << '\n';
    // cout << s.get_a() << '\n';

    Vector<int> v1 = {1, -2, 3};
    Vector<int> v2 = {2, 3, -1};
    Vector<double> v3 = {10.2, -2.4, 3.75};
    MathVector<int> mv1 = v1;
    MathVector<int> mv2 = v2;
    MathVector<Fraction> mv3 = {Fraction(3, 4), Fraction(-1, 2)};
    MathVector<double> mv4 = {10.2, -2.4, 3.75};
    cout << v1 << '\n';
    for (int& x : v1) {
        x = 4;
    }
    v1[v1.get_size() - 1] = 10;
    cout << v1 << '\n';
    cout << (mv1 * mv2) << '\n';
    cout << mv1.length() << '\n';
    cout << mv3.length() << '\n';

    auto x = (mv4 + mv4) * 7;
    cout << x << '\n';
    
    cout << mv1.angle(mv2) << '\n';

    cin >> v3;
    cout << v3 << '\n';
}   
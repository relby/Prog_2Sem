#include <iostream>
#include <cassert>
#include "Fraction.h"
#include "ComplexT.cpp"
using namespace std;

int main() {
    Complex<int> c1(1, 3);
    Complex<double> c2(3.4, 4.5);
    Complex<long long> c3(7, -3);
    Complex<Fraction> c4(3.9, -9.9);
    Fraction asdfasdf(3);
    cout << c4[Real] << ' ' << c4[Imag] << '\n';
    auto c5 = c1.add(c2).multiply(c3).subtract(c2).add(c1).divide(c4);
    auto c6 = ((c1 + c2) * c3 - c2 + c1) / c4;
    assert(c5 == c6);
    c5.print();
    c6.print();
    Complex<double> t1;
    cin >> t1;
    cout << t1 << '\n';
    Complex<Fraction> t2;
    cin >> t2;
    cout << t2 << '\n';
    cout << "~ " << ~t1 << '\n';
    cout << "pre++ " << ++t1 << '\n';
    cout << "post++ "<< t1++ << '\n';
    cout << "pre-- " << --t1 << '\n';
    cout << "post-- " << t1-- << '\n';
    cout << "- " << -t1 << '\n';
    cout << "+ "<< +t1 << '\n';
    auto tmp = t1;
    t1 *= c4;
    assert(tmp * c4 == t1);
    tmp = t1;
    t1 /= c4;
    assert(tmp / c4 == t1);
    tmp = t1;
    t1 += c4;
    assert(tmp + c4 == t1);
    tmp = t1;
    t1 -= c4;
    assert(tmp - c4 == t1);
}
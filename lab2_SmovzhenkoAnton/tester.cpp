#include "Segment.h"

#include <iostream>

//Smovzhenko Anton

using namespace std;

int main() {
    Point x(1, 1);
    Point y(2, 2);
    Point z(3, 3);
    cout << "Segment processing================" << endl;
    Segment s, s1(x, y), s2(y, x), s3(z, y), s4(x, z);
    cout << s << endl;
    cout << "Length=" << s.length() << endl;
    cout << z << endl;
    cout << "Distance=" << s.distance(z) << endl;
}

#include "Segment.h"

#include <iostream>


using namespace std;

int main() {
    Point x(2, 3);

    Point y(4, 1);
    Point z(5, 5);
    cout << "Segment=" << endl;


    Segment s, s1(x, y), s2(y, x), s3(z, y), s4(x, z);
    cout << s << endl;

    cout << "l=" << s.length() << endl;

    cout << z << endl;
    cout << "Dist=" << s.distance(z) << endl;
}

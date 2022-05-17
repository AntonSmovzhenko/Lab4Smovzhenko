#include <iostream>
#include "Date.h"

//Smovzhenko Anton
using namespace std;

int main() {
    cout << "Begin" << endl;
    try {
        Date::showDefault();

        Date::setDefault(17, Date::Month(8), 1979);

        Date::showDefault();

        Date::setDefault();

        Date d, d1(10, 11, 2003), d2(d1);

        Date WrongDate(32, 13, 2222);

    } catch (Date::BadDate wrong)
    {
        cerr << "Wrong date: " << wrong << endl;
    }

    cout << "End" << endl;
}

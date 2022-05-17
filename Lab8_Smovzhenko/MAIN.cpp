#include <iostream>
#include <cassert>
#include "Arrays.h"


// Anton Smovzhenko

using namespace std;
int main() {

    //////////////////////////////

    cout << "Testing array" << endl;

    const size_t size = 8;
    Array<size, string> myArray;
    cout << "My first array length is " << myArray.size() << endl;

    myArray[0] = "Zero";
    myArray[3] = "Three";
    myArray[7] = "Seven";

    cout << myArray << endl;

    assert(myArray[0] == "Zero");
    assert(myArray[3] == "Three");
    assert(myArray[7] == "Seven");

    //////////////////////////////

    cout << "Errors testing" << endl;
  

    try {
        myArray[666] = "qwerty";
    } catch (Array<size, string>::WrongArray& E) {
        cout << "The error is: " << E.whyError() << endl;
    }
   

    try {
        myArray[-1] = "qwerty";
    } catch (Array<size, string>::WrongArray& E) {
        cout << "The error is: " << E.whyError() << endl << endl;
    }
   
    //////////////////////////////

    Array<size, int> mySecondArray;
    for (size_t i = 0; i < size; i++)
    {
        mySecondArray[i] = i;
    }
    cout << "My second array using only numbers: " << mySecondArray;
}
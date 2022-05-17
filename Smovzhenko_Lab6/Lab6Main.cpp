#include <iostream>

#include "String.h"

using namespace std;


int main() {
	cout << "CONSTRUCTOR" << endl;

	String a;

	cout << endl << "C-STRING CONSTRUCTOR" << endl;
	String b("my C-string");

	cout << endl << "STL-STRING CONSTRUCTOR" << endl;

	string stl_string = "my STL-string";
	String c(stl_string);

	cout << endl << "COPY CONSTRUCTOR" << endl;
	String d(b);

	cout << endl << "MOVE CONSTRUCTOR" << endl;
	String f(move(b));


	cout << endl << endl << "ASSIGNMENT" << endl << endl;
	a = move(f);
	a = stl_string;
	a = "_a_value_";

	cout << endl << endl << "COMBINED ASSIGNMENT" << endl;
	a += c;
	cout << "a += c;" << endl;
	cout << "a: " << a << endl << endl;
	string stl_string2 = "my 2nd STL-string";
	a += stl_string2;
	cout << "a += stl_string2;" << endl;
	cout << "a: " << a << endl << endl;
	a += "_hello_";
	cout << "a += \"_hello_\";" << endl;
	cout << "a: " << a << endl;

	cout << endl << endl << "OPERATOR []" << endl;
	try {
		cout << "a[1]: " << a[1] << " (expected \"a\")" << endl;
		cout << "a[a.len() - 2]: " << a[a.len() - 2] << " (expected \"o\")" << endl;
		//cout << "a[-1]" << a[-1] << endl;
	}
	catch (const std::exception& e) { cerr << e.what() << endl; }


	cout << endl << endl << "OPERATOR ==" << endl;
	cout << "c == \"my STL-string\": " << boolalpha << (c == "my STL-string") << endl;
	cout << "c == stl_string2: " << boolalpha << (c == stl_string2) << endl;

	cout << endl << endl << "OPERATOR !=" << endl;
	cout << "c != a: " << boolalpha << (c != a) << endl;

	cout << endl << endl << "OPERATOR +" << endl << endl;
	cout << "***" << endl << "c + stl_string2: " << (c + stl_string2) << endl << "***" << endl;
	cout << endl;
	cout << "***" << endl << "c + \"my STL-string\": " << (c + "my STL-string") << endl << "***" << endl;
	cout << endl;
	cout << "***" << endl << "c + \"my STL-string\": " << (c + d) << endl << "***" << endl;

	cout << endl << "CLEANUP: " << endl;
	return 0;
}
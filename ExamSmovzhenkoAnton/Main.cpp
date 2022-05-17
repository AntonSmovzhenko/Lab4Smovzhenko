///////Smovzhenko Anton

#include "Trapezoid.h"
#include "Trapezoid.h"
#include "Deque.h"
#include "ListDeque.h"
#include "BoundedDequeArray.h"
#include "ListPeekDeque.h"
#include "QueuePriority.h"
#include "DequeUnboundedArray.h"

#include <iostream>

#include <cassert>

#include <cmath>

#define TOLERANCE 0.0000001
using namespace std;

int main()
{
	cout << "Test construtors" << endl;

	//constructors
	Trapezoid t1(0, 0, 0, 1, 2, 1, 4, 0);
	Trapezoid t2(t1);

	////////////////////////////////////

	cout << endl << "Test equality" << endl;

	double t2Area = t2.area();

	assert(t1 == t2);

	////////////////////////////////////

	cout << endl << "Test getters" << endl;

	assert(t1.getC() == t2.getC());
	assert(t1.getAD().Start() == t1.getA());

	////////////////////////////////////

	cout << endl << "Test area and perimeter" << endl;

	double t1Area = 3;
	double t1Perimeter = 7 + sqrt(5);

	assert(fabs(t1.area() - t1Area) < TOLERANCE);
	assert(fabs(t1.perimeter() - t1Perimeter) < TOLERANCE);

	////////////////////////////////////

	cout << endl << "Test setters" << endl;

	Point C(3, 1);

	t1.setC(C);

	assert(C == t1.getBC().End());
	assert(t1 != t2);

	////////////////////////////////////

	cout << endl << "Test invalid trapezoid" << endl;
	Point badC(5, 5);

	try {
		t1.setC(badC);
	}
	catch (Trapezoid::BadTrapezoid& error) {
		cout << " ERROR " << error.getReason() << endl;
	}

	try {
		Trapezoid bad(1, 5, 2, 2, 11, 6, 15, 1);
	}
	catch (Trapezoid::BadTrapezoid& error) {
		cout << " ERROR " << error.getReason() << endl;
	}

	////////////////////////////////////

	cout << endl << "Test list deque" << endl;
	ListDeque<string> listD;
	listD.putFront("middle");
	listD.putBack("last");
	listD.putFront("first");
	listD.popBack();

	try {
		listD.popFront();
	}
	catch (Deque<string>::BadDeque error) {
		error.diagnose();
	}

	////////////////////////////////////

	cout << endl << "Test bound deque array" << endl;
	BoundedDequeArray<string> boundedD(5);

	boundedD.putFront("center");
	boundedD.putBack("end");
	boundedD.putFront("start");
	boundedD.popBack();

	try {
		boundedD.popFront();
	}
	catch (Deque<string>::BadDeque error) {
		error.diagnose();
	}

	for (size_t i = 0; i < 5; i++)
	{
		boundedD.putBack("T E S T");
	}

	cout << endl << "Putting more elements than size of deque" << endl;

	try {
		boundedD.putBack("T E S T");
	}
	catch (Deque<string>::BadDeque error) {
		error.diagnose();
	}

	////////////////////////////////////

	cout << endl << "Test queue priority" << endl;
	QueuePriority<int> queueP;
	int* two = new int(2);
	int* eight = new int(8);
	int* twentyFive = new int(25);
	queueP.put(*(two));
	queueP.put(*(twentyFive));
	queueP.put(*(eight));
	delete twentyFive;
	delete eight;
	delete two;
	cout << "Pop from empty queue" << endl;
	try {
		queueP.pop();
	}
	catch (QueuePriority<int>::BadQueue error) {
		error.diagnose();
	}

	////////////////////////////////////

	cout << endl << "Test deque peek list" << endl;
	ListPeekDeque<string> listP;

	listP.putFront("2");
	listP.putFront("1");
	listP.putFront("0");
	assert(listP.peek(0) == "0");
	assert(listP.peek(1) == "1");
	assert(listP.peek(2) == "2");

	cout << endl << "Peek out of bounds" << endl;
	try {
		listP.peek(10);
	}
	catch (Deque<string>::BadDeque error) {
		error.diagnose();
	}

	////////////////////////////////////

	cout << endl << "Test unboarded array deque" << endl;
	DequeUnboundedArray<string> infiniteD;

	infiniteD.putFront("center");

	infiniteD.putFront("start");

	infiniteD.putBack("end");

	infiniteD.popBack();

	try {
		infiniteD.popFront();
	}
	catch (Deque<string>::BadDeque error) {
		error.diagnose();
	}

	cout << endl << "Put lots of items into unboarded deque array" << endl;
	for (size_t i = 0; i < 30; i++)
	{
		infiniteD.putFront("secondTesting");
	}

}


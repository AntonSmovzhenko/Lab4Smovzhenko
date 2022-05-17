//Anton Smovzhenko

#include <iostream>

#include "AComplex.h"
#include "TComplex.h"

#include <cassert>

using namespace std;

int main() {

	cout << " Constructoring " << endl;

	AComplex firstAComplex(3, 6);

	TComplex firstTComplex(5, 0.75);

	/////////////////////////////////////

	cout << endl << "Coping construction" << endl;

	AComplex secondAComplex(firstAComplex);

	TComplex secondTComplex(firstTComplex);

	/////////////////////////////////////

	cout << "	+ " << endl;
	cout << firstAComplex + secondAComplex << endl;

	/////////////////////////////////////

	cout << "	+ but mixed ";
	cout << endl << firstAComplex + firstTComplex << endl;

	/////////////////////////////////////

	cout << "	- ";
	cout << endl << firstAComplex - secondAComplex << endl;

	/////////////////////////////////////

	cout << "	- but mixed ";
	cout << endl << firstAComplex - firstTComplex << endl;

	/////////////////////////////////////

	cout << "	* ";
	cout << endl << firstTComplex * secondTComplex << endl;


	/////////////////////////////////////

	cout << "	* but mixed ";
	cout << endl  << firstAComplex * firstTComplex << endl;

	/////////////////////////////////////

	cout << "	/ ";
	cout << endl << firstTComplex / secondTComplex << endl;

	/////////////////////////////////////

	cout << "	/ but mixed ";
	cout << endl  << firstTComplex / firstAComplex << endl;

	/////////////////////////////////////

	cout << "	== " << endl;
	assert(firstAComplex == secondAComplex);
}
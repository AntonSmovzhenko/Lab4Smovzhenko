//Anton Smovzhenko

#include "TComplex.h"
#include "AComplex.h"

using namespace std;

void constructoringMessage(AComplex& AC) {
	cout << "Constructoring AComplex " << AC << endl;
}

AComplex::AComplex(const double real, const double imaginary) :
	_real(real),
	_imaginary(imaginary)
{
	constructoringMessage(*this);
}


AComplex::AComplex(const AComplex& AC) :
	_real(AC.real()),
	_imaginary(AC.imaginary())
{
	constructoringMessage(*this);
}


AComplex::operator TComplex() const {
	return TComplex(mod(), arg());
}


AComplex::~AComplex() {
	cout << "Destroying AComplex " << *this << endl;
}

AComplex& AComplex::operator=(const AComplex& AC) {
	if (this == &AC)
		return *this;
	_real = AC.real();
	_imaginary = AC.imaginary();
	return *this;
}


const AComplex operator+(const AComplex& AC1, const AComplex& AC2) {
	return { AC1.real() + AC2.real(), 
			AC1.imaginary() + AC2.imaginary() };
}

bool operator==(const AComplex& AC1, const AComplex& AC2) {
	return AC1.imaginary() == AC2.imaginary() &&
		AC1.real() == AC2.real();
}

const AComplex operator-(const AComplex& AC1, const AComplex& AC2) {
	return { AC1.real() - AC2.real(),
			AC1.imaginary() - AC2.imaginary() };
}

bool operator!=(const AComplex& AC1, const AComplex& AC2) {
	return !(AC1 == AC2);
}

//toString

ostream& operator<<(ostream& ostr, const AComplex& AC) {
	ostr << AC.real() << "+i*" << AC.imaginary();
	return ostr;
}
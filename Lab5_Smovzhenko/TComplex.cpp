//Anton Smovzhenko

#include "AComplex.h"
#include "TComplex.h"

using namespace std;

void contructoringMessage(TComplex& TC) {
	cout << "Constructoring TComplex " << TC << endl;
}

TComplex::TComplex(const double PO, const double FI) :
	_PO(PO),
	_FI(FI) {
	contructoringMessage(*this);
}


TComplex::TComplex(const TComplex& TC) :
	_PO(TC.PO()),
	_FI(TC.FI()) {
	contructoringMessage(*this);
}


TComplex::operator AComplex() const {
	return AComplex(real(), imaginary());
}


TComplex::~TComplex() {
	cout << "Destroying TComplex " << *this << endl;
}


TComplex& TComplex::operator=(const TComplex& TC) {
	if (this == &TC) {
		return *this;
	}

	_PO = TC.PO();

	_FI = TC.FI();

	return *this;
}

const TComplex operator/(const TComplex& TC1, const TComplex& TC2) {
	return { TC1.PO() / TC2.PO(),
			TC1.FI() - TC2.FI() };
}

const TComplex operator*(const TComplex& TC1, const TComplex& TC2) {
	return { TC1.PO() * TC2.PO(),
			TC1.FI() + TC2.FI() };
}


//toString

ostream& operator<<(ostream& ostr, const TComplex& TC) {
	ostr << endl << "PO: " << TC.PO() <<endl;
	ostr << "FI: " << TC.FI();
	return ostr;
}
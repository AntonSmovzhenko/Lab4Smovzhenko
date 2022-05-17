//Anton Smovzhenko

#pragma once

#include	<iostream>

using namespace std;

class AComplex;

class TComplex {

private:

	double _FI;

	double _PO;


public:
	TComplex(const double PO, const double FI);

	TComplex(const TComplex&);

	~TComplex();

	operator AComplex() const;

	TComplex& operator=(const TComplex&);

	inline double& PO() { return _PO; }

	inline double& FI() { return _FI; }

	inline double real() const { return _PO * cos(_FI); }

	inline double imaginary() const { return _PO * sin(_FI); }

	inline const double& PO() const { return _PO; }

	inline const double& FI() const { return _FI; }


};

const TComplex operator*(const TComplex&, const TComplex&);

const TComplex operator/(const TComplex&, const TComplex&);

ostream& operator<<(ostream&, const TComplex&);
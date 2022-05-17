//Anton Smovzhenko

#pragma once

#include <iostream>

using namespace std;

class TComplex;

class AComplex {

private:

	double _imaginary;

	double _real;


public:

	AComplex(const double real = 0, const double imaginary = 0);

	AComplex(const AComplex&);

	~AComplex();

	operator TComplex() const;

	AComplex& operator=(const AComplex&);



	inline double& imaginary() { return _imaginary; }

	inline double& real() { return _real; }

	inline double mod() const { return sqrt(_real * _real + _imaginary * _imaginary); }

	inline double arg() const { return atan2(_imaginary, _real); }

	inline const double& real() const { return _real; }

	inline const double& imaginary() const { return _imaginary; }

	inline const AComplex conj() const { return AComplex(_real, -_imaginary); }
};

bool operator==(const AComplex&, const AComplex&);

bool operator!=(const AComplex&, const AComplex&);

const AComplex operator+(const AComplex&, const AComplex&);

const AComplex operator-(const AComplex&, const AComplex&);


ostream& operator<<(ostream&, const AComplex&);
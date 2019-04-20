// ----------------------------------poly.h-----------------------------------
// Lei CSS343 section A
// January 10, 2019
// January 11, 2019
// -----------------------------------------------------------------------------
// to create the abstract data type for a polynomial called Poly. Implement the
// internal representation of a polynomial (nonnegative exponents) as an array of
// terms
// -----------------------------------------------------------------------------
// specifications and assumptions:
// - polynomial of nonnegative exponents
// - power exponent is the index of the array
// - contents of the array is coefficient
// - assum input is always an integer
// -----------------------------------------------------------------------------

#ifndef poly_h
#define poly_h
#include <iostream>
using namespace std;

class Poly{
    friend ostream& operator << (ostream& output, const Poly&);   // operator << (output)
    friend istream& operator >> (istream& input, Poly&);          // operator >> (input)

public:
    Poly(const int = 0, const int = 0);    // default constructor
    Poly(const Poly &);                    // copy constructor
    ~Poly();                               // destructor

    int getCoeff(const int) const;         // get one term's coefficient
    void setCoeff(const int, const int);   // set one coefficient

    // arithmetic operators
    Poly operator+(const Poly &) const;
    Poly operator-(const Poly &) const;
    Poly operator*(const Poly &) const;

    // equality and inequality operators
    bool operator==(const Poly &) const;
    bool operator!=(const Poly &) const;

    // assignment operators
    Poly& operator=(const Poly &);
    Poly& operator+=(const Poly &);
    Poly& operator-=(const Poly &);
    Poly& operator*=(const Poly &);

private:
    int* coeffPtr;             // pointing to the first element of a array
    int size;                  // array size
};
#endif /* poly_h */

// ----------------------------------poly.cpp------------------------------------------
// Lei CSS343 section A
// January 10, 2019
// January 14, 2019
// ------------------------------------------------------------------------------------
// to create the abstract data type for a polynomial called Poly. Implement the
// internal representation of a polynomial (nonnegative exponents) as an array of
// terms
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// - polynomial of nonnegative exponents
// - power exponent is the index of the array
// - contents of the array is coefficient
// - assum input is always an integer
// ------------------------------------------------------------------------------------

#include <iostream>
#include "poly.h"
using namespace std;

// ------------------------------------------------------------------------------------
// default constructor
// initialize polynomial with largest power exponent and coefficient
// if power is negative, creating an array without coefficient
// ------------------------------------------------------------------------------------
Poly::Poly(const int coeff, const int exponent)
{
    if(exponent >= 0) {
        size = exponent + 1;
        coeffPtr = new int [size];
        for(int i = 0; i < size; i++) {    // initialize an array
            coeffPtr[i] = 0;
        }
        coeffPtr[exponent] = coeff;
    } else {  // the exponent is negative, create an array then set its size to be zero;
        coeffPtr = new int[1];
        coeffPtr[0] = 0;
        size = 1;
    }
}   // end of default constructor

// -------------------------------------------------------------------------------------
// copy constructor
// create a copy of another polynomial
// -------------------------------------------------------------------------------------
Poly::Poly(const Poly &other)
{
    coeffPtr = new int[other.size];
    for(int i = 0; i < other.size; i++) {
        coeffPtr[i] = other.coeffPtr[i];
    }
    size = other.size;
}   // end of copy constructor

// -------------------------------------------------------------------------------------
// destructor
// deallocate all memory
// -------------------------------------------------------------------------------------
Poly::~Poly()
{
    delete [] coeffPtr;
    coeffPtr = NULL;
    size = 0;
}   // end of destructor

// -------------------------------------------------------------------------------------
// getter
// get one term's coefficient and return it
// -------------------------------------------------------------------------------------
int Poly::getCoeff(const int exponent) const
{
    if(coeffPtr == NULL || exponent < 0 || exponent >= size) {
        return 0;
    } else {
        return coeffPtr[exponent];
    }
}   // end of getCoeff

// -------------------------------------------------------------------------------------
// setter
// set one coefficient at the power expononent
// -------------------------------------------------------------------------------------
void Poly::setCoeff(const int coeff, const int exponent)
{
    if (size <= exponent) {
        int newSize = exponent + 1;
        int* tempArray = new int[newSize];
        // copy the first array contents
        for(int i = 0; i < size; i++) {
            tempArray[i] = coeffPtr[i];
        }
        // initialize the rest of the array to be 0
        for(int i = size; i < newSize; i++) {
            tempArray[i] = 0;
        }
        // change array pointer to point to tempArray
        delete [] coeffPtr;
        coeffPtr = tempArray;
        tempArray = NULL;
        size = newSize;
    }
    coeffPtr[exponent] = coeff;      // set coefficient at "exponent" index
}   // end of setCoeff

// -------------------------------------------------------------------------------------
// operator +
// add two polynomials then return its sum
// -------------------------------------------------------------------------------------
Poly Poly::operator+(const Poly& other) const
{
    int maxSize = (size < other.size ? other.size : size);
    Poly sum(0, maxSize - 1);
    for(int i = 0; i < maxSize; i++) {
        if (i < size && i < other.size) {    // both polynomial array size are equal
            sum.coeffPtr[i] = coeffPtr[i] + other.coeffPtr[i];
        } else if (i < size) {              //  this polynomial array size is bigger
            sum.coeffPtr[i] = coeffPtr[i];
        } else {                            // other polynomial array size is bigger
            sum.coeffPtr[i] = other.coeffPtr[i];
        }
    }
    return sum;
}   // end of operator +

// -------------------------------------------------------------------------------------
// operator -
// subtract two polynomials then return its difference
// -------------------------------------------------------------------------------------
Poly Poly::operator-(const Poly& other) const
{
    int maxSize = (size < other.size ? other.size : size);
    Poly diff(0, maxSize - 1);
    for(int i = 0; i < maxSize; i++) {
        if (i < size && i < other.size) {
            diff.coeffPtr[i] = coeffPtr[i] - other.coeffPtr[i];
        } else if (i < size) {
            diff.coeffPtr[i] = coeffPtr[i];
        } else {
            diff.coeffPtr[i] = 0 - other.coeffPtr[i];
        }
    }
    return diff;
}   // end of operator -

// --------------------------------------------------------------------------------------
// operator *
// multiply two polynomials then return its result
// --------------------------------------------------------------------------------------
Poly Poly::operator*(const Poly& other) const
{
    int maxSize = size + other.size;
    Poly multiply(0, maxSize - 2);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < other.size; j++) {
            multiply.coeffPtr[i + j] += coeffPtr[i] * other.coeffPtr[j];
        }
    }
    return multiply;
}   // end of operator *

// --------------------------------------------------------------------------------------
// operator==
// check if two polynomials are equal
// return true if they are equal, false if they are not
// --------------------------------------------------------------------------------------
bool Poly::operator==(const Poly& other) const
{
    if(size != other.size) {
        return false;
    }
    for(int i = 0; i < size; i++) {
        if(coeffPtr[i] != other.coeffPtr[i]) {
            return false;
        }
    }
    return true;
}   // end of operator ==

// --------------------------------------------------------------------------------------
// operator!=
// check if two polynomials are not equal
// return true if they are not equal, flase if they are equal
// --------------------------------------------------------------------------------------
bool Poly::operator!=(const Poly& other) const
{
    return !(*this == other);
}   // end of operator !=

// --------------------------------------------------------------------------------------
// operator +=
// adding another polynomial to this one
// --------------------------------------------------------------------------------------
Poly& Poly::operator+=(const Poly& other)
{
    int maxSize = (size < other.size ? other.size : size);
    int* tempArray = new int[maxSize];
    for(int i = 0; i < maxSize; i++) {
        if(i < size && i < other.size) {
            tempArray[i] = coeffPtr[i] + other.coeffPtr[i];
        } else if (i < size) {
            tempArray[i] = coeffPtr[i];
        } else {
            tempArray[i] = other.coeffPtr[i];
        }
    }
    delete [] coeffPtr;
    size = maxSize;
    coeffPtr = tempArray;
    tempArray = NULL;
    return *this;
}   // end of operator +=

// --------------------------------------------------------------------------------------
// operator -=
// subtracting another polynomial from this one
// --------------------------------------------------------------------------------------
Poly& Poly::operator-=(const Poly& other)
{
    int maxSize = (size < other.size ? other.size : size);
    int* tempArray = new int[maxSize];
    for(int i = 0; i < maxSize; i++) {
        if(i < size && i < other.size) {
            tempArray[i] = coeffPtr[i] - other.coeffPtr[i];
        } else if (i < size) {
            tempArray[i] = coeffPtr[i];
        } else {
            tempArray[i] = 0 - other.coeffPtr[i];
        }
    }
    delete [] coeffPtr;
    size = maxSize;
    coeffPtr = tempArray;
    tempArray = NULL;
    return *this;
}   // end of operator -=

// --------------------------------------------------------------------------------------
// operator*=
// multiplying another polynomial with this one
// --------------------------------------------------------------------------------------
Poly& Poly::operator*=(const Poly& other)
{
    int maxSize = size + other.size;
    int* tempArray = new int[maxSize];
    int coeff = 0;
    for(int i = 0; i < maxSize; i++) {
        tempArray[i] = 0;
    }
    for(int i = 0; i < size; i++) {
        if(coeffPtr[i] != 0) {
            for(int j = 0; j < other.size; j++) {
                if(other.coeffPtr[j] != 0) {
                    coeff = coeffPtr[i] * other.coeffPtr[j];
                    tempArray[i + j] += coeff;
                }
            }
        }
    }
    delete [] coeffPtr;
    size = maxSize;
    coeffPtr = tempArray;
    tempArray = NULL;
    return *this;
}   // end of operator *=

// -------------------------------------------------------------------------------------
// operator=
// assign other polynomial to this polynomial
// -------------------------------------------------------------------------------------
Poly& Poly::operator=(const Poly& other)
{
    if(&other != this) {         // check if two addresses are the same
        if(size < other.size) {
            delete [] coeffPtr;
            size = other.size;
            coeffPtr = new int [size];
        } else {
            for(int i = other.size; i < size; i++) {
                coeffPtr[i] = 0;
            }
        }
        for(int i = 0; i < other.size; i++) {
            coeffPtr[i] = other.coeffPtr[i];
        }
    }
    return *this;
}   // end of operator =

// -------------------------------------------------------------------------------------
// operator>>
// maximum size of a array is the largest exponent + 1, non-negative exponent
// terminate the program if input is -1 -1
// -------------------------------------------------------------------------------------
istream& operator>>(istream &input, Poly& other)
{
    int coeff;
    int exponent;
    input >> coeff >> exponent;
    while(coeff != -1 && exponent != -1) {
        if(exponent >= 0) {
            other.setCoeff(coeff, exponent);
        }
        input >> coeff >> exponent;
    }
    return input;
}   // end of operator >>

// -------------------------------------------------------------------------------------
// operator<<
// output the values for array with coefficients, except if all term is zero
// then print out " 0".
// use lowercase x, a nonzero coefficient and its sign are always displayed.
// -------------------------------------------------------------------------------------
ostream& operator<<(ostream &output, const Poly& other)
{
    bool coeffAllZero = true;
    for(int i = other.size - 1; i >= 0; i--) {
        int coeff = other.coeffPtr[i];
        if(coeff != 0) {
            coeffAllZero = false;
            output << " ";
            if(coeff > 0) {
                output << "+";
            }
            output << coeff;
            if(i > 0) {
                output << "x";
            }
            if (i > 1) {
                output << "^" << i;
            }
        }
    }
    if(coeffAllZero) {
        output << " 0";
    }
    return output;
}   // end of operator <<

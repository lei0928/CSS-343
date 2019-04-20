// ----------------------------------comedy.h---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// sub class of movie
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// inherits methods from the movie object
// contains overriden display method
// ------------------------------------------------------------------------------------
#ifndef comedy_h
#define comedy_h
#include "movie.h"
using namespace std;

class Comedy : public Movie
{
public:

    Comedy(char genre, char mediaType, string title, string director,
           int stock, int yearRelease);         // constructor
    ~Comedy();                                  // destructor
    
    // Overloaded operators
    virtual bool operator==(const Movie& otherMovie) const;   // check if movies are equal
    virtual bool operator != (const Movie& otherMovie) const; // check if movies are not equal
    virtual bool operator > (const Movie& otherMovie) const;  // check if this movie is greater than other movie
    virtual bool operator < (const Movie& otherMovie) const;  // check if this movie is less than other movie
};
#endif

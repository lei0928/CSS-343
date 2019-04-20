// ----------------------------------drama.h---------------------------------------
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
#ifndef drama_h
#define drama_h

#include "movie.h"
using namespace std;

class Drama : public Movie
{
public:
    
    Drama(char genre, char mediaType, string title, string director,
          int stock, int yearRelease);      // constructor
    ~Drama();                               // destructor
    
    // Overloaded operators
    virtual bool operator==(const Movie& otherMovie) const;   // check if movies are equal
    virtual bool operator != (const Movie& otherMovie) const; // check if movies are not equal
    virtual bool operator > (const Movie& otherMovie) const;  // check if this movie is greater than rhs movie
    virtual bool operator < (const Movie& otherMovie) const;  // check if this movie is less than rhs movie
};
#endif

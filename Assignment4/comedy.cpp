// ----------------------------------comedy.cpp---------------------------------------
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
#include "comedy.h"
#include <stdio.h>

// --------------------------------------------------------------------------------------
// input constructor
// --------------------------------------------------------------------------------------
Comedy::Comedy(char genre, char mediaType, string title,
               string director, int stock, int yearReleased)
: Movie(genre, mediaType, title, director, stock, yearReleased)
{
    
}

// --------------------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------------------
Comedy::~Comedy()
{
    
}

// --------------------------------------------------------------------------------------
// equivalence operator
// returns true if both movies have the same title and year released
// --------------------------------------------------------------------------------------
bool Comedy::operator == (const Movie& otherMovie) const// check if movies are equal
{
    if (title == otherMovie.getTitle() && yearReleased == otherMovie.getYearReleased())
        return true;
    else
        return false;
}

// --------------------------------------------------------------------------------------
// not equals operator
// returns true if both movie have different title or year released
// --------------------------------------------------------------------------------------
bool Comedy::operator != (const Movie& otherMovie) const // check if movies are not equal
{
    return !(*this == otherMovie);
}

// --------------------------------------------------------------------------------------
// greater than operator
// check if this movie is greater than other movie by title and then year released
// --------------------------------------------------------------------------------------
bool Comedy::operator > (const Movie& otherMovie) const
{
    if (title > otherMovie.getTitle())
        return true;
    else if (title == otherMovie.getTitle() && yearReleased > otherMovie.getYearReleased())
        return true;
    else
        return false;
}

// --------------------------------------------------------------------------------------
// less than operator
// check if this movie is less than other movie by title and then year released
// --------------------------------------------------------------------------------------
bool Comedy::operator < (const Movie& otherMovie) const
{
    if (title < otherMovie.getTitle())
        return true;
    else if (title == otherMovie.getTitle() && yearReleased < otherMovie.getYearReleased())
        return true;
    else
        return false;
}

// ----------------------------------drama.cpp---------------------------------------
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
#include "drama.h"

// --------------------------------------------------------------------------------------
// input consturctor
// --------------------------------------------------------------------------------------
Drama::Drama(char genre, char mediaType, string title,
             string director, int stock, int yearReleased)
: Movie(genre, mediaType, title, director, stock, yearReleased)
{
    
}

// --------------------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------------------
Drama::~Drama()
{
    
}

// --------------------------------------------------------------------------------------
// rquivalence operator
// returns true if both movies directors and titles are the same
// --------------------------------------------------------------------------------------
bool Drama::operator == (const Movie& otherMovie) const
{
    if (director == otherMovie.getDirector() && title == otherMovie.getTitle())
        return true;
    else
        return false;
}

// --------------------------------------------------------------------------------------
// not equal operator
// returns true if both movies have different directors or titles
// --------------------------------------------------------------------------------------
bool Drama::operator != (const Movie& otherMovie) const
{
    return !(*this == otherMovie);
}

// --------------------------------------------------------------------------------------
// greater than operator
// check if this movie is greater than other movie by director and then title
// --------------------------------------------------------------------------------------
bool Drama::operator > (const Movie& otherMovie) const
{
    if (director > otherMovie.getDirector())
        return true;
    else if (director == otherMovie.getDirector() && title > otherMovie.getTitle())
        return true;
    else
        return false;
}

// --------------------------------------------------------------------------------------
// less than operator
// check if this movie is less than other movie by director and then title
// --------------------------------------------------------------------------------------
bool Drama::operator < (const Movie& otherMovie) const
{
    if (director < otherMovie.getDirector())
        return true;
    else if (director == otherMovie.getDirector() && title < otherMovie.getTitle())
        return true;
    else
        return false;
}

// ----------------------------------movie.pp---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// super class of movie
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// it tracks the current amount of in stock movies for each movie, the media type,
// director, year released, title, and movie code
// it has functions to add and remove from the movie stock compare movies
// ------------------------------------------------------------------------------------
#include "movie.h"
#include <stdio.h>

// --------------------------------------------------------------------------------------
// default constructor
// --------------------------------------------------------------------------------------
Movie::Movie()
{
    
}

// --------------------------------------------------------------------------------------
// input constructor
// --------------------------------------------------------------------------------------
Movie::Movie(char genre, char mediaType, string title, string director, int stock, int yearReleased)
{
    this->genre = genre;
    this->mediaType = mediaType;
    this->title = title;
    this->director = director;
    this->stock = stock;
    this->yearReleased = yearReleased;
    
    this->counted = false;
}

// --------------------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------------------
Movie::~Movie()
{
    
}

// --------------------------------------------------------------------------------------
// displays the movie's information on one line
// --------------------------------------------------------------------------------------
void Movie::display() const
{
    cout << setw(7) << getGenre() << setw(7) << getMediaType() << setw(35) << getTitle()
    << setw(20) << getDirector() << setw(7)<< getYearReleased() << setw(7) <<getStock() << endl;
}

// --------------------------------------------------------------------------------------
// returns a string of "Title by Director"
// --------------------------------------------------------------------------------------
string Movie::getMovieInfo() const
{
    string s;
    s = title + " by " + director;
    return s;
}

// --------------------------------------------------------------------------------------
// returns the genre of the movie
// --------------------------------------------------------------------------------------
char Movie::getGenre() const
{
    return genre;
}

// --------------------------------------------------------------------------------------
// returns the media type of the movie
// --------------------------------------------------------------------------------------
char Movie::getMediaType() const
{
    return mediaType;
}

// --------------------------------------------------------------------------------------
// returns the title
// --------------------------------------------------------------------------------------
string Movie::getTitle() const
{
    return title;
}

// --------------------------------------------------------------------------------------
// returns the director
// --------------------------------------------------------------------------------------
string Movie::getDirector() const
{
    return director;
}

// --------------------------------------------------------------------------------------
// returns the stock as an int
// --------------------------------------------------------------------------------------
int Movie::getStock() const
{
    return stock;
}

// --------------------------------------------------------------------------------------
// returns the year released as an int
// --------------------------------------------------------------------------------------
int Movie::getYearReleased() const
{
    return yearReleased;
}

// --------------------------------------------------------------------------------------
// returns true if the passed in value was added to the stock
// --------------------------------------------------------------------------------------
bool Movie::addToStock(int add)
{
    stock += add;
    return true;
}

// --------------------------------------------------------------------------------------
// only used by Classics
// --------------------------------------------------------------------------------------
int Movie::getMonth() const
{
    return 0;
}

// --------------------------------------------------------------------------------------
// returns an empty string
// only used by Classics
// --------------------------------------------------------------------------------------
string Movie::getActor() const
{
    return "";
}

// --------------------------------------------------------------------------------------
// returns true if movie has already been counted
// --------------------------------------------------------------------------------------
bool Movie::getCountedStatus() const
{
    return counted;
}

// --------------------------------------------------------------------------------------
// sets the movie's counted variable to true
// --------------------------------------------------------------------------------------
void Movie::setCounted(bool checked)
{
    counted = checked;
}

// --------------------------------------------------------------------------------------
// returns true if the passed in value was subtracted from the movie's stock
// --------------------------------------------------------------------------------------
bool Movie::subtractFromStock(int count)
{
    if (stock >= count && stock > 0)
    {
        stock-= count;
        return true;
    }
    else
        return false;
}

// --------------------------------------------------------------------------------------
// only for use by Classics
// --------------------------------------------------------------------------------------
void Movie::addSameMovies(Movie*& sameMovie)
{
    
}

// --------------------------------------------------------------------------------------
// equivalence operator
// default compare by title and year
// --------------------------------------------------------------------------------------
bool Movie::operator == (const Movie& otherMovie) const
{
    if (this -> title == otherMovie.title && this -> yearReleased == otherMovie.getYearReleased())
        return true;
    else
        return false;
}

// --------------------------------------------------------------------------------------
// not equals operator
// default compare
// returns true if the title or year are different
// --------------------------------------------------------------------------------------
bool Movie::operator != (const Movie& otherMovie) const
{
    return !(*this == otherMovie);
}

// --------------------------------------------------------------------------------------
// greater than operator
// default sort by year only
// --------------------------------------------------------------------------------------
bool Movie::operator > (const Movie& otherMovie) const
{
    return this->yearReleased > otherMovie.yearReleased;
}

// --------------------------------------------------------------------------------------
// less than operator
// default sort by year only
// --------------------------------------------------------------------------------------
bool Movie::operator < (const Movie& otherMovie) const
{
    return this->yearReleased < otherMovie.yearReleased;
}

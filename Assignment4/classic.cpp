// ----------------------------------classic.cpp---------------------------------------
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
#include "classic.h"
#include <string>

// --------------------------------------------------------------------------------------
// constructor
// sets the monthReleased and actor based on passed in values
// uses Movie constructor for most values.
// --------------------------------------------------------------------------------------
Classic::Classic(char genre, char mediaType, string title, string director,
                 int stock, int yearReleased, int monthReleased, string actor)
: Movie(genre, mediaType, title, director, stock, yearReleased)
{
    this -> actor = actor;
    this->monthReleased = monthReleased;
}

// --------------------------------------------------------------------------------------
// destructor
// no dynamic memory is allocated
// nothing to delete
// --------------------------------------------------------------------------------------
Classic::~Classic()
{
    
}

// --------------------------------------------------------------------------------------
// displays movie information with all actors listed
// only one movie is displayed, even if that movie has multiple actors
// --------------------------------------------------------------------------------------
void Classic::display() const
{
    // Print movie info and total stock
    cout << setw(7) << getGenre() << setw(7) << getMediaType() << setw(35) << getTitle() << setw(20)
    << getDirector() << setw(7) << getMonth() << setw(7)<< getYearReleased() << setw(7)  << getTotalStock() << endl;
    
    // print actor and stock for this movie
    cout << setw(73) << this -> getActor() << " -------------" << setw(3) << this -> getStock() << endl;
    
    // print actor and stock for all other movies with same title
    for (int i = 0; i < sameMoviesList.size(); i++)
    {
        cout << setw(73) << sameMoviesList[i] -> getActor()
        << " -------------" << setw(3) << sameMoviesList[i] -> getStock() << endl;
    }
}

// --------------------------------------------------------------------------------------
// returns the monthReleased
// --------------------------------------------------------------------------------------
int Classic::getMonth() const
{
    return monthReleased;
}

// --------------------------------------------------------------------------------------
// returns the major actor
// --------------------------------------------------------------------------------------
string Classic::getActor() const
{
    return actor;
}

// --------------------------------------------------------------------------------------
// returns number of stock of this movie from all actors
// --------------------------------------------------------------------------------------
int Classic::getTotalStock() const
{
    int totalStock = getStock();
    for (int i = 0; i < sameMoviesList.size(); i++)
    {
        if(!sameMoviesList[i] -> getCountedStatus()) // if the movie was not already counted for inventory
        {
            totalStock += sameMoviesList[i] -> getStock();
            sameMoviesList[i] -> setCounted(true);
        }
    }
    return totalStock;
}

// --------------------------------------------------------------------------------------
// returns true if subtracking from the movies stock was successful
// if one actor doesn't have enough stock, the method searches for stock from
// the other actors
bool Classic::subtractFromStock(int count)
{
    if (stock >= count && stock > 0)
    {
        stock-= count;
        return true;
    }
    else if (sameMoviesList.size() > 0) // check same movies stock and borrow
    {
        setCounted(true);
        for(int i = 0; i < sameMoviesList.size(); i++)
        {
            if (!sameMoviesList[i] -> getCountedStatus() && sameMoviesList[i] -> subtractFromStock(count))
                return true;
            
            // mark the movie as counted
            sameMoviesList[i] -> setCounted(true);
        }
        return false;
        
    }
    else //this and all the same movies did not have enough stock
        return false;
}

// --------------------------------------------------------------------------------------
// adds movies with the same title but different actors to each
// movie nodes' vector called sameMovieList
void Classic::addSameMovies(Movie*& sameMovie)
{
    sameMoviesList.push_back(sameMovie); // add to this list
}

// --------------------------------------------------------------------------------------
// equivalence operator
// compares if the monthReleased is the same for both movies with different actors, but
// the same monthReleased are considered to be equivalent
// --------------------------------------------------------------------------------------
bool Classic::operator == (const Movie& otherMovie) const
{
    if (monthReleased == otherMovie.getMonth() &&
        yearReleased == otherMovie.getYearReleased() && getActor() == otherMovie.getActor())
        return true;
    else
        return false;
}

// --------------------------------------------------------------------------------------
// not equivalent operator
// returns the negation of the equivalence operator
// --------------------------------------------------------------------------------------
bool Classic::operator != (const Movie& otherMovie) const
{
    return !(*this == otherMovie);
}

// --------------------------------------------------------------------------------------
// greater than operator
// returns true if this movie was released after the right hand side movie
// --------------------------------------------------------------------------------------
bool Classic::operator > (const Movie& otherMovie) const
{
    
    if (yearReleased > otherMovie.getYearReleased())
        return true;
    else if (yearReleased == otherMovie.getYearReleased())
    {
        if (monthReleased > otherMovie.getMonth())
            return true;
        else if (monthReleased == otherMovie.getMonth() && actor > otherMovie.getActor())
            return true;
    }
    return false;
}

// --------------------------------------------------------------------------------------
// less than operator
// returns true if this movie was released before the right hand side movie
// --------------------------------------------------------------------------------------
bool Classic::operator < (const Movie& otherMovie) const
{
    if (yearReleased < otherMovie.getYearReleased())
        return true;
    else if (yearReleased == otherMovie.getYearReleased())
    {
        if (monthReleased < otherMovie.getMonth())
            return true;
        else if (monthReleased == otherMovie.getMonth() && actor < otherMovie.getActor())
            return true;
    }
    return false;
}

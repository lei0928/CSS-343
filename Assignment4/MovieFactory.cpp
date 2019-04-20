// ----------------------------------MovieFactory.cpp---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// factory creates different genre of movies
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// create function holds a switch to instantiate the corrent genre of movie
// ------------------------------------------------------------------------------------
#include "MovieFactory.h"

// --------------------------------------------------------------------------------------
// default constructor
// --------------------------------------------------------------------------------------
MovieFactory::MovieFactory()
{
    
}

// --------------------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------------------
MovieFactory::~MovieFactory()
{
    
}

// --------------------------------------------------------------------------------------
// creates a movie object based on the genre passed in
// assume all movies are DVDs
// --------------------------------------------------------------------------------------
Movie* MovieFactory::create(char genre, string title, string director, string actor, int month, int year, int stock)
{
    Movie* newMovie = NULL;
    switch(genre)
    {
        case 'F':
            newMovie = new Comedy (genre, 'D', title, director, stock, year);
            return newMovie;
            break;
            
        case 'D':
            newMovie = new Drama (genre, 'D', title, director, stock, year);
            return newMovie;
            break;
            
        case 'C':
            newMovie = new Classic (genre, 'D', title, director, stock, year, month, actor);
            return newMovie;
            break;
            
        default:
            cerr << "ERROR: " << genre << " Genre Not Found. Try Again." << endl;
            return newMovie;
            break;
    }
}

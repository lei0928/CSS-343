// ----------------------------------MovieFactory.h---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// factory creates different genre of movies
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// create function holds a switch to instantiate the corrent genre of movie
// ------------------------------------------------------------------------------------
#ifndef MovieFactory_h
#define MovieFactory_h
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
using namespace std;

class MovieFactory
{
public:
    
    MovieFactory();           // constructor
    ~MovieFactory();          // destructor
    
    // create movie
    Movie* create(char genre, string title, string director, string actor, int month, int year, int stock);
};
#endif

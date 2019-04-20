// ----------------------------------classic.h---------------------------------------
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
#ifndef classic_h
#define classic_h
#include <vector>
#include "movie.h"
using namespace std;

struct actorNode
{
    string actor; // major actor of the movie
    int stock;
    actorNode* next;
};

class Classic : public Movie
{
public:
    
    Classic(char genre, char mediaType, string title, string director, int stock, int yearRelease, int monthReleased, string actor);               // constructor
    ~Classic();                                     // destructor
    
    // Overloaded operators
    virtual bool operator == (const Movie&) const;  // check if movies are equal
    virtual bool operator != (const Movie&) const;  // check if movies are not equal
    virtual bool operator > (const Movie&) const;   // check if this movie is greater than rhs movie
    virtual bool operator < (const Movie&) const;   // check if this movie is less than rhs movie
    
    // Accessors
    virtual int getMonth() const;
    virtual void display() const;                   // print out movie data and return string
    virtual string getActor() const;                // get the major actor for the movie
    int getTotalStock() const;                      // get total stock of all the same movies
    
    // Mutators
    virtual bool subtractFromStock(int);            // subtract from stock
    virtual void addSameMovies(Movie*&);            // add the same movie to the list of same movies
    
private:
    vector<Movie*> sameMoviesList;
    string actor;
    int monthReleased;                              // month of the movie release
};

#endif

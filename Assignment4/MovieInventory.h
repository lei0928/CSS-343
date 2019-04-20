// ----------------------------------MovieInventory.h---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// holds inventory of the movies
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// this class keeps track of all the movies the store owns in an array of binary search
// trees
// ------------------------------------------------------------------------------------
#ifndef MovieInventory_h
#define MovieInventory_h
#include <vector>
#include "movie.h"
#include "BST.h"

class MovieInventory
{
    
public:
    MovieInventory();               // constructor
    ~MovieInventory();              // destructor
    
    Movie* getMovie (Movie*);                   // retrieves movie equal to the parameter movie
    bool movieExist (Movie*);                   // checks if movie exists
    void printInventory();                      // print all the movies in the stock
    
    Movie* getMovieByTitle(int, string, int);   // get movie by title and year
    
    bool addMovie (Movie*&);                    // add new movie
    bool borrowMovie (Movie*, string&);         // borrow a movie, and updates string with movie info
    bool returnMovie (Movie*, string&);         // return a movie, and updates string with movie info
    
    void addAllSameMovies(Movie*, int);
    
private:
    vector<BST> movieType; // array of BSTs there are 3 for each genre of movies
    // idx 0 for comedy, 1 for drama, 2 for classic
};
#endif

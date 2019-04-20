// ----------------------------------movie.h---------------------------------------
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
#ifndef movie_h
#define movie_h

#include <iostream>
#include <iomanip> 
using namespace std;

class Movie
{
public:

    Movie();                                        // constructor
    Movie(char, char, string, string, int, int);    // genre, mediatype, title, director, stock, year released
    virtual ~Movie();                               // destructor
    
    // Overloaded operators
    virtual bool operator==(const Movie& otherMovie) const;    // check if movies are equal
    virtual bool operator != (const Movie& otherMovie) const;  // check if movies are not equal
    virtual bool operator > (const Movie& otherMovie) const;   // check if this movie is greater than other movie
    virtual bool operator < (const Movie& otherMovie) const;   // check if this movie is less than other movie
    
    // Accessors
    char getGenre() const;
    char getMediaType() const;
    string getTitle() const;
    string getDirector() const;
    int getStock() const;
    int getYearReleased() const;
    bool getCountedStatus() const;
    virtual string getActor() const;
    virtual int getMonth() const;
    
    virtual void display() const;                      // print out movie data and return string
    string getMovieInfo() const;                       //returns string of movie data variables
    
    // Mutators
    bool addToStock(int);                              // add to stock
    virtual bool subtractFromStock(int);               // subtract from stock
    void setCounted(bool);                             // mark movie as counted in inventory
    virtual void addSameMovies(Movie*&);               // add the same movie to the list of same movies
    
protected:
    char genre;                                        // genre of the movie
    char mediaType;                                    // media type of the movie
    string title;                                      // title of movie
    string director;                                   // director of movie
    int stock;                                         // number of movie left in stock
    int yearReleased;                                  // year released
    bool counted;                                      // keeps track of inventory status of the movie
};
#endif

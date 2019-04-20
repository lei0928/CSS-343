// ----------------------------------borrow.h---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// borrow transaction
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// sub class of transaction
// subtracts 1 stock from the Movie in MovieInventory
// ------------------------------------------------------------------------------------
#ifndef borrow_h
#define borrow_h
#include "transaction.h"
#include "movie.h"
#include "MovieInventory.h"
#include "CustomerInventory.h"

using namespace std;

class Borrow: public Transaction
{
public:
    Borrow(int, Movie*);
    virtual ~Borrow();
    virtual bool perform(MovieInventory&, CustomerInventory&);   // perform borrow movie
    
private:
    Movie* movie;                   // movie to borrow
    int customerID;                 // customer responsible for the transaction
};
#endif

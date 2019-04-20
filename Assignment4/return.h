// ----------------------------------return.h---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// return transaction
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// sub class of transaction
// adds 1 stock from the Movie in MovieInventory
// ------------------------------------------------------------------------------------
#ifndef return_h
#define return_h
#include "transaction.h"
#include "movie.h"
#include "MovieInventory.h"
#include "CustomerInventory.h"
using namespace std;

class Return: public Transaction
{
public:
    Return(int, Movie*);     // constructor
    virtual ~Return();       // destructor
    int getCustomerID();     // get ID of the customer of the transaction
    virtual bool perform(MovieInventory&, CustomerInventory&);  // perform Return movie
    
private:
    Movie* movie;            // movie to Return
    int customerID;          // customer responsible for the transaction
};
#endif

// ----------------------------------inventory.h---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// inventory transaction
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// sub class of transaction
// prints the inventory of the movies by genre then categories of director, title year
// released, and actor and release date for classics
// ------------------------------------------------------------------------------------
#ifndef inventory_h
#define inventory_h
#include "transaction.h"
#include "movie.h"
#include "MovieInventory.h"
#include "CustomerInventory.h"

using namespace std;

class Inventory: public Transaction
{
public:
    
    Inventory();             // constructor
    virtual ~Inventory();    // destructor
    virtual bool perform(MovieInventory&, CustomerInventory&);     // perform inventory
};
#endif

// ----------------------------------history.h---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// history transaction
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// sub class of transaction
// prints the transaction history of a customer in first in last out order
// ------------------------------------------------------------------------------------
#ifndef history_h
#define history_h
#include "transaction.h"
#include "MovieInventory.h"
#include "customer.h"
#include "CustomerInventory.h"

using namespace std;

class History: public Transaction
{
public:
    
    History(int);            // constructor
    virtual ~History();      // destructor
    
    // perform history
    virtual bool perform(MovieInventory&, CustomerInventory&);
    
private:
    int customerID; // customer responsible for the transaction
};
#endif

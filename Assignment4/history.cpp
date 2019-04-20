// ----------------------------------history.cpp---------------------------------------
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
#include "history.h"

// --------------------------------------------------------------------------------------
// input Constructor
// initializes customer for history transaction
// --------------------------------------------------------------------------------------
History::History(int id)
{
    customerID = id;
}

// --------------------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------------------
History::~History()
{
    
}

// --------------------------------------------------------------------------------------
// returns true if history was perfomred successfully
// --------------------------------------------------------------------------------------
bool History::perform(MovieInventory& movies, CustomerInventory& customers)
{
    // check if cusomer exists
    if (!customers.customerExist(customerID))
    {
        cout << "ERROR: History Transaction Failed -- "
        << "Customer " << customerID << " does not exist" << endl;
        return false;
    }
    
    Customer* c = customers.getCustomer(customerID);     // display customer's history
    c -> displayHistory();
    return true;
}

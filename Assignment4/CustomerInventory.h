// ----------------------------------CustomerInventory.h---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// holds inventory of the customers
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// this class stores all the customer objects in a open hash table. It uses their ID as
// a unique key.
// it provides methods to add, remove, get, and check if a customer exists
// ------------------------------------------------------------------------------------
#ifndef CustomerInventory_h
#define CustomerInventory_h
#include "customer.h"
#include <iostream>
using namespace std;

class CustomerInventory
{
public:
    static const int MAX = 10000;            // max number of IDs
    
    CustomerInventory();                     // constructor
    ~CustomerInventory();                    // destructor
    
    Customer* getCustomer (int);             // get Customer with ID
    bool customerExist (int);                // check if customer exists with ID
    bool addCustomer(int, string, string);   // add customer to inventory
    bool removeCustomer(int);                // remove customer from inventory
    
private:
    struct customerNode
    {
        Customer* customer;
        customerNode* next;
    };
    customerNode* hashTable[MAX];            // open hash table for customer nodes
    
    // helper functions
    int hashFunction(int);                   // calculate which bucket to insert customer
    void deleteHelper(customerNode*);        // delete linked list in a hash bucket
};
#endif

// ----------------------------------CustomerInventory.cpp---------------------------------------
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
#include "CustomerInventory.h"

// --------------------------------------------------------------------------------------
// default constructor
// intialize hash table of dummy customer nodes
// --------------------------------------------------------------------------------------
CustomerInventory::CustomerInventory()
{
    for (int i = 0; i < MAX; i++)
    {
        hashTable[i] = new customerNode;
        hashTable[i] -> customer = NULL;
        hashTable[i] -> next = NULL;
    }
}

// --------------------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------------------
CustomerInventory::~CustomerInventory()
{
    for (int i = 0; i < MAX; i++)
    {
        deleteHelper(hashTable[i] -> next);   // delete list of customer in bucket
        
        delete hashTable[i] -> customer;      // delete dummy node customer
        hashTable[i] -> customer = NULL;
        
        delete hashTable[i];                  // delete dummy node
        hashTable[i] = NULL;
    }
}

// --------------------------------------------------------------------------------------
// return customer ptr or NULL if customer doesn't exist
// --------------------------------------------------------------------------------------
Customer* CustomerInventory::getCustomer (int customerID)
{
    int bucket = hashFunction(customerID);
    customerNode* cur = hashTable[bucket] -> next;
    if (cur == NULL)
        return NULL; 
    
    // traverse the bucket to get customer
    while (cur != NULL)
    {
        if (cur -> customer -> getID() == customerID)
            return cur -> customer;
        cur = cur -> next;
    }
    return NULL;
}

// --------------------------------------------------------------------------------------
// returns true if the customer is in the hash table
// --------------------------------------------------------------------------------------
bool CustomerInventory::customerExist (int customerID)
{
    int bucket = hashFunction(customerID);
    customerNode* cur = hashTable[bucket] -> next;
    if (cur == NULL)
        return false; // customer does not exist
    
    // traverse the bucket
    while (cur != NULL)
    {
        if (cur -> customer -> getID() == customerID)
            return true;
        cur = cur -> next;
    }
    return false;
}

// --------------------------------------------------------------------------------------
// returns true if the customer was added to the hash table
// --------------------------------------------------------------------------------------
bool CustomerInventory::addCustomer(int customerID, string firstName, string lastName)
{
    // check if customer already exists
    if (customerExist(customerID))
        return false;
    
    int bucket = hashFunction(customerID);
    customerNode* cur = hashTable[bucket] -> next;
    if (cur == NULL) // insert for first customer in bucket
    {
        cur = new customerNode;
        cur -> customer = new Customer(customerID, firstName, lastName);
        cur -> next = NULL;
        hashTable[bucket] -> next =  cur;
    }
    else // insert additional customers in the bucket
    {
        customerNode* temp = new customerNode;
        temp -> customer = new Customer(customerID, firstName, lastName);
        temp -> next = cur;
        hashTable[bucket] -> next = temp;
    }
    
    return true;
}

// --------------------------------------------------------------------------------------
// returns true if the customer was removed from the hash table
// --------------------------------------------------------------------------------------
bool CustomerInventory::removeCustomer(int customerID)
{
    if (customerExist(customerID)) // delete only if customer exists
    {
        int bucket = hashFunction(customerID);
        customerNode* cur = hashTable[bucket] -> next;
        customerNode* prev = hashTable[bucket];
        while (cur != NULL)
        {
            // delete customer ptr and customer node from hash table
            if (cur -> customer -> getID() == customerID)
            {
                prev -> next = cur -> next;
                cur -> next = NULL;
                delete cur -> customer;
                cur -> customer = NULL;
                delete cur;
                cur = NULL;
                
                return true;
            }
            
            // current ptr moves to next customer
            prev = cur;
            cur = cur -> next;
        }
    }
    return false;
}

// --------------------------------------------------------------------------------------
// returns the index where to store the customer in the hash table
// --------------------------------------------------------------------------------------
int CustomerInventory::hashFunction(int id)
{
    return id % MAX;
}

// --------------------------------------------------------------------------------------
// recursive helper function for destructor
// reletes dynamic memory created by hash table
// --------------------------------------------------------------------------------------
void CustomerInventory::deleteHelper(customerNode* cur)
{
    customerNode* deleteNode = cur;
    while (cur != NULL)
    {
        cur = cur -> next;
        delete deleteNode -> customer;
        deleteNode -> customer = NULL;
        delete deleteNode;
        deleteNode = cur;
    }
}

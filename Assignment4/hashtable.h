#ifndef hashtable_h
#define hashtable_h
#include <stdio.h>
#include <string>
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
#include "inventory.h"
using namespace std;

class Movie;
class Transaction;

class HashTable
{
public:
    Hash();     // default constructor
    ~Hash();    // destructor
    // create new Inventory
    Inventory* createMovie(char, istream&);
    // create new Transaction
    Transaction* createTransaction(char, istream&);
    // get array subscript from letter
    int getSubscript(char);
    // get media type from letter
    string getMediaType(char);
    // max letters
    static const int MAX_COMMANDS = 26;
    
private:
    // return int subscript from char
    int hash(char);
    // set initial values in arrays
    void ininInventory();
};

#endif /* hashtable_hpp */

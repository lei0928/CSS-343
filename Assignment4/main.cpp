// ----------------------------------main.cpp---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// automated inventory tracking system for a local movie rental store
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// the system has two inventory systems that keep track of movies and customers
// it also performs transactions such as borrow, return, iventory, and history
// ------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include "store.h"
using namespace std;

int main()
{
    ifstream customerFile("data4customers.txt");
    ifstream movieFile("data4movies.txt");
    ifstream transactionFile("data4commands.txt");
    
    if (!customerFile)                // repeat for movieFile and transactionFile
        cout << "Customer file cannot be oppened" << endl;
    if (!movieFile)                   // repeat for movieFile and transactionFile
        cout << "Movie file cannot be oppened" << endl;
    if (!transactionFile)             // repeat for movieFile and transactionFile
        cout << "Transaction file cannot be oppened" << endl;
    
    Store movieStore;                                   //create a store
    movieStore.readCustomerFile(customerFile);          //create customer profiles from file
    movieStore.readMovieFile(movieFile);                //create movie inventory from file
    movieStore.readTransactionFile(transactionFile);    //process transactions from file
    
    return 0;
}

// ----------------------------------customer.cpp---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// customer object
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// stores information about a customer, including frist and last name, ID, history
// and movies currently borrowed
// ------------------------------------------------------------------------------------
#include "customer.h"

// --------------------------------------------------------------------------------------
// default constructor
// initiates first and last name as Anonymous
// customer ID initiated to 0
// history and checked out list are both empty
// --------------------------------------------------------------------------------------
Customer::Customer()
{
    firstName = "Anon";
    lastName = "Ymous";
    ID = 0;
    history = NULL;
    checkedOut = NULL;
}

// --------------------------------------------------------------------------------------
// input constructor
// initiates first and last to the passed in strings
// initiates ID to the passed in id int
// history and checked out list are both empty
// --------------------------------------------------------------------------------------
Customer::Customer(int id, string first, string last)
{
    firstName = first;
    lastName = last;
    ID = id;
    history = NULL;
    checkedOut = NULL;
}

// --------------------------------------------------------------------------------------
// destructor
// deletes dynamic memory created by history and checkOut linked lists
// --------------------------------------------------------------------------------------
Customer::~Customer()
{
    // delete history list
    historyNode* temp = history;
    while (temp != NULL)
    {
        history = history -> next;
        delete temp;
        temp = history;
    }
    
    // delete checked out list
    checkedOutNode* cur = checkedOut;
    while (cur != NULL)
    {
        checkedOut = checkedOut -> next;
        delete cur -> movieBorrowed;
        cur -> movieBorrowed = NULL;
        delete cur;
        cur = checkedOut;
    }
}

// --------------------------------------------------------------------------------------
// displays the customer's ID, first name, and last name
// --------------------------------------------------------------------------------------
void Customer::display()
{
    // set preceding 0 for 4 digit ID
    // for IDs less than 4 digits
    string zeros = "";
    if (ID < 10)
        zeros = "000";
    else if (ID < 100)
        zeros = "00";
    else if (ID < 1000)
        zeros = "0";
    
    // print customer info
    cout << zeros << ID  << "    ";
    cout.width(10);
    cout << left << firstName;
    cout.width(10);
    cout << left << lastName << endl;
}

// --------------------------------------------------------------------------------------
// most recent to Least recent (newest transaction to oldest transaction)
// --------------------------------------------------------------------------------------
void Customer::displayHistory()
{
    cout << endl;
    cout << "History for " << getName() << ":" <<endl; // print header
    
    historyNode* temp = history;
    while (temp!= NULL) // print history
    {
        cout << temp -> data << endl;
        temp = temp -> next;
    }
    cout << endl;
}

// --------------------------------------------------------------------------------------
// returns the customer's ID
// --------------------------------------------------------------------------------------
int Customer::getID()
{
    return ID;
}

// --------------------------------------------------------------------------------------
// returns the customer's first and last name
// --------------------------------------------------------------------------------------
string Customer::getName()
{
    return firstName + " " + lastName;
}

// --------------------------------------------------------------------------------------
// newest to oldest transaction
// insert new transaction to the front of the list of history
// --------------------------------------------------------------------------------------
void Customer::addHistory(string summary)
{
    historyNode* newHistory = new historyNode;
    newHistory -> data = summary;
    newHistory -> next = history;
    history = newHistory;
}

// --------------------------------------------------------------------------------------
// insert new checked out movie in front of the list of checked out list
// customer can check out 2 copies of the same movie (do not check for double)
// --------------------------------------------------------------------------------------
void Customer::addCheckedOut(Movie* movie)
{
    
    checkedOutNode* newMovieNode = new checkedOutNode;
    newMovieNode -> movieBorrowed = movie;
    newMovieNode -> next = checkedOut;
    checkedOut = newMovieNode;
}

// --------------------------------------------------------------------------------------
// returns true if customer was able to return a movie from their
// movieBorrowed linked list
// --------------------------------------------------------------------------------------
bool Customer::removeCheckedOut(Movie* movie)
{
    checkedOutNode* cur = checkedOut;
    if (cur != NULL)
    {
        // check the first checkedOutNode
        if (*(cur -> movieBorrowed) == *movie)
        {
            delete checkedOut -> movieBorrowed;
            checkedOut = cur -> next;
            delete cur;
            cur = NULL;
            return true;
        }
        
        // check all other checkedOutNode
        checkedOutNode* prev = cur;
        cur = cur -> next;
        while (cur != NULL)
        {
            if (*(cur -> movieBorrowed) == *movie)
            {
                delete cur -> movieBorrowed;
                // remove movie from the list
                prev -> next = cur -> next;
                
                // delete pointers
                cur -> next = NULL;
                delete cur;
                return true;
            }
            prev = cur;
            cur = cur -> next;
        }
    }
    return false;           // movie was not checked out by the customer
}

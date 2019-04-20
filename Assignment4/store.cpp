// ----------------------------------store.cpp---------------------------------------
// Lei CSS343 section A
// March 7, 2019
// March 18, 2019
// ------------------------------------------------------------------------------------
// store class holds the business logic for the inventory system
// ------------------------------------------------------------------------------------
// specifications and assumptions:
// the performTransaction method which performs either borrowing or returning a movie,
// printing inventory of all the items, and pringting transaction history of a customer,
// performTransaction also cheecks for bad inputs from the imput file
// ------------------------------------------------------------------------------------
#include "store.h"

// --------------------------------------------------------------------------------------
// default constructor
// --------------------------------------------------------------------------------------
Store::Store()
{
    
}

// --------------------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------------------
Store::~Store()
{
    
}

// --------------------------------------------------------------------------------------
// reads specified file and creates customers from it
// --------------------------------------------------------------------------------------
void Store::readCustomerFile (ifstream& input)
{
    int id;
    string firstName, lastName;
    string line;
    getline(input,line);
    
    while(!input.eof())
    {
        // read string as input
        stringstream readLine(line);
        readLine >> id;
        readLine >> lastName;
        readLine >> firstName;
        
        // add new customer to customer hash table
        customerTable.addCustomer(id, firstName, lastName);
        
        // read next line
        getline(input,line);
    }
}


// --------------------------------------------------------------------------------------
// reads specified file and creates movies from it
// --------------------------------------------------------------------------------------
void Store::readMovieFile (ifstream& input)
{
    char genre = 'Z';
    int stock = 0;
    int month = 0;
    int year = 0;
    string director, title, actor;
    
    // read file by line
    string line;
    getline(input, line);
    
    while(!input.eof())
    {
        stringstream readLine(line);
        string temp;
        
        readLine >> temp;                           // temporary string including commas
        genre = temp[0];                            // get first character as genre
        readLine >> stock;
        readLine >> temp;                           // read over the ','
        director = readStringStream(readLine);      // read director until next ','
        title = readStringStream(readLine);         // read title until next ','
        
        // read classics actor and month
        if (genre == 'C')
        {
            readLine >> actor >> temp;
            actor = actor + " " + temp;
            readLine >> temp;
            istringstream(temp) >> month;
        }
        readLine >> year;                           // read year
        
        // Create movie and add to the movieTree
        Movie* newMovie = movieFactory.create(genre, title, director, actor, month, year, stock);
        if(!movieTree.addMovie(newMovie))
            delete newMovie;
        
        title = "";
        director = "";
        actor = "";
        genre = 'Z';
        stock = 0;
        year = 0;
        month = 0;
    
        getline(input,line);                        // read next line
    }
}


// --------------------------------------------------------------------------------------
// reads specified file and processes transactions from it
// --------------------------------------------------------------------------------------
void Store::readTransactionFile (ifstream& input)
{
    char transType, mediaType, genre;
    int id = 0, month = 0, year = 0;
    string actor, director, title, temp;
    Movie* movie = NULL;
    Transaction* newTrans = NULL;
    
    string line;
    getline(input, line);
    
    while(!input.eof())
    {
        stringstream readLine(line);
        readLine >> transType;                      // read transaction type
        
        // continue reading for history, borrow and return transactions
        if(transType == 'H' || transType == 'B' || transType == 'R' )
        {
            readLine >> id;
            
            // continue reading for borrow and return transactions
            if(transType != 'H')
            {
                readLine >> mediaType;
                if (mediaType != 'D') // invalid media type
                    cout << "ERROR: " << mediaType << " Invalid Media Type. Try Again." << endl;
                else
                {
                    readLine >> genre;
                    switch (genre)
                    {
                        case 'F':
                            title = readStringStream(readLine);
                            readLine >> year;
                            break;
                            
                        case 'D':
                            director = readStringStream(readLine);
                            title = readStringStream(readLine);
                            break;
                            
                        case 'C':
                            readLine >> month >> year;
                            readLine >> actor >> temp;
                            actor = actor + " " + temp;
                            break;
                            
                    }
                    movie = movieFactory.create(genre, title, director, actor, month, year, 0);
                }
            }
        }
        
        //create new transaction and perform
        newTrans = transFactory.create(transType, id, movie);
        performTransaction(newTrans);
        delete newTrans;
        
        title = "";
        director = "";
        actor = "";
        genre = 'Z';
        year = 0;
        month = 0;
        newTrans = NULL;
        movie = NULL;
        
        getline(input,line);
    }
}


// --------------------------------------------------------------------------------------
// performs transactions from the transaction file
// --------------------------------------------------------------------------------------
bool Store::performTransaction (Transaction* t)
{
    if (t != NULL)
        return (t -> perform(movieTree, customerTable));
    return false;
}

// --------------------------------------------------------------------------------------
// read part of the string stream and return group of words that are separated by comma
// --------------------------------------------------------------------------------------
string Store::readStringStream (stringstream& input)
{
    string words, temp;
    input >> words;
    
    // read string stream until last character is a comma
    while(words[words.length() - 1] != ',')
    {
        input >> temp;
        words = words + " " + temp;
    }
    
    // remove the last comma character
    if (words[words.length() - 1] == ',')
        words = words.substr(0, words.length() - 1);
    
    return words;
}

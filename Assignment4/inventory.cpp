// ----------------------------------inventory.cpp---------------------------------------
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
#include "inventory.h"

// --------------------------------------------------------------------------------------
// default constructor
// --------------------------------------------------------------------------------------
Inventory::Inventory()
{
    
}

// --------------------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------------------
Inventory::~Inventory()
{
    
}

// --------------------------------------------------------------------------------------
// returns true if inventory print was performed successfully
// --------------------------------------------------------------------------------------
bool Inventory::perform(MovieInventory& movies, CustomerInventory& customers)
{
    movies.printInventory();
    return true;
}

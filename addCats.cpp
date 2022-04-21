///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   9_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "addCats.h"
#include "catDatabase.h"
#include <cassert>
#include <iostream>

bool addCat(Cat* newCat){
    assert(newCat != nullptr);
    if (!newCat->validate()){
        throw std::logic_error(ADD_CATS_FILE_NAME ": The cat pointer given has invalid data");
    }

    if (inTheDatabase(newCat)){
        throw std::logic_error(ADD_CATS_FILE_NAME ": This pointer already exist within the database");
    }

    assert(validateDatabase());

    newCat->next = catDatabaseHeadPointer;
    catDatabaseHeadPointer = newCat;
    amountOfCats++;

    assert(validateDatabase());

    #ifdef DEBUG
        std::cout << ADD_CATS_FILE_NAME << ": Cat " << newCat->getName() << "was just added to the database" << std::endl;
    #endif

    return true;
}



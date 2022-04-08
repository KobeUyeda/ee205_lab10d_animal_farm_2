///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   16_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "catDatabase.h"
#include "Cat.h"

// ***** Initialize the Gloabl Variable *****
size_t amountOfCats = 0;
Cat* catDatabaseHeadPointer = nullptr;

// **** functions used to validate the link list ****
bool validateDatabase() noexcept{
    Cat* iterateThroughCat = catDatabaseHeadPointer;
    while(iterateThroughCat != nullptr){
        if(!iterateThroughCat->validate()){
            return false;
        }
        iterateThroughCat = iterateThroughCat->next;
    }
    #ifdef DEBUG
        std::cout << DATABASE_FILE_NAME << ": The database is valid " << std::endl;
    #endif
    return true;
}

bool inTheDatabase(Cat* catPointer) noexcept{
    for(Cat* catPointerIterator = catDatabaseHeadPointer; catPointerIterator != nullptr; catPointerIterator=catPointerIterator->next){
        if (catPointer == catPointerIterator){
            return true;
        }
    }
    #ifdef DEBUG
        std::cout << DATABASE_FILE_NAME << ": The cat Pointer does not exist with in the database " << std::endl;
    #endif
    return false;
}



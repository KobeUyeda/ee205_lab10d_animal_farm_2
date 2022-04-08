///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   16_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "catDatabase.h"
#include "config.h"
#include <cassert>
#include <stdexcept>

bool deleteCat(Cat* catPointer){
    assert(validateDatabase());
    assert(catPointer != nullptr);
    if(catPointer == catDatabaseHeadPointer){
        catDatabaseHeadPointer = catDatabaseHeadPointer->next;
        delete catPointer;
        amountOfCats--;
        assert(validateDatabase());
        #ifdef DEBUG
            std::cout << DELETE_CATS_FILE_NAME << ": The cat Pointer has been deleted from the database " << std::endl;
        #endif
        return true;
    }

    Cat* iterateThroughCat = catDatabaseHeadPointer;
    while(iterateThroughCat != nullptr){
        if(iterateThroughCat->next == catPointer){
            iterateThroughCat->next = catPointer->next;
            delete catPointer;
            amountOfCats--;
            assert(validateDatabase());
            #ifdef DEBUG
                std::cout << DELETE_CATS_FILE_NAME << ": The cat Pointer has been deleted from the database " << std::endl;
            #endif
            return true;
        }
        iterateThroughCat = iterateThroughCat->next;
    }

    std::cout << DELETE_CATS_FILE_NAME << " deleteCatError: The pointer (" << catPointer << ") does not exist within the database, was not able to delete cat" << std::endl;
    return false;
}

bool deleteAllCats(){
    Cat* iterateThroughCat = catDatabaseHeadPointer;
    while(iterateThroughCat != nullptr){
        bool catDeleted = deleteCat(iterateThroughCat);
        if (!catDeleted){
            #ifdef DEBUG
                std::cout << DELETE_CATS_FILE_NAME << ": There seems to have been an error " << std::endl;
            #endif
            return false;
        }
    }
    #ifdef DEBUG
        std::cout << DELETE_CATS_FILE_NAME << ": The whole database has been deleted " << std::endl;
    #endif
    return true;
}
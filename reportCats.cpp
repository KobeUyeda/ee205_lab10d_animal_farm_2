///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   9_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "catDatabase.h"
#include "reportCats.h"
#include "config.h"
#include <cassert>

// ***** ENUM print conversion function *****

const char* genderName (const enum genderType gender){
    switch (gender){
        case 0:
            return "Unknown Gender";
        case 1:
            return "Male";
        case 2:
            return "Female";
    }
    return "";
}

const char* breedName (const enum breedType breed){
    switch (breed){
        case 0:
            return "Unknown Breed";
        case 1:
            return "Maine Coon";
        case 2:
            return "Manx";
        case 3:
            return "Short hair";
        case 4:
            return "Persian";
        case 5:
            return "Spheynx";
    }
    return "";

}

/*const char* colorName (const enum color collarColor){
    switch (collarColor){
        case 0:
            return "Black";
        case 1:
            return "White";
        case 2:
            return "Red";
        case 3:
            return "Blue";
        case 4:
            return "Green";
        case 5:
            return "Pink";
    }
    return "";

}*/

// ***** Report functions *****

void printAllCats(){
    assert(validateDatabase());
    Cat* iterateThroughCat = catDatabaseHeadPointer;
    while(iterateThroughCat != nullptr){
        iterateThroughCat->print();
        iterateThroughCat = iterateThroughCat->next;
    }
}


Cat* findCatByName(const std::string& nameLookingUp){
    Cat* iterateThroughCat = catDatabaseHeadPointer;
    while(iterateThroughCat != nullptr){
        if (iterateThroughCat->getName() == nameLookingUp){
            #ifdef DEBUG
                std::cout << REPORT_CATS_FILE_NAME << ": The cat has been found" << std::endl;
            #endif
            return(iterateThroughCat);
        }
        iterateThroughCat = iterateThroughCat->next;
    }
    std::cout << "Name Look Up Error: The name does not exist within the database" << std::endl;
    return(nullptr);
}
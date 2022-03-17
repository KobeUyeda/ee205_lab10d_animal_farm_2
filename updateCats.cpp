///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   16_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "updateCats.h"
#include "catDatabase.h"
#include "config.h"
#include <string.h>

// updates cat name
int updateCatName(const size_t index, const char newName[]){
    if(isNameValid(newName) == false || isIndexValid(index) == false){
#ifdef DEBUG
        printf("Name Vaild: %d, Index Valid: %d\n", isNameValid(newName), isIndexValid(index));
#endif
        fprintf(stderr, "%s ...Update Name ERROR: there was an error check above for the reason.\n", UPDATE_CATS_FILE_NAME);
        return -1;
    }
    strcpy(catLists[index].name, newName);
    return 1;
}
// updates the status of fixed to true
int fixCat(const size_t index){
    if (isIndexValid(index) == false){
#ifdef DEBUG
        printf("Index Valid: %d\n", isIndexValid(index));
#endif
        fprintf(stderr, "%s ...Fix Cat ERROR: there was an error trying to fix cat look above for the reason\n", UPDATE_CATS_FILE_NAME);
        return -1;
    }
    catLists[index].isFixed = true;
    return 1;
}

// update the weight of the cat
int updateCatWeight(const size_t index, const float newWeight){
    if (isIndexValid(index) == false || isWeightValid(newWeight) == false){
#ifdef DEBUG
        printf("Index Valid: %d, Weight Valid: %d\n", isIndexValid(index), isWeightValid(newWeight));
#endif
        fprintf(stderr, "%s ...Cat Weight ERROR: there was an error trying to update the cat weight look above for the reason\n", UPDATE_CATS_FILE_NAME);
        return -1;
    }
    catLists[index].weight = newWeight;
    return 1;
}
// This is to update the collar colors
int updateCatCollar1(const size_t index, enum color newCollarColor){
    if (isIndexValid(index) == false){
#ifdef DEBUG
        printf("Index Valid: %d\n", isIndexValid(index));
#endif
        fprintf(stderr, "%s ...Cat Weight ERROR: there was an error trying to update the cat collar look above for the reason\n", UPDATE_CATS_FILE_NAME);
        return -1;
    }
    catLists[index].collarColor1 = newCollarColor;
    return 1;
}

int updateCatCollar2(const size_t index, enum color newCollarColor){
    if (isIndexValid(index) == false){
#ifdef DEBUG
        printf("Index Valid: %d\n", isIndexValid(index));
#endif
        fprintf(stderr, "%s ...Cat Weight ERROR: there was an error trying to update the cat collar look above for the reason\n", UPDATE_CATS_FILE_NAME);
        return -1;
    }
    catLists[index].collarColor2 = newCollarColor;
    return 1;
}

// Updates the license number
int updateLicense (const size_t index, unsigned long long newLicense){
    if (isIndexValid(index) == false){
#ifdef DEBUG
        printf("Index Valid: %d\n", isIndexValid(index));
#endif
        fprintf(stderr, "%s ...Cat Weight ERROR: there was an error trying to update the cat license look above for the reason\n", UPDATE_CATS_FILE_NAME);
        return -1;
    }
    catLists[index].license = newLicense;
    return 1;
}

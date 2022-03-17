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
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "config.h"
#include "deleteCats.h"
#include "catDatabase.h"

// ***** Initialize the Gloabl Variable *****
size_t amountOfCats = 0;

struct catData catLists[MAX_DATABASE_LENGTH] = {};

// ****** Validates the input to the database *******
bool isNameValid(const char name[MAX_NAME_LENGTH]){
    bool error = true;
    if (strlen(name) == 0){
        fprintf(stderr, "%s ...Too Short: The name entered [%s] must have at least one character\n", DATABASE_FILE_NAME, name);
        error =  false;
    }
    if(strlen(name)+1 > MAX_NAME_LENGTH){
        fprintf(stderr, "%s ...Too Long: The name you entered [%s] is to long and needs to be less than %d\n", DATABASE_FILE_NAME, name, MAX_NAME_LENGTH);
        error = false;
    }
    for(size_t i = 0; i < amountOfCats; i++){
        if (strcmp(name, catLists[i].name) == 0){
            fprintf(stderr, "%s ...Same Name: This name [%s] has been already used within the database\n", DATABASE_FILE_NAME, name);
            error = false;
        }
    }
    return error;
}

bool isIndexValid(const size_t index){
    if (index >= amountOfCats){
        fprintf(stderr, "%s ...Index out of Range: the index [%ld] input into the function must be in range of 0-%ld\n", DATABASE_FILE_NAME, index, amountOfCats);
        return false;
    }
    return true;
}

bool isWeightValid(const float weight){
    const float WEIGHT_GREATER_THAN_VALID = 0;

    if (weight <= WEIGHT_GREATER_THAN_VALID){
        fprintf(stderr, "%s ...Invalid Weight: The weight must be greater than 0", DATABASE_FILE_NAME);
        return false;
    }
    return true;
}

bool isDatabaseFull(){
    if (amountOfCats >= MAX_DATABASE_LENGTH){
        fprintf(stderr, "%s ...Database Full: the database is full. The database can only fit up to %d\n", DATABASE_FILE_NAME, MAX_DATABASE_LENGTH);
        return true;
    }
    return false;
}

// ***** Has to deal with the database ******


// Cleans the data by getting rid of the data
bool databaseFix(){
    bool error = false;

    for (size_t i = 0; i < amountOfCats; i++){
        if (isNameValid(catLists[i].name) || isWeightValid(catLists[i].weight)){
            deleteCat(i);
            error = true;
        }
    }
    return error;
}

bool isNameInDatabaseValid(const char name[MAX_NAME_LENGTH]){
    const int SHOWS_UP_TWICE = 2;

    bool error    = true;
    int  sameName = 0;
    if (strlen(name) == 0){
        fprintf(stderr, "%s ...Too Short: The name entered [%s] must have at least one character\n", DATABASE_FILE_NAME, name);
        error =  false;
    }
    if(strlen(name)+1 > MAX_NAME_LENGTH){
        fprintf(stderr, "%s ...Too Long: The name you entered [%s] is to long and needs to be less than %d\n", DATABASE_FILE_NAME, name, MAX_NAME_LENGTH);
        error = false;
    }
    for(size_t i = 0; i < amountOfCats; i++){
        if (strcmp(name, catLists[i].name) == 0){
            if(sameName == SHOWS_UP_TWICE){
                fprintf(stderr, "%s ...Same Name: This name [%s] has been already used within the database\n", DATABASE_FILE_NAME, name);
                error = false;
            }
            sameName++;
        }
    }
    return error;
}

bool isDatabaseValid(){
    bool error = true;
    for (size_t i = 0; i < amountOfCats; i++){
        if (isNameInDatabaseValid(catLists[i].name) == false || isWeightValid(catLists[i].weight) == false){
#ifdef DEBUG
            printf("Name Valid: %d, Weight Valid: %d\n", isNameValid(catLists[i].name) == false, isWeightValid(catLists[i].weight)==false);
#endif
            fprintf(stderr, "%s ...ERROR: Some how an error got through the database. Nothing was fixed to fix it call upon the fixDatabaseError Command. The index with error is %ld\n", DATABASE_FILE_NAME, i);
            error = false;
        }
    }
    return error;
}

void resetDataBase(){
    amountOfCats = 0;
    memset(catLists, 0, sizeof(catLists));
}

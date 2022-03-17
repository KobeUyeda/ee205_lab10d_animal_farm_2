///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author @todo <@todo@hawaii.edu>
/// @date   16_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "addCats.h"
#include "catDatabase.h"
#include "config.h"
#include <string.h>
#include <stdio.h>

int addCat(
        const char name[],
        const enum genderType gender,
        const enum breedType breed,
        const bool isFixed,
        const float weight,
        const enum color collarColor1,
        const enum color collarColor2,
        const unsigned long long license
){
    if (isNameValid(name) == false || isWeightValid(weight) == false || isDatabaseFull() || isDatabaseValid() == false){
#ifdef DEBUG
        printf("Name Valid: %d, Weight Valid: %d, Database Full: %d, database is Valid: %d\n", isNameValid(name) == false, isWeightValid(weight)==false, isDatabaseFull(), isDatabaseValid()==false);
#endif
        fprintf(stderr, "%s ...One of your inputs were invalid or issue with database look above to see all problems:\n", ADD_CATS_FILE_NAME);
        return -1;
    }

    strcpy(catLists[amountOfCats].name, name);

    catLists[amountOfCats].gender       = gender;
    catLists[amountOfCats].breed        = breed;
    catLists[amountOfCats].isFixed      = isFixed;
    catLists[amountOfCats].weight       = weight;
    catLists[amountOfCats].collarColor1 = collarColor1;
    catLists[amountOfCats].collarColor2 = collarColor2;
    catLists[amountOfCats].license      = license;

    amountOfCats++;
    return (amountOfCats - 1);
}



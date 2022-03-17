///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   16_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "catDatabase.h"
#include "reportCats.h"
#include "config.h"
#include <stdio.h>
#include <string.h>

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

const char* colorName (const enum color collarColor){
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

}

// ***** Report functions *****
void printCat(const size_t index){
    if (isIndexValid(index) == false){
        fprintf(stderr, "%s ...animalFarm0: Bad cat [%lu] \n", REPORT_CATS_FILE_NAME, index);
    }
    else {
        printf("cat index = [%lu] name=[%s] gender=[%s] breed=[%s] isFixed=[%d] weight=[%f] color1=[%s] color2=[%s] license=[%lld]\n",
               index,
               catLists[index].name,
               genderName(catLists[index].gender),
               breedName(catLists[index].breed),
               catLists[index].isFixed,
               catLists[index].weight,
               colorName(catLists[index].collarColor1),
               colorName(catLists[index].collarColor2),
               catLists[index].license
        );
    }
}

void printAllCats(){
    for (size_t i = 0; i < amountOfCats; i++){
        printf("cat index = [%lu] name=[%s] gender=[%s] breed=[%s] isFixed=[%d] weight=[%f] color1=[%s] color2=[%s] license=[%lld]\n",
               i,
               catLists[i].name,
               genderName(catLists[i].gender),
               breedName(catLists[i].breed),
               catLists[i].isFixed,
               catLists[i].weight,
               colorName(catLists[i].collarColor1),
               colorName(catLists[i].collarColor2),
               catLists[i].license
        );
    }
}

// Used to find the index number if given the cat name
int findCat(const char name[]){
    for (size_t i = 0; i < amountOfCats; i++){
        if (strcmp(name, catLists[i].name) == 0){
            return i;
        }
    }
    return -1;
}
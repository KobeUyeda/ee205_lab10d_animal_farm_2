///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   9_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <stdio.h>
#include "catDatabase.h"

const char* genderName (const enum genderType gender);
const char* breedName (const enum breedType breed);
//const char* colorName (const enum color collarColor);    // Commented out since not being used in this code

extern void printCat(const size_t index);
extern void printAllCats();
extern Cat* findCatByName(const std::string& nameLookingUp);

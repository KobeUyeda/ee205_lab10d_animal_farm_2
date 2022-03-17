///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.h
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   16_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <stdbool.h>
#include "catDatabase.h"

extern int addCat(const char name[],
                  const enum genderType gender,
                  const enum breedType breed,
                  const bool isFixed,
                  const float weight,
                  const enum color collarColor1,
                  const enum color collarCollar2,
                  const unsigned long long license);

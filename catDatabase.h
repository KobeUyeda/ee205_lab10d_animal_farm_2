///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_010d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Cat.h"

extern Cat*   catDatabaseHeadPointer;
extern size_t amountOfCats;

extern bool validateDatabase() noexcept;
extern bool inTheDatabase(Cat* catPointer) noexcept;




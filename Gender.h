///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file Gender.h
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>

enum genderType{UNKNOWN_GENDER, MALE, FEMALE};

const std::string UNKNOWN_GENDER_STRING = "Unknown Gender";
const std::string MALE_STRING           = "Male";
const std::string FEMALE_STRING         = "Female";

extern std::ostream &operator<< (std::ostream &lhs_stream, const genderType &rhs_Gender);
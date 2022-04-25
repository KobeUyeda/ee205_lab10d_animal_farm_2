///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Gender.cpp
/// @version 3.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////



#include "Gender.h"
#include <iostream>

std::ostream &operator<< (std::ostream &lhs_stream, const genderType &rhs_Gender){
    switch( rhs_Gender ) {
        case UNKNOWN_GENDER:
            return lhs_stream << UNKNOWN_GENDER_STRING;
        case MALE:
            return lhs_stream << MALE_STRING;
        case FEMALE:
            return lhs_stream << FEMALE_STRING;
        default:
            throw std::out_of_range("The unit can’t be mapped to a string");
    }
}
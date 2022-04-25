///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file Color.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////



#include "Color.h"
#include <iostream>

std::ostream &operator<< (std::ostream &lhs_stream, const Color &rhs_color){
    switch( rhs_color ) {
        case UNKNOWN_COLOR:
            return lhs_stream << UNKNOWN_COLOR_STRING;
        case BLACK:
            return lhs_stream << BLACK_STRING;
        case BROWN:
            return lhs_stream << BROWN_STRING;
        case WHITE:
            return lhs_stream << WHITE_STRING;
        case RED:
            return lhs_stream << RED_STRING;
        case BLUE:
            return lhs_stream << BLUE_STRING;
        case GREEN:
            return lhs_stream << GREEN_STRING;
        case GINGER:
            return lhs_stream << GINGER_STRING;
        case CREAM:
            return lhs_stream << CREAM_STRING;
        case CINNAMON:
            return lhs_stream << CINNAMON_STRING;
        case CALICO:
            return lhs_stream << CALICO_STRING;
        default:
            throw std::out_of_range("The unit can’t be mapped to a string");
    }
}
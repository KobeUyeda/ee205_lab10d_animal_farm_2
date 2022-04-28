///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Color.h
/// @version 3.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>

enum Color{UNKNOWN_COLOR =0 , BLACK , BROWN , WHITE , RED , BLUE , GREEN , GINGER , CREAM , CINNAMON , CALICO};

const std::string UNKNOWN_COLOR_STRING = "Unknown Color";
const std::string BLACK_STRING         = "Black";
const std::string BROWN_STRING         = "Brown";
const std::string WHITE_STRING         = "White";
const std::string RED_STRING           = "Red";
const std::string BLUE_STRING          = "Blue";
const std::string GREEN_STRING         = "Green";
const std::string GINGER_STRING        = "Ginger";
const std::string CINNAMON_STRING      = "Cinnamon";
const std::string CALICO_STRING        = "Calico";
const std::string CREAM_STRING         = "Cream";

extern std::ostream &operator<< (std::ostream &lhs_stream, const Color &rhs_color);

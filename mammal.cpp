///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file mammal.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////



#include "mammal.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#define FORMAT_LINE(className, member) std::cout << std::setw(8) << (className) << std::setw(20) << (member) << std::setw(52)

const std::string Mammal::MAMMAL_NAME = "Mammalian";

Color Mammal::getColor() const noexcept {
    return Mammal::color;
}

void Mammal::setColor(const Color newColor) noexcept {
    Mammal::color = newColor;
}

void Mammal::dump() const noexcept {
    Animal::dump();
    FORMAT_LINE("Mammal", "color") << Mammal::getColor() << std::endl;
}
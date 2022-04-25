///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file cat.cpp
/// @version 3.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   9_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Cat.h"
#include "config.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>

#define FORMAT_LINE(className, member) std::cout << std::setw(8) << (className) << std::setw(20) << (member) << std::setw(52)

const Weight::t_weight Cat::MAX_WEIGHT   = 40;
const std::string      Cat::SPECIES_NAME = "Felis Catus";

// *** Validate Methods for each field ***
bool Cat::validateName(const std::string& newName){
    if(newName.empty()){
        throw std::length_error(CAT_FILE_NAME ": name length has to be greater than 0");
    }
    #ifdef DEBUG
        std::cout << CAT_FILE_NAME << ": Cat " << newName << " is a valid name" << std::endl;
    #endif
    return true;
}

// Methods Required: Prints out the data in a certain format
void Cat::dump() const noexcept {
    //assert( validate() );
    Mammal::dump();
    FORMAT_LINE("Cat", "name") << Cat::getName() << std::endl;
    FORMAT_LINE("Cat", "isFixed") << Cat::getCatFixed() << std::endl;
}

// Methods Required: brings all the validators together and creates an error print out for any errors
bool Cat::validate() const noexcept {
    if(!Mammal::validate()){
        return false;
    }
    try{
        validateName(name);
    } catch (std::exception const& error){
        std::cout << error.what() << std::endl;
        return false;
    }
    #ifdef DEBUG
        std::cout << CAT_FILE_NAME << ": Cat has been validated " << name << std::endl;
    #endif
    return true;
}

// *** Getter methods ***
std::string Cat::getName() const noexcept {
    return(name);
}

bool Cat::getCatFixed() const noexcept {
    return(isCatFixed);
}

// *** Setter methods ***
bool Cat::setName(const std::string& newName) noexcept {
    try {
        validateName(newName);
    } catch (std::exception const& error) {
        std::cout << error.what() << std::endl;
        return false;
    }
    name.assign(newName);
    #ifdef DEBUG
        std::cout << CAT_FILE_NAME << ": Cat name has been changed to" << name << std::endl;
    #endif
    return true;
}

bool Cat::setCatFixed() noexcept {
    isCatFixed = true;
    #ifdef DEBUG
        std::cout << CAT_FILE_NAME << ": Cat name has been changed to" << isCatFixed << std::endl;
    #endif
    return true;
}

std::string Cat::speak() const noexcept {
    return "Meow";
}


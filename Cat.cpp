///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file cat.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   9_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Cat.h"
#include "config.h"
#include "reportCats.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cassert>

#define FORMAT_LINE(className, member) std::cout << std::setw(8) << (className) << std::setw(20) << (member) << std::setw(52)

// Added Method to allow easily setting the values back to 0 for initializer and destructor
void Cat::setDataToZero() {
    name.assign("");
    isCatFixed = false;
    weight     = 0;
    gender     = UNKNOWN_GENDER;
    breed      = UNKOWN_BREED;
}

// *** Initializers ***
Cat::Cat() noexcept{
    setDataToZero();
    #ifdef DEBUG
        std::cout << CAT_FILE_NAME << ": New cat has been initialized and has no values" << std::endl;
    #endif
}

Cat::Cat(const std::string& newName,
         const genderType newGender,
         const breedType newBreed,
         const Weight newWeight) {
    setDataToZero();
    weight     = newWeight;
    gender     = newGender;
    breed      = newBreed;
    name.assign(newName);

    #ifdef DEBUG
        std::cout << CAT_FILE_NAME << ": New cat has been initialized and has valid values" << std::endl;
    #endif
}

// *** Destructor ***
Cat::~Cat() {
    setDataToZero();
    #ifdef DEBUG
        std::cout << CAT_FILE_NAME << ": Cat has been deleted with values being set to 0" << std::endl;
    #endif
}

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

bool Cat::validateWeight(const Weight newWeight){
    if(newWeight <= 0){
        throw std::invalid_argument(CAT_FILE_NAME ": The weight must be greater than 0");
    }
    #ifdef DEBUG
        std::cout << CAT_FILE_NAME << ": Cat " << newWeight << " is a valid weight" << std::endl;
    #endif
    return true;
}

bool Cat::validateBreed(const breedType newBreed){
    if(newBreed == UNKOWN_BREED){
        throw std::invalid_argument(CAT_FILE_NAME ": The breed of the cat must be known");
    }
    #ifdef DEBUG
        std::cout << CAT_FILE_NAME << ": Cat " << newBreed << " is a valid Breed" << std::endl;
    #endif
    return true;
}

bool Cat::validateGender(const genderType newGender){
    if(newGender == UNKNOWN_GENDER){
        throw std::invalid_argument(CAT_FILE_NAME ": The gender of the cat must be known");
    }
    #ifdef DEBUG
        std::cout << CAT_FILE_NAME << ": Cat " << newGender << " is a valid gender" << std::endl;
    #endif
    return true;
}

// Methods Required: Prints out the data in a certain format
bool Cat::print() const noexcept {
    assert( validate() );

    std::cout << std::setw(80) << std::setfill('=') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::left;
    std::cout << std::boolalpha;

    FORMAT_LINE("Cat", "name") << getName() << std::endl;
    FORMAT_LINE("Cat", "gender") << genderName(getGender()) << std::endl;
    FORMAT_LINE("Cat", "breed") << breedName(getBreed()) << std::endl;
    FORMAT_LINE("Cat", "isFixed") << getCatFixed() << std::endl;
    FORMAT_LINE("Cat", "weight") << getWeight() << std::endl;

    return true;
}

// Methods Required: brings all the validators together and creates an error print out for any errors
bool Cat::validate() const noexcept {
    try{
        validateName(name);
        validateWeight(weight);
        validateBreed(breed);
        validateGender(gender);
    } catch (std::exception const& error){
        std::cout << error.what() << std::endl;
        return false;
    }
    return true;
}

// *** Getter methods ***
std::string Cat::getName() const noexcept {
    return(name);
}

enum genderType Cat::getGender() const noexcept {
    return(gender);
}

enum breedType Cat::getBreed() const noexcept {
    return(breed);
}

bool Cat::getCatFixed() const noexcept {
    return(isCatFixed);
}

Weight Cat::getWeight() const noexcept {
    return(weight);
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

bool Cat::setGender(const enum genderType newGender) noexcept {
    try {
        validateGender(newGender);
    } catch (std::exception const& error) {
        std::cout << error.what() << std::endl;
        return false;
    }
    gender = newGender;
    #ifdef DEBUG
        std::cout << CAT_FILE_NAME << ": Cat name has been changed to" << gender << std::endl;
    #endif
    return true;
}

bool Cat::setBreed(const enum breedType newBreed) noexcept {
    try {
        validateBreed(newBreed);
    } catch (std::exception const& error) {
        std::cout << error.what() << std::endl;
        return false;
    }
    breed = newBreed;
    #ifdef DEBUG
        std::cout << CAT_FILE_NAME << ": Cat name has been changed to" << breed << std::endl;
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

bool Cat::setWeight(const Weight newWeight) noexcept {
    try {
        validateWeight(newWeight);
    } catch (std::exception const& error) {
        std::cout << error.what() << std::endl;
        return false;
    }
    weight = newWeight;
    #ifdef DEBUG
        std::cout << CAT_FILE_NAME << ": Cat name has been changed to" << weight << std::endl;
    #endif
    return true;
}

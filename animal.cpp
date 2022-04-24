///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file animal.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "animal.h"
#include "node.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>

#define FORMAT_LINE(className, member) std::cout << std::setw(8) << (className) << std::setw(20) << (member) << std::setw(52)

const std::string Animal::KINGDOM_NAME = "Animalia";
const std::string WHITESPACE = " \n\r\t\f\v";

Animal::Animal(const Weight::t_weight newMaxWeight, const std::string &newClassification,
               const std::string &newSpecies) {

    Animal::weight         = Weight(0, newMaxWeight);
    Animal::classification = newClassification;
    Animal::species        = newSpecies;

}
Animal::Animal(const genderType newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight,
               const std::string &newClassification, const std::string &newSpecies) {

    Animal::weight         = Weight(newWeight, newMaxWeight);
    Animal::classification = newClassification;
    Animal::species        = newSpecies;
    Animal::gender         = newGender;

}

std::string Animal::getKingdom() const noexcept {
    return Animal::KINGDOM_NAME;
}

std::string Animal::getClassification() const noexcept {
    return Animal::classification;
}

std::string Animal::getSpecies() const noexcept {
    return Animal::species;
}

Animal::genderType Animal::getGender() const noexcept {
    return Animal::gender;
}

Weight::t_weight Animal::getWeight() const noexcept {
    return Animal::weight.getWeight();
}

void Animal::setWeight(const Weight::t_weight newWeight) {
    Animal::weight.setWeight(newWeight);
}

void Animal::dump() const noexcept {
    Node::dump();
    FORMAT_LINE("Animal", "this") << this << std::endl;
    FORMAT_LINE("Animal", "Kingdom") << Animal::getKingdom() << std::endl;
    FORMAT_LINE("Animal", "classification") << Animal::getClassification() << std::endl;
    FORMAT_LINE("Animal", "species") << Animal::getSpecies() << std::endl;
    FORMAT_LINE("Animal", "gender") << Animal::getGender() << std::endl;
    FORMAT_LINE("Animal", "weight") << Animal::getWeight() << std::endl;
}

std::string Animal::leftTrim(const std::string &stringTrim) {
    std::size_t trimOnLeftAmount  = stringTrim.find_first_not_of(WHITESPACE);
    return (trimOnLeftAmount == std::string::npos) ? "" : stringTrim.substr(trimOnLeftAmount);
}

std::string Animal::rightTrim(const std::string &stringTrim) {
    std::size_t trimOnRightAmount = stringTrim.find_last_not_of(WHITESPACE);
    return (trimOnRightAmount == std::string::npos) ? "" : stringTrim.substr(trimOnRightAmount);
}

bool Animal::validateClassification(const std::string &checkClassification) noexcept {
    std::string validateString = Animal::rightTrim(Animal::leftTrim(checkClassification));
    if(validateString.length() == 0){
        return false;
    }
    return true;
}

bool Animal::validateSpecies(const std::string &checkSpecies) noexcept {
    std::string validateString = Animal::rightTrim(Animal::leftTrim(checkSpecies));
    if(validateString.length() == 0){
        return false;
    }
    return true;
}
bool Animal::validate() const noexcept {
    if(!Animal::weight.validate() ||
    !Animal::validateSpecies(Animal::getSpecies()) ||
    !Animal::validateClassification(Animal::getClassification())){
        return false;
    }
    return true;
}

void Animal::setGender(const genderType newGender) {
    gender = newGender;
}

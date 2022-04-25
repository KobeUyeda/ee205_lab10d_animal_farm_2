///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file animal.h
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "weight.h"
#include "node.h"
#include "Gender.h"
#include "config.h"

class Animal: public Node{
public:
    // Used to define the Kingodm Name based on the classes
    static const std::string KINGDOM_NAME;

private:
    std::string species;
    std::string classification;
    genderType gender = genderType::UNKNOWN_GENDER;
    Weight weight;

// Constructors
public:
    Animal(const Weight::t_weight newMaxWeight,
           const std::string &newClassification,
           const std::string &newSpecies);
    Animal (const genderType newGender,
            const Weight::t_weight newWeight,
            const Weight::t_weight newMaxWeight,
            const std::string &newClassification,
            const std::string &newSpecies);

// These are getter methods
public:
    std::string      getKingdom()        const noexcept; // returns the kingdom: type string
    std::string      getClassification() const noexcept; // returns the classification: type string
    std::string      getSpecies()        const noexcept; // returns the species : type string
    genderType       getGender()         const noexcept; // returns the gender : type enum gender type
    Weight::t_weight getWeight()         const noexcept; // returns the weight : type typedef float

// These are the setter methods
public:
    void setWeight(const Weight::t_weight newWeight);    // attribute: type typedef float

public:
    virtual std::string speak() const noexcept=0;        // returns a string defined in the inheritance of Animal

    void dump()     const noexcept override;             // prints out all values of the object
    bool validate() const noexcept override;             // Validates to make sure the object is valid

public:
    static bool validateClassification(const std::string &checkClassification) noexcept;
    static bool validateSpecies(const std::string &checkSpecies) noexcept;

protected:
    void setGender(const genderType newGender);

private:
    static std::string leftTrim(const std::string &stringTrim);
    static std::string rightTrim(const std::string &stringTrim);

};
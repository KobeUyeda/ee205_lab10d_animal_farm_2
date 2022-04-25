///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file cat.h
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   9_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <string>
#include "config.h"
#include "mammal.h"
#include "weight.h"

class Cat:public Mammal{
public:
    static const std::string      SPECIES_NAME;
    static const Weight::t_weight MAX_WEIGHT;

/* **** Everything underneath are member variables that are protected **** */
protected:
    std::string     name;
    bool            isCatFixed;

/* **** Underneath defines all the constructors and destructors for this class **** */
public:
    // Constructors
    explicit Cat(const std::string newName) : Mammal(MAX_WEIGHT, SPECIES_NAME){
        if(!validateName(newName)){
            throw std::out_of_range("The cat Class must have a name");
        }
        Cat::name = newName;
        Cat::isCatFixed = false;
        Cat::validate();
    };
    Cat(const std::string& newName,
        const Color newColor,
        const bool newIsFixed,
        const genderType newGender,
        const Weight::t_weight newWeight): Mammal(newColor, newGender, newWeight, MAX_WEIGHT, SPECIES_NAME) {
        if(!validateName(newName)){
            throw std::out_of_range("The cat class must have a name");
        }
        Cat::name = newName;
        Cat::isCatFixed = newIsFixed;
        Cat::validate();
    };

/* **** Creating helper methods to validate the data **** */
public:
    static bool validateName( const std::string& newName);
    //static bool validateBreed( breedType newBreed);

/* **** Methods to print values and validate Data **** */
public:
    std::string speak() const noexcept override;
    void dump()     const noexcept override;
    bool validate() const noexcept override;

/* **** Underneath defines all the getter and setters for values stored in the cat object **** */
public:
    //Getters
    std::string      getName()     const noexcept;
    bool             getCatFixed() const noexcept;

    //Setter
    bool setName(const std::string& newName)   noexcept;
    bool setCatFixed()                         noexcept;

};
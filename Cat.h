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

class Cat{

/* **** Everything underneath are member variables that are protected **** */
protected:
    std::string     name;
    bool            isCatFixed;
    Weight          weight;
    enum genderType gender;
    enum breedType  breed;

/* **** Underneath is a member variable that is used as a next pointer for link list **** */
public:
    Cat* next;

/* **** underneath is a method that sets the value of the protected member variables to zero **** */
protected:
    void setDataToZero();

/* **** Underneath defines all the constructors and destructors for this class **** */
public:
    // Constructors
    Cat() noexcept;
    Cat(const std::string& newName,
        genderType newGender,
        breedType newBreed,
        Weight newWeight) ;

    // Destructors
    virtual ~Cat();

/* **** Creating helper methods to validate the data **** */
public:
    static bool validateName( const std::string& newName);
    static bool validateWeight( Weight newWeight);
    static bool validateBreed( breedType newBreed);
    static bool validateGender( genderType newGender);

/* **** Methods to print values and validate Data **** */
public:
    bool print()    const noexcept;
    bool validate() const noexcept;

/* **** Underneath defines all the getter and setters for values stored in the cat object **** */
public:
    //Getters
    std::string     getName()     const noexcept;
    enum genderType getGender()   const noexcept;
    enum breedType  getBreed()    const noexcept;
    bool            getCatFixed() const noexcept;
    Weight          getWeight()   const noexcept;

    //Setter
    bool setName(const std::string& newName)   noexcept;
    bool setGender(enum genderType newGender)  noexcept;
    bool setBreed(enum breedType newBreed)     noexcept;
    bool setCatFixed()                         noexcept;
    bool setWeight(Weight newWeight)           noexcept;

};
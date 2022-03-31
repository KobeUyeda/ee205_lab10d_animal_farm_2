///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file cat.h
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include "catDatabase.h"

class Cat{
protected:
    std::string     name;
    bool            isCatFixed;
    Weight          weight;
    enum genderType gender;
    enum breedType  breed;

/* **** Underneath defines all the constructors and destructors for this class **** */
public:
    // Constructors
    Cat();
    Cat(const std::string newName, const genderType newGender, const breedType newBreed, const Weight newWeight);

    // Destructors
    virtual ~Cat();

public:
    void print();
    bool validate();

/* **** Underneath defines all the getter and setters for values stored in the cat object **** */
public:
    //Getters
    std::string getName() const noexcept;

};
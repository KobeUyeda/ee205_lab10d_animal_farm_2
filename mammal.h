///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file mammal.h
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include "weight.h"
#include "animal.h"
#include "Color.h"
#include "Gender.h"


class Mammal: public Animal {
protected:
    Color color = Color::UNKNOWN_COLOR;

public:
    static const std::string MAMMAL_NAME;

    // Constructor uses the animal constructors to stop reuse of code
public:
    Mammal(const Weight::t_weight newMaxWeight,
           const std::string &newSpecies): Animal(newMaxWeight, MAMMAL_NAME, newSpecies) {};
    Mammal(const Color newColor,
           const genderType newGender,
           const Weight::t_weight newWeight,
           const Weight::t_weight newMaxWeight,
           const std::string &newSpecies) : Animal(newGender, newWeight, newMaxWeight, MAMMAL_NAME, newSpecies){
            setColor(newColor);
           };

    // Getter method
public:
    Color getColor() const noexcept;

    // Setter Method
public:
    void setColor(const Color newColor) noexcept;

    // Other methods the object can do
public:
    void dump() const noexcept override;
};


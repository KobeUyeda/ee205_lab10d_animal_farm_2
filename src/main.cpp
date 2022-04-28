///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 3.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   9_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <cassert>
#include <iostream>
#include <exception>
#include "Cat.h"
#include "singleLinkedList.h"
#include "config.h"
#include "Gender.h"



int main() {
    std::cout << "Starting " << MAIN_FILE_NAME << std::endl ;
    SinglyLinkedList catDB ;
    catDB.push_front( new Cat( "Loki", Color::CREAM, true, genderType::MALE, 1.0 ) ) ;
    catDB.push_front( new Cat( "Milo", Color::BLACK, true, genderType::MALE, 1.1 ) ) ;
    catDB.push_front( new Cat( "Bella", Color::BROWN, true, genderType::FEMALE, 1.2 ) ) ;
    catDB.push_front( new Cat( "Kali", Color::CALICO, true, genderType::FEMALE, 1.3 ) ) ;
    catDB.push_front( new Cat( "Trin", Color::WHITE, true, genderType::FEMALE, 1.4 ) ) ;
    catDB.insert_after(catDB.get_first(), new Cat( "Chili", Color::GINGER, false,
                                                   genderType::MALE, 1.5 ) );
    assert(catDB.size() == 6);
    try{
        catDB.push_front( new Cat( "Trin", Color::WHITE, true, genderType::FEMALE, 40 ) ) ;
        assert(true == false);
    }
    catch (std::exception const& error){

    }
    try{
        catDB.push_front( new Cat( "", Color::WHITE, true, genderType::FEMALE, 40 ) ) ;
        assert(true == false);
    }
    catch (std::exception const& error){

    }

    for( Animal* pAnimal = (Animal*)catDB.get_first() ; pAnimal != nullptr ; pAnimal =
                                                                                     (Animal*)List::get_next( (Node*)pAnimal ) ) {
        std::cout << pAnimal->speak() << std::endl;
    }
    catDB.validate() ;
    catDB.dump() ;
    assert(catDB.empty() == false);
    Cat* newFirstElement = (Cat*)catDB.pop_front();
    newFirstElement->setWeight(9);
    newFirstElement->validate();
    newFirstElement->setCatFixed();
    assert(newFirstElement->getName() == "Chili");
    catDB.dump();
    std::cout << catDB.isSorted() << std::endl;
    catDB.deleteAllNodes() ;
    catDB.dump() ;
    assert(catDB.empty());
    std::cout << "Done with " << MAIN_FILE_NAME << std::endl;
    return( EXIT_SUCCESS ) ;

}


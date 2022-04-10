///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   9_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include <stdlib.h>
#include "addCats.h"
#include "deleteCats.h"
#include "reportCats.h"
#include "catDatabase.h"
#include "config.h"

#define SUCCESS true

#define STRING_FIFTY_CHARACTERS     "543290605644487098442288957842892578701236285adfad"
#define EMPTY_STRING                ""

int main() {
    std::cout << "Starting Animal Farm 2" << std::endl;
    // Generates a few cats in the database
    addCat(new Cat( "Loki", MALE, PERSIAN, 8.5)) ;
    addCat(new Cat( "Milo", MALE, MANX, 7.0)) ;
    addCat(new Cat( "Bella", FEMALE, MAINE_COON, 18.2 )) ;
    addCat(new Cat( "Kali", FEMALE, SHORTHAIR, 9.2 )) ;
    addCat(new Cat( "Trin", FEMALE, MANX, 12.2 )) ;

#ifdef DEBUG
    // Testing the addCat function validators
    try {
        addCat(new Cat(STRING_FIFTY_CHARACTERS, MALE, SHORTHAIR, 0));       // Should Fail the weight can not be 0
        assert(true==false);
    } catch (std::exception const& error){

    }
    try {
        addCat(new Cat(EMPTY_STRING, UNKNOWN_GENDER, SHORTHAIR, 10));       // Should Fail the Name is an empty string
        assert(true==false);
    } catch (std::exception const& error){

    }

    // Finding a Cat and print
    Cat* catIndex = findCatByName("Chili");
    assert(catIndex == nullptr);
    addCat(new Cat( "Chili", FEMALE, MANX, 12.2 )) ;
    catIndex = findCatByName("Chili");
    catIndex->print();

    // Update Cat testing
    assert(catIndex->setCatFixed() == SUCCESS);
    assert(catIndex->setWeight(55.5) == SUCCESS);
    assert(catIndex->setWeight(0) != SUCCESS);
    assert(catIndex->setName("LINKER") == SUCCESS);
    assert(catIndex->setName("") != SUCCESS);
    assert(catIndex->setGender(MALE) == SUCCESS);
    assert(catIndex->setGender(UNKNOWN_GENDER) != SUCCESS);
    assert(catIndex->setBreed(MANX) == SUCCESS);
    assert(catIndex->setBreed(UNKOWN_BREED) != SUCCESS);

    // Delete Cat testing
    assert(deleteCat(catIndex) == SUCCESS);

#endif

    printAllCats() ;
    Cat* kali = findCatByName( "Kali" ) ;
    assert( kali->setName("") != SUCCESS ) ; // string is empty cat name should fail
    kali->print();
    assert( kali->setName("Capulet") == SUCCESS ) ;
    assert( kali->setWeight(9.9) == SUCCESS ) ;
    assert( kali->setCatFixed() == SUCCESS ) ;
    kali->print() ;
    printAllCats() ;
    deleteAllCats() ;
    printAllCats() ;
    assert(validateDatabase()==true);
    std::cout << "Done with Animal Farm 2" << std::endl;
    return( EXIT_SUCCESS ) ;

}


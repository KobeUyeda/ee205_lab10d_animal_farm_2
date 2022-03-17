///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   16_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "addCats.h"
#include "deleteCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "catDatabase.h"
#include "config.h"

#define FAIL -1
#define SUCCESS 1

#define STRING_FIFTY_ONE_CHARACTERS "543290605644487098442288957842892578701236285adfadd"
#define STRING_FIFTY_CHARACTERS     "543290605644487098442288957842892578701236285adfad"
#define EMPTY_STRING                ""

int main() {

    // Initializes the Databse
    resetDataBase();

    // Generates a few cats in the database
    addCat( "Loki", MALE, PERSIAN, true, 8.5, BLACK, WHITE, 101 ) ;
    addCat( "Milo", MALE, MANX, true, 7.0, BLACK, RED, 102 ) ;
    addCat( "Bella", FEMALE, MAINE_COON, true, 18.2, BLACK, BLUE, 103 ) ;
    addCat( "Kali", FEMALE, SHORTHAIR, false, 9.2, BLACK, GREEN, 104 ) ;
    addCat( "Trin", FEMALE, MANX, true, 12.2, BLACK, PINK, 105 ) ;
    addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106 ) ;

#ifdef DEBUG
    // Testing the addCat function validators
      assert( addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106 ) == FAIL);                      // Should Fail Repeat Name
      assert( addCat( STRING_FIFTY_ONE_CHARACTERS, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106 ) == FAIL);  // Should Fail Name longer than 50 char by 1
      assert( addCat(STRING_FIFTY_CHARACTERS, UNKNOWN_GENDER, SHORTHAIR, false, 0, WHITE, RED, 106) == FAIL);             // Should Fail the weight can not be 0
      assert( addCat(EMPTY_STRING, UNKNOWN_GENDER, SHORTHAIR, false, 10, WHITE, RED, 106) == FAIL);                       // Should Fail the Name is an empty string
      int testCat = addCat( STRING_FIFTY_CHARACTERS, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106 );         // Should Succed Name is correct length
      assert(testCat != FAIL);
      assert(testCat < MAX_DATABASE_LENGTH);

      // Finding a Cat and print
      int catIndex = findCat(STRING_FIFTY_CHARACTERS);
      assert(catIndex != FAIL);
      printCat(catIndex);

      // Update Cat testing
      assert(fixCat(catIndex) == SUCCESS);
      assert(fixCat(-1) == FAIL);
      assert(updateCatCollar1(catIndex, RED) == SUCCESS);
      assert(updateCatCollar1(-1, RED) == FAIL);
      assert(updateCatCollar2(catIndex, BLUE) == SUCCESS);
      assert(updateCatCollar2(-1, RED) == FAIL);
      assert(updateLicense(catIndex, 1001) == SUCCESS);
      assert(updateLicense(-1, 1001) == FAIL);
      assert(updateCatWeight(catIndex, 55.5) == SUCCESS);
      assert(updateCatWeight(catIndex, 0) == FAIL);
      assert(updateCatWeight(-1, 55.5) == FAIL);
      assert(updateCatWeight(-1, 0) == FAIL);
      assert(updateCatName(catIndex, "LINKER") == SUCCESS);
      assert(updateCatName(catIndex, STRING_FIFTY_ONE_CHARACTERS) == FAIL);
      assert(updateCatName(catIndex, EMPTY_STRING) == FAIL);
      assert(updateCatName(-1, STRING_FIFTY_ONE_CHARACTERS) == FAIL);
      assert(updateCatName(-1, "BABY") == FAIL);

      // Delete Cat testing
      assert(deleteCat(-1) == FAIL);
      assert(deleteCat(catIndex) == SUCCESS);

#endif

    printAllCats() ;
    int kali = findCat( "Kali" ) ;
    assert( updateCatName( kali, "Chili" ) == FAIL ) ; // duplicate cat name should fail
    printCat( kali ) ;
    assert( updateCatName( kali, "Capulet" ) == SUCCESS ) ;
    assert( updateCatWeight( kali, 9.9 ) == SUCCESS ) ;
    assert( fixCat( kali ) == SUCCESS ) ;
    assert( updateCatCollar1( kali, GREEN ) == SUCCESS ) ;
    assert( updateCatCollar2( kali, GREEN ) == SUCCESS ) ;
    assert( updateLicense( kali, 201 ) == SUCCESS ) ;
    printCat( kali ) ;
    printAllCats() ;
    deleteAllCats() ;
    printAllCats() ;
    printf( "Done with %s\n", MAIN_FILE_NAME ) ;
    return( EXIT_SUCCESS ) ;

}


///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file config.h
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   16_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#define DATABASE_FILE_NAME    "catDatabase.cpp"
#define CAT_FILE_NAME         "cat.cpp"
#define ADD_CATS_FILE_NAME    "addCats.cpp"
#define REPORT_CATS_FILE_NAME "repoprtCats.cpp"
#define UPDATE_CATS_FILE_NAME "updateCats.cpp"
#define DELETE_CATS_FILE_NAME "deleteCats.cpp"
#define MAIN_FILE_NAME        "main.cpp"

enum color{BLACK, WHITE, RED, BLUE, GREEN, PINK};
enum genderType{UNKNOWN_GENDER, MALE, FEMALE};
enum breedType{UNKOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX};
typedef float Weight;


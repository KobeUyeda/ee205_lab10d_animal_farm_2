cmake_minimum_required(VERSION 3.22)
project(ee205_lab_08d_animal_farm_2)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE off)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

add_executable(ee205_lab_08d_animal_farm_1_to_clion main.cpp addCats.cpp addCats.h catDatabase.cpp catDatabase.h config.h deleteCats.cpp deleteCats.h animal.h animal.cpp Cat.cpp Cat.h)

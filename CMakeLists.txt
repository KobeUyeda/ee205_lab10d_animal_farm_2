cmake_minimum_required(VERSION 3.22)
project(ee205_lab_08d_animal_farm_3)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE off)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

add_executable(ee205_lab_08d_animal_farm_1_to_clion main.cpp config.h animal.h node.h node.cpp animal.cpp Cat.cpp Cat.h mammal.cpp mammal.h Gender.cpp Gender.h Color.cpp Color.h list.cpp list.h singleLinkedList.cpp singleLinkedList.h weight.cpp weight.h)

///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file list.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////



#include "list.h"
#include "config.h"
#include <iostream>
#include <cassert>

bool List::empty () const noexcept{
    if(List::head == nullptr){
        return true;
    }
    return false;
}
unsigned int List::size () const noexcept{
    return List::count;
}
bool List::isIn (Node *aNode) const{
    for(Node* catPointerIterator = List::head; catPointerIterator != nullptr; catPointerIterator=catPointerIterator->next){
        if (aNode == catPointerIterator){
            return true;
        }
    }
#ifdef DEBUG
    std::cout << LIST_OBJECT << ": The cat Pointer does not exist with in the database " << std::endl;
#endif
    return false;
}
bool List::isSorted() const noexcept{
    Node* iterateThroughCat = List::head;
    while(iterateThroughCat != nullptr){
        if(!iterateThroughCat->operator>(*iterateThroughCat->next)){
            return false;
        }
        iterateThroughCat = iterateThroughCat->next;
    }
    return true;
}
Node* List::get_first() const noexcept{
    return List::head;
}
void List::deleteAllNodes () noexcept{
    Node* iterateThroughCat = List::head;
    while(iterateThroughCat != nullptr){
        if(iterateThroughCat == List::head){
            List::head = List::head->next;
            operator delete(iterateThroughCat);
            List::count--;
            #ifdef DEBUG
                std::cout << LIST_OBJECT << ": The cat Pointer has been deleted from the database " << std::endl;
            #endif
        }
        iterateThroughCat = List::head;
    }
    #ifdef DEBUG
        std::cout << LIST_OBJECT << ": The whole database has been deleted " << std::endl;
    #endif
}
Node* List::get_next(const Node *currentNode){
    return currentNode->next;
}

///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file singleLinkedList.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////



#include "singleLinkedList.h"
#include "config.h"
#include <cassert>
#include <stdexcept>
#include <iostream>

SinglyLinkedList::SinglyLinkedList() = default;
void SinglyLinkedList::push_front(Node *newNode) {
    assert(newNode != nullptr);
    if (!newNode->validate()){
        throw std::logic_error(SINGLE_LINKED_LIST ": The cat pointer given has invalid data");
    }

    if (isIn(newNode)){
        throw std::logic_error(SINGLE_LINKED_LIST ": This pointer already exist within the database");
    }

    assert(validate());

    newNode->next = SinglyLinkedList::head;
    SinglyLinkedList::head = newNode;
    SinglyLinkedList::count++;

    assert(validate());

    #ifdef DEBUG
       std::cout << SINGLE_LINKED_LIST << ": Node " << newNode << " was just added to the database" << std::endl;
    #endif

}

Node* SinglyLinkedList::pop_front() noexcept {
    if(List::head != nullptr) {
        Node *deleteValue = List::head;
        List::head = List::head->next;
        operator delete(deleteValue);
        List::count--;
        #ifdef DEBUG
            std::cout << SINGLE_LINKED_LIST << ": The cat Pointer has been deleted from the database " << std::endl;
        #endif
    }
    return List::head;
}
void SinglyLinkedList::insert_after(Node *currentNode, Node* newNode) {

    assert(newNode != nullptr);
    if (!newNode->validate()){
        throw std::logic_error(SINGLE_LINKED_LIST ": The cat pointer given has invalid data");
    }

    if (isIn(newNode)){
        throw std::logic_error(SINGLE_LINKED_LIST ": This pointer already exist within the database");
    }

    assert(validate());

    newNode->next = currentNode->next;
    currentNode->next = newNode;
    SinglyLinkedList::count++;

    assert(validate());

    #ifdef DEBUG
        std::cout << SINGLE_LINKED_LIST << ": Node " << newNode << " was just added to the database" << std::endl;
    #endif

}
bool SinglyLinkedList::validate() const noexcept {
    Node* iterateThroughCat = SinglyLinkedList::head;
    while(iterateThroughCat != nullptr){
        if(!iterateThroughCat->validate()){
            return false;
        }
        iterateThroughCat = iterateThroughCat->next;
    }
    #ifdef DEBUG
        std::cout << SINGLE_LINKED_LIST << ": The database is valid " << std::endl;
    #endif
    return true;
}

void SinglyLinkedList::dump() const noexcept {
    Node* iterateThroughCat = SinglyLinkedList::head;
    while(iterateThroughCat != nullptr){
        iterateThroughCat->dump();
        iterateThroughCat = iterateThroughCat->next;
    }
    #ifdef DEBUG
        std::cout << SINGLE_LINKED_LIST << ": Node is at the end" << std::endl;
    #endif
}
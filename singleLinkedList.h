///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file singleLinkedList.h
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "list.h"
#include "node.h"


class SinglyLinkedList: public List {
public:
    SinglyLinkedList();
public:
    void push_front(Node* newNode);
    Node* pop_front() noexcept override;

    void insert_after(Node* currentNode, Node* newNode);

    void dump() const noexcept override;
    bool validate() const noexcept override;
};


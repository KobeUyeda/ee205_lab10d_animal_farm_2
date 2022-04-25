///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file node.h
/// @version 3.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

class Node{
    friend class List;
    friend class SinglyLinkedList;
protected:
    Node *next = nullptr;

protected:
    static bool compareByAddress(const Node *node1, const Node *node2);

public:
    virtual void dump () const noexcept;
    virtual bool validate() const noexcept;
    virtual bool operator>(const Node &rightSide) const noexcept;
};


///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file node.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "node.h"
#include "config.h"
#include <iostream>
#include <iomanip>
#define FORMAT_LINE(className, member) std::cout << std::setw(8) << (className) << std::setw(20) << (member) << std::setw(52)

bool Node::compareByAddress(const Node *node1, const Node *node2) {
    return node1 > node2;
}

bool Node::validate() const noexcept{
    if(next->next == next){
        std::cout << NODE_OBJECT << ": This is recursive the node is pointing back to itself, breaks code" << std::endl;
        return false;
    }
    return true;
}

bool Node::operator>(const Node &rightSide) const noexcept {
    return compareByAddress(this, &rightSide);
}

void Node::dump() const noexcept {
    std::cout << std::setw(80) << std::setfill('=') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::left;
    std::cout << std::boolalpha;

    FORMAT_LINE("Node", "this") << this << std::endl;
    FORMAT_LINE("Node", "next") << next << std::endl;

}

/*
 * VTABLE
 * Just some experiments with vtables, vpointers, etc
 *
 * Stefan Wong 2020
 */


#include <iostream>
#include "vtable.hpp"


Base::~Base()
{
    std::cout << "[" << __func__ << "] destroying Base" << std::endl;
}


Derived::~Derived()
{
    std::cout << "[" << __func__ << "] destroying Derived" << std::endl;
}

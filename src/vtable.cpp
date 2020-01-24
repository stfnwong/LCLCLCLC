/*
 * VTABLE
 * Just some experiments with vtables, vpointers, etc
 *
 * Stefan Wong 2020
 */


#include <iostream>
#include "vtable.hpp"


// Classes that don't correctly implement virtual dtors
// ======== BASE ======== //
BaseNotVirtual::~BaseNotVirtual()
{
    std::cout << "[" << __func__ << "] destroying BaseNotVirtual" << std::endl;
}

// ======== DERIVED ======== //
DerivedNotVirtual::DerivedNotVirtual(int num)
{
    this->some_number = new int(num);
}

DerivedNotVirtual::~DerivedNotVirtual()
{
    std::cout << "[" << __func__ << "] destroying DerivedNotVirtual" << std::endl;
    delete this->some_number;
}

// Classes that do correctly implement virtual dtors
BaseVirtual::~BaseVirtual()
{
    std::cout << "[" << __func__ << "] destroying BaseVirtual" << std::endl;
}

DerivedVirtual::DerivedVirtual(int num)
{
    this->some_number = new int(num);
}

DerivedVirtual::~DerivedVirtual()
{
    std::cout << "[" << __func__ << "] destroying DerivedVirtual" << std::endl;
    delete this->some_number;
}

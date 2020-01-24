/*
 * VTABLE
 * Just some experiments with vtables, vpointers, etc
 *
 * Stefan Wong 2020
 */

#ifndef __LC_VTABLE_HPP
#define __LC_VTABLE_HPP


// Some simple classes for showing dtor order
class Base
{
    public:
        ~Base();
};


class Derived : public Base
{
    public:
        ~Derived();
};



#endif /*__LC_VTABLE_HPP*/

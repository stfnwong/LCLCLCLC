/*
 * VTABLE
 * Just some experiments with vtables, vpointers, etc
 *
 * Stefan Wong 2020
 */

#ifndef __LC_VTABLE_HPP
#define __LC_VTABLE_HPP


// Some simple classes for showing dtor order
// Below: classes that don't implement virtual dtor correctly
class BaseNotVirtual
{
    public:
        ~BaseNotVirtual();
};


class DerivedNotVirtual : public BaseNotVirtual
{
    int* some_number;

    public:
        DerivedNotVirtual(int num);
        ~DerivedNotVirtual();
};



// Below: classes that do implement virtual dtor correctly.
class BaseVirtual
{
    public:
        virtual ~BaseVirtual();
};

class DerivedVirtual : public BaseVirtual
{
    int* some_number;

    public:
        DerivedVirtual(int num);
        ~DerivedVirtual();
};



#endif /*__LC_VTABLE_HPP*/

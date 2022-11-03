/*
 * UNIQUE_PTR
 * May as well try to implement the other major smart pointer 
 * as well.
 *
 * Stefan Wong 2020
 */

#ifndef __LC_UNIQUE_PTR
#define __LC_UNIQUE_PTR

#include <algorithm>

/*
 * UniquePtr
 * A basic implementation of a unique_ptr. It goes
 * without saying that this implementation is going
 * to be less comprehesive than std::unique_ptr
 */
template <typename T> class UniquePtr
{
    T* raw_ptr;

    public:
        UniquePtr() : raw_ptr(nullptr) {} 
        UniquePtr(T* ptr) : raw_ptr(ptr) {} 
        UniquePtr(UniquePtr&& that) : raw_ptr(std::move(that)) {} 
        UniquePtr(const UniquePtr<T>& that) = delete;   // don't allow copy construction
        ~UniquePtr();

        // operators 
        bool operator==(const UniquePtr<T>& that) const noexcept;
        bool operator!=(const UniquePtr<T>& that) const noexcept;
        T* operator->(void);
        T& operator*(void);

        // Assignment 
        UniquePtr<T>& operator=(UniquePtr<T>&& that) noexcept;

        // getters 
        bool empty(void) const noexcept;
};


// dtor
template <typename T> UniquePtr<T>::~UniquePtr()
{
    delete this->raw_ptr;
}

// operators
template <typename T> UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& that) noexcept
{
    if(this->raw_ptr == that.raw_ptr)
        return *this;

    this->raw_ptr = std::move(that.raw_ptr);
    that.raw_ptr = nullptr;

    return *this;
}

// Equality
template <typename T> bool UniquePtr<T>::operator==(const UniquePtr<T>& that) const noexcept
{
    return (this->raw_ptr == that.raw_ptr) ? true : false;
}

// Inequality
template <typename T> bool UniquePtr<T>::operator!=(const UniquePtr<T>& that) const noexcept 
{
    return !(*this == that);
}

// Dereference member
template <typename T> T* UniquePtr<T>::operator->(void) 
{
    return this->raw_ptr;
}

// Dereference 
template <typename T> T& UniquePtr<T>::operator*(void)
{
    return *this->raw_ptr;
}

// Returns true if there is a reference here
template <typename T> bool UniquePtr<T>::empty(void) const noexcept 
{
    return (this->raw_ptr == nullptr) ? true : false;
}



#endif /*__LC_UNIQUE_PTR*/

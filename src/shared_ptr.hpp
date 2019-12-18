/*
 * SHARED_PTR
 * Got asked this and died. Lets try to implement it here.
 *
 * Stefan Wong 2019
 */

#ifndef __LC_SHARED_PTR
#define __LC_SHARED_PTR

/*
 * SharedPtr
 */
template <typename T> class SharedPtr
{
    int *num_ref;
    T   *ptr;

    public:
        SharedPtr();
        SharedPtr(T* ref);
        SharedPtr(const SharedPtr<T>& that);    // copy ctor
        ~SharedPtr();

    // operators 
    public:
        bool operator==(const SharedPtr<T>& that) const;
        bool operator!=(const SharedPtr<T>& that) const;

    // assignment
    //public:
    //    SharedPtr<T>& operator=(const SharedPtr<T>& that) const;

    // status 
    public:
        int numRef(void) const;
        T*  get(void) const;
};


// base ctor
template <typename T> SharedPtr<T>::SharedPtr() 
{
    this->num_ref = new int(0);
    this->ptr     = nullptr;
}

// new value ctor
template <typename T> SharedPtr<T>::SharedPtr(T* ref)
{
    this->num_ref = new int(1);
    this->ptr = ref;
}

// copy ctor
template <typename T> SharedPtr<T>::SharedPtr(const SharedPtr<T>& that)
{
    this->ptr     = that.ptr;
    this->num_ref = that.num_ref;
    (*this->num_ref) = (*this->num_ref) + 1;
}

// dtor 
template <typename T> SharedPtr<T>::~SharedPtr()
{
    (*this->num_ref)--;
    
    // clean this up if its the last reference
    if((*this->num_ref) == 0)
    {
        std::cout << "[" << __func__ << "] cleaning memory..." << std::endl;
        delete this->ptr;
        delete this->num_ref;
    }
}

// ======== OPERATORS ======== //
template <typename T> bool SharedPtr<T>::operator==(const SharedPtr<T>& that) const
{
    if(this->ptr == that.ptr)
        return true;
    return false;
}

template <typename T> bool SharedPtr<T>::operator!=(const SharedPtr<T>& that) const
{
    return !(*this == that);
}

// ==== Status ==== //
// TODO : what is the benefit of returning a const int?
template <typename T> int SharedPtr<T>::numRef(void) const
{
    return *this->num_ref;
}

template <typename T> T* SharedPtr<T>::get(void) const
{
    return this->ptr;
}

#endif /*__LC_SHARED_PTR*/

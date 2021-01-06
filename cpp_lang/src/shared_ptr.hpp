/*
 * SHARED_PTR
 * Got asked this and died. Lets try to implement it here.
 *
 * Stefan Wong 2019
 */

#ifndef __LC_SHARED_PTR
#define __LC_SHARED_PTR

/*
 * SharedPtrIntrusive
 */
template <typename T> class SharedPtrIntrusive
{
    int *num_ref;
    T   *raw_ptr;

    public:
        SharedPtrIntrusive();
        SharedPtrIntrusive(T* ref);
        SharedPtrIntrusive(const SharedPtrIntrusive<T>& that);    // copy ctor
        SharedPtrIntrusive(SharedPtrIntrusive<T>&& that);  // move ctor
        ~SharedPtrIntrusive();

    // operators 
    public:
        bool operator==(const SharedPtrIntrusive<T>& that) const noexcept;
        bool operator!=(const SharedPtrIntrusive<T>& that) const noexcept;

        // referencing operators
        T* operator->(void);
        T& operator*(void);

    // assignment
    //public:
    //    SharedPtrIntrusive<T>& operator=(const SharedPtrIntrusive<T>& that) const;

    // status 
    public:
        bool empty(void) const noexcept;        // TODO: getting non-class type error here...
        int numRef(void) const;
        T*  get(void) const;
};


// base ctor
template <typename T> SharedPtrIntrusive<T>::SharedPtrIntrusive() 
{
    this->num_ref = new int(0);
    this->raw_ptr = nullptr;
}

// new value ctor
template <typename T> SharedPtrIntrusive<T>::SharedPtrIntrusive(T* ref)
{
    this->num_ref = new int(1);
    this->raw_ptr = ref;
}

// copy ctor
template <typename T> SharedPtrIntrusive<T>::SharedPtrIntrusive(const SharedPtrIntrusive<T>& that)
{
    this->raw_ptr   = that.raw_ptr;
    this->num_ref    = that.num_ref;
    (*this->num_ref)++; 
}

// move ctor
template <typename T> SharedPtrIntrusive<T>::SharedPtrIntrusive(SharedPtrIntrusive<T>&& that)
{
    // TODO : is this sufficient?
    this->raw_ptr = std::move(that.raw_ptr);
    this->num_ref = std::move(that.num_ref);
    that.raw_ptr = nullptr;
}

// dtor 
template <typename T> SharedPtrIntrusive<T>::~SharedPtrIntrusive()
{
    (*this->num_ref)--;
    
    // clean this up if its the last reference
    if((*this->num_ref) == 0)
    {
        delete this->raw_ptr;
        delete this->num_ref;
    }
}

// ======== OPERATORS ======== //
// Equality
template <typename T> bool SharedPtrIntrusive<T>::operator==(const SharedPtrIntrusive<T>& that) const noexcept
{
    if(this->raw_ptr == that.raw_ptr)
        return true;
    return false;
}

// Inequality
template <typename T> bool SharedPtrIntrusive<T>::operator!=(const SharedPtrIntrusive<T>& that) const noexcept
{
    return !(*this == that);
}

// Reference to member
template <typename T> T* SharedPtrIntrusive<T>::operator->(void) 
{
    return this->raw_ptr;
}

// Dereference member
template <typename T> T& SharedPtrIntrusive<T>::operator*(void)
{
    return *this->raw_ptr;
}

// ==== Status ==== //
// TODO : what is the benefit of returning a const int?
template <typename T> int SharedPtrIntrusive<T>::numRef(void) const
{
    return *this->num_ref;
}

template <typename T> T* SharedPtrIntrusive<T>::get(void) const
{
    return this->raw_ptr;
}

// Has this been assigned a reference?
template <typename T> bool SharedPtrIntrusive<T>::empty(void) const noexcept
{
    return (this->raw_ptr == nullptr) ? true : false;
}

/*
 * Reference count structure
 */
struct RefCount
{
    int count;

    public:
        RefCount() : count(1) {}
};

/*
 * SharedPtr
 * Non-instrusive shared pointer
 */
template <typename T> class SharedPtr
{
    private:
        T* raw_ptr;
        RefCount* ref_count;

    public:
        SharedPtr(T* ptr);
        SharedPtr(const SharedPtr<T>& that);
        ~SharedPtr();

    // operators
    public:
        bool operator==(const SharedPtr<T>& that) const;
        bool operator!=(const SharedPtr<T>& that) const;
        T*   operator->(void);
        T&   operator*(void);

        // assignment

    // Getters / Setters
    public:
        bool empty(void) const noexcept;
        int numRef(void) const;
};

// regular ctor
template <typename T> SharedPtr<T>::SharedPtr(T* ptr) : raw_ptr(ptr), ref_count(new RefCount) {}

// copy ctor
template <typename T> SharedPtr<T>::SharedPtr(const SharedPtr<T>& that) : raw_ptr(that.raw_ptr), ref_count(that.ref_count)
{
    this->ref_count->count++;
}

// dtor
template <typename T> SharedPtr<T>::~SharedPtr()
{
    --this->ref_count->count;

    if(this->ref_count->count == 0)
    {
        delete this->ref_count;
        delete this->raw_ptr;
    }
}

// Operators 
// Equality
template <typename T> bool SharedPtr<T>::operator==(const SharedPtr<T>& that) const
{
    if(this->raw_ptr == that.raw_ptr)
        return true;
    return false;
}

// Inequality
template <typename T> bool SharedPtr<T>::operator!=(const SharedPtr<T>& that) const
{
    return !(*this == that);
}

template <typename T> T* SharedPtr<T>::operator->(void) 
{
    return this->raw_ptr;
}

template <typename T> T& SharedPtr<T>::operator*(void)
{
    return *this->raw_ptr;
}

// num_ref()
template <typename T> int SharedPtr<T>::numRef(void) const
{
    return this->ref_count->count;
}

template <typename T> bool SharedPtr<T>::empty(void) const noexcept
{
    return (this->raw_ptr == nullptr) ? true : false;
}

#endif /*__LC_SHARED_PTR*/

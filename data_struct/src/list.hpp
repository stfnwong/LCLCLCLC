/*
 * LIST
 * Implementations of list structures. Never use these for any actual purpose, i
 * because they are shit.
 */

#ifndef __LC_LIST_HPP
#define  __LC_LIST_HPP

#include <memory>
#include <sstream>
#include <string>



template <typename T> struct ListNode
{
    T value;
    ListNode<T>* next;
    ListNode<T>* prev;

    public:
        ListNode(const T& val) :
            value(val), next(nullptr), prev(nullptr) {} 
        // copy ctor
        ListNode(const ListNode& that) :
            value(that.value), next(that.next), prev(that.prev) {} 

        // Should the dtor be here or in the parent? I think in real code 
        // this should be a private struct of the LinkedList class
        ~ListNode()
        {
            delete this->next;
            delete this->prev;
        }

        // Provide some compare operators
        bool operator==(const ListNode& that) const
        {
            if(this->value != that.value)
                return false;
            if(this->next != that.next)
                return false;
            if(this->prev != that.prev)
                return false;

            return true;
        }

        bool operator!=(const ListNode& that) const
        {
            return !(*this == that);
        }


        /*
         * Provide a string representation of this node.
         */
        std::string to_string(void) const 
        {
            std::ostringstream oss;

            oss << "V: [" << this->value << "]";
            if(this->next != nullptr)
                oss << " -> ";

            return oss.str();
        }

};


/*
 * LIST
 * This wraps some ListNode objects
 */
template <typename T> struct LinkedList
{
    std::unique_ptr<ListNode<T>> head;

    public:
        LinkedList() : head(nullptr) {}

        //T get(const unsigned idx) const
        //{
        //    unsigned cur_idx = 0;
        //    std::unique_ptr<ListNode<T>>
        //    
        //}
};



/*
 * Because this is a toy list that we never want to use for any real task, it would 
 * be handy to provide a constructor that accepts a vector of elements and 
 * constructs from them one of these linked lists
 */



#endif /*__LC_LIST_HPP*/

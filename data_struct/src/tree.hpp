/*
 * TREE
 * Various implementations of Trees 
 */


#ifndef __LC_TREE_HPP
#define __LC_TREE_HPP

#include <string>
#include <sstream>
#include <vector>

/*
 * ArrayTree
 * Tree implemented as a vector of nodes
 */
template <class T> class ArrayTree
{
    T elem;
    std::vector<ArrayTree> children;

    public:
        ArrayTree() {} 
        ArrayTree(const T& v)
        {
            this->elem = v;
        }

        void add_child(const T& v)
        {
            this->children.push_back(ArrayTree(v));
        }

        void remove_at(const unsigned idx)
        {
            this->children.erase(this->children.begin() + idx);
        }

        void set(const T& v)
        {
            this->elem = v;
        }

        T get(void) const 
        {
            return this->elem;
        }

        unsigned num_children(void) const
        {
            return this->children.size();
        }



        //std::string ToString(void) const 
        //{
        //    std::ostringstream oss;

        //    return oss.str();
        //}

};




#endif /*__LC_TREE_HPP*/


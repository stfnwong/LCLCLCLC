/*
 * Simple program to check how the capacity of the vector grows 
 * Stefan Wong 2019
 */

#include <iostream>
#include <vector>


int main(int argc, char *argv[])
{
    std::vector<int> vec;     // new vector, default size
    unsigned int max_vector_size = 256;

    std::cout << "Initial vector size : " << vec.size() << std::endl;
    for(unsigned int v = 0; v < max_vector_size; ++v)
    {
        vec.push_back(v);
        std::cout << "iteration " << v << ": size=" 
            << vec.size() << " cap=" << vec.capacity() << std::endl;
    }

    return 0;
}

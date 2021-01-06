/*
 * DISTANCE
 * Stuff for integer distance questions
 *
 * Stefan Wong 2019 
 */

#include <unordered_map>
#include "distance.hpp"

/*
 * occurrence_dist_brute()
 * Brute-force implementation of occurrence distance
 */
int occurrence_dist_brute(const std::vector<int>& array, int target_elem, bool verbose)
{
    int max_dist = -1;
    int dist;

    for(unsigned int i = 0; i < array.size(); ++i)
    {
        for(unsigned int j = 0; j < array.size(); ++j)
        {
            if((array[i] == target_elem) && (array[i] == array[j]))
            {
                dist = j - i;
                if(dist > max_dist)
                {
                    max_dist = dist;
                    // TODO : save idx here later...
                }
            }
        }
    }

    return max_dist;
}


/*
 * occurrence_dist_hash()
 * Hash map implementation of occurrence distance
 */
int occurrence_dist_hash(const std::vector<int>& array, int target_elem, bool verbose)
{
    int max_dist = -1;
    int dist;

    std::unordered_map<int, int> dist_map;

    for(unsigned int i = 0; i < array.size(); ++i)
    {
        if(array[i] == target_elem)
        {
            if(dist_map.count(array[i]))
            {
                dist = i - dist_map[array[i]];
                if(dist > max_dist)
                    max_dist = dist;
            }
            else
                dist_map[array[i]] = i;
        }
    }

    return max_dist;
}

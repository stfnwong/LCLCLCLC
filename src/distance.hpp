/*
 * DISTANCE
 * Stuff for integer distance questions
 *
 * Stefan Wong 2019 
 */

#ifndef __DISTANCE_HPP
#define __DISTANCE_HPP

#include <vector>


// TODO : could use a mutable std::array<int> to pass back the c
int occurrence_dist_brute(const std::vector<int>& array, int target_elem, bool verbose = false);

int occurrence_dist_hash(const std::vector<int>& array, int target_elem, bool verbose = false);


#endif /*__DISTANCE_HPP*/

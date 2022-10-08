/* TEST_DISTANCE
 * Tests for distance stuff
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <vector>
#include "distance.hpp"


std::vector<int> test_array = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};

int expected_dist_1 = 2;
int expected_dist_2 = 10;
int expected_dist_4 = 5;


TEST_CASE("test_occurrence_dist_brute", "leetcode")
{
    int dist_1;
    int dist_2;
    int dist_4;

    dist_1 = occurrence_dist_brute(test_array, 1);
    REQUIRE(expected_dist_1 == dist_1);
    dist_2 = occurrence_dist_brute(test_array, 2);
    REQUIRE(expected_dist_2 == dist_2);
    dist_4 = occurrence_dist_brute(test_array, 4);
    REQUIRE(expected_dist_4 == dist_4);

}

TEST_CASE("test_occurrence_dist_hash", "leetcode")
{
    int dist_1;
    int dist_2;
    int dist_4;

    dist_1 = occurrence_dist_hash(test_array, 1);
    REQUIRE(expected_dist_1 ==  dist_1);
    dist_2 = occurrence_dist_hash(test_array, 2);
    REQUIRE(expected_dist_2 ==  dist_2);
    dist_4 = occurrence_dist_hash(test_array, 4);
    REQUIRE(expected_dist_4 ==  dist_4);
}

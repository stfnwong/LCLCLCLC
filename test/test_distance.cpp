/* TEST_DISTANCE
 * Tests for distance stuff
 *
 * Stefan Wong 2019
 */

#include <vector>
#include <gtest/gtest.h>
#include "distance.hpp"





class TestDistance : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}

    public:
        std::vector<int> test_array = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
        int expected_dist_1 = 2;
        int expected_dist_2 = 10;
        int expected_dist_4 = 5;
};


TEST_F(TestDistance, test_occurrence_dist_brute)
{
    int dist_1;
    int dist_2;
    int dist_4;

    dist_1 = occurrence_dist_brute(this->test_array, 1);
    ASSERT_EQ(this->expected_dist_1, dist_1);
    dist_2 = occurrence_dist_brute(this->test_array, 2);
    ASSERT_EQ(this->expected_dist_2, dist_2);
    dist_4 = occurrence_dist_brute(this->test_array, 4);
    ASSERT_EQ(this->expected_dist_4, dist_4);

}

TEST_F(TestDistance, test_occurrence_dist_hash)
{
    int dist_1;
    int dist_2;
    int dist_4;

    dist_1 = occurrence_dist_hash(this->test_array, 1);
    ASSERT_EQ(this->expected_dist_1, dist_1);
    dist_2 = occurrence_dist_hash(this->test_array, 2);
    ASSERT_EQ(this->expected_dist_2, dist_2);
    dist_4 = occurrence_dist_hash(this->test_array, 4);
    ASSERT_EQ(this->expected_dist_4, dist_4);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

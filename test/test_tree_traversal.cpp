/* TEST_TRAVERSE_TREE 
 * Test LeetCode tree traversal
 *
 * Stefan Wong 2019
 */

#include <vector>
#include <string>
#include <gtest/gtest.h>
#include "tree.hpp"


class TestTraverseTree : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}
};




TEST_F(TestTraverseTree, test_inorder_traversal)
{

}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



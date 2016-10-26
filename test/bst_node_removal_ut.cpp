//
//  bst_node_removal_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-10-26.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

//#include "bst.cpp"
#include "bst.hpp"
#include "gtest/gtest.h"

class BSTNodeRemoval : public ::testing::Test
{
public:
    virtual void SetUp()
    {
        tree.root->data = 7;
        tree.Add(3);
        tree.Add(11);
        tree.Add(1);
        tree.Add(5);
        tree.Add(9);
        tree.Add(13);
        //tree.Print();
        /*
         //
         //        ________[7]_______
         //       /                  \
         //     _[3]__            __[11]_
         //    /      \          /       \
         //  [1]      [5]      [9]       [13]
         //
         //*/
    }
    virtual void TearDown(){};
    Tree tree;
};

TEST_F(BSTNodeRemoval, RemoveNodeWithNoChildren)
{
    ASSERT_TRUE(tree.Find(1));
    ASSERT_TRUE(tree.Remove(1));
    ASSERT_FALSE(tree.Find(1));
}

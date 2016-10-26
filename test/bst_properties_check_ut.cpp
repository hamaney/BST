//
//  bst_properties_check_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-10-25.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

//#include "bst.cpp"
#include "bst.hpp"
#include "gtest/gtest.h"

class BSTNodeProperties : public ::testing::Test
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
TEST_F(BSTNodeProperties, CheckIfLeafNode)
{
    ASSERT_TRUE(tree.isLeaf(1));
    ASSERT_TRUE(tree.isLeaf(5));
    ASSERT_TRUE(tree.isLeaf(9));
    ASSERT_TRUE(tree.isLeaf(13));
    ASSERT_FALSE(tree.isLeaf(3));
    ASSERT_FALSE(tree.isLeaf(11));
    ASSERT_FALSE(tree.isLeaf(7));
    ASSERT_FALSE(tree.isLeaf(99));
    ASSERT_FALSE(tree.isLeaf(-99));
}
TEST_F(BSTNodeProperties, CheckIfNodeHasTwoChildren)
{
    ASSERT_TRUE(tree.hasTwoChildren(7));
    ASSERT_TRUE(tree.hasTwoChildren(3));
    ASSERT_FALSE(tree.hasTwoChildren(1));
    ASSERT_FALSE(tree.hasTwoChildren(99));
    ASSERT_FALSE(tree.hasTwoChildren(-99));
}
TEST_F(BSTNodeProperties, CheckIfNodeHasOnlyLeftChild)
{
    ASSERT_TRUE(tree.Add(0));
    ASSERT_TRUE(tree.Add(6));
    ASSERT_TRUE(tree.hasOnlyLeftChild(1));
    ASSERT_FALSE(tree.hasOnlyLeftChild(5));
    ASSERT_FALSE(tree.hasOnlyLeftChild(9));
    ASSERT_FALSE(tree.hasOnlyLeftChild(11));
    ASSERT_FALSE(tree.hasOnlyLeftChild(99));
    ASSERT_FALSE(tree.hasOnlyLeftChild(-99));
}
TEST_F(BSTNodeProperties, CheckIfNodeHasOnlyRightChild)
{
    ASSERT_TRUE(tree.Add(2));
    ASSERT_TRUE(tree.Add(4));
    ASSERT_TRUE(tree.hasOnlyRightChild(1));
    ASSERT_FALSE(tree.hasOnlyRightChild(5));
    ASSERT_FALSE(tree.hasOnlyRightChild(9));
    ASSERT_FALSE(tree.hasOnlyRightChild(11));
    ASSERT_FALSE(tree.hasOnlyRightChild(99));
    ASSERT_FALSE(tree.hasOnlyRightChild(-99));
}
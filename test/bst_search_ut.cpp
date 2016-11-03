//
//  bst_search_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-10-25.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

//#include "bst.cpp"
#include "bst.hpp"
#include "gtest/gtest.h"

class BSTSearching : public ::testing::Test
{
  public:
    virtual void SetUp()
    {
        tree.root->data = 4;
        tree.Add(2);
        tree.Add(6);
        tree.Add(1);
        tree.Add(3);
        tree.Add(5);
        tree.Add(7);
        //        ________[4]_______
        //       /                  \
        //     _[2]__            __[6]_
        //    /      \          /      \
        //  [1]      [3]      [5]      [7]
        //
    }
    virtual void TearDown(){};
    Tree tree;
};

TEST_F(BSTSearching, FindingAValueInTree)
{
    ASSERT_EQ(tree.Find(4), tree.root.get());
    ASSERT_EQ(tree.Find(2), tree.root->left.get());
    ASSERT_EQ(tree.Find(6), tree.root->right.get());
    ASSERT_EQ(tree.Find(1), tree.root->left->left.get());
    ASSERT_EQ(tree.Find(3), tree.root->left->right.get());
    ASSERT_EQ(tree.Find(5), tree.root->right->left.get());
    ASSERT_EQ(tree.Find(7), tree.root->right->right.get());
}

TEST_F(BSTSearching, CheckingIfValueExistsInTree)
{
    ASSERT_TRUE(tree.Find(1));
    ASSERT_TRUE(tree.Find(4));
    ASSERT_TRUE(tree.Find(5));
    ASSERT_TRUE(tree.Find(6));

    ASSERT_FALSE(tree.Find(-100));
    ASSERT_FALSE(tree.Find(100));
}

TEST_F(BSTSearching, FindingTheMinValueInTree)
{
    ASSERT_EQ(tree.Min(), 1);
    ASSERT_TRUE(tree.Remove(1));
    ASSERT_EQ(tree.Min(), 2);
    ASSERT_TRUE(tree.Remove(3));
    ASSERT_EQ(tree.Min(), 2);
    ASSERT_TRUE(tree.Remove(2));
    ASSERT_EQ(tree.Min(), 4);
    ASSERT_TRUE(tree.Add(0));
    ASSERT_EQ(tree.Min(), 0);
}

TEST_F(BSTSearching, FindingTheMaxValueInTree)
{
    ASSERT_EQ(tree.Max(), 7);
    ASSERT_TRUE(tree.Remove(7));
    ASSERT_EQ(tree.Max(), 6);
    ASSERT_TRUE(tree.Remove(6));
    ASSERT_EQ(tree.Max(), 5);
    ASSERT_TRUE(tree.Remove(5));
    ASSERT_EQ(tree.Max(), 4);
    ASSERT_TRUE(tree.Add(99));
    ASSERT_EQ(tree.Max(), 99);
}

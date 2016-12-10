//
//  bst_search_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-10-25.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include <vector>
#include "bst.hpp"
#include "gtest/gtest.h"

using namespace BSTNS;

class BSTSearching : public ::testing::Test {
 public:
  virtual void SetUp() {
      
      tree.Insert({4,2,6,1,3,5,7});
    /*        ________[4]_______
    //       /                  \
    //     _[2]__            __[6]_
    //    /      \          /      \
    //  [1]      [3]      [5]      [7]
    */
  }
  virtual void TearDown(){};
  BST tree;
};

TEST_F(BSTSearching, FindingAValueInTree) {
  ASSERT_EQ(tree.Find(4), tree.root.get());
  ASSERT_EQ(tree.Find(2), tree.root->left.get());
  ASSERT_EQ(tree.Find(6), tree.root->right.get());
  ASSERT_EQ(tree.Find(1), tree.root->left->left.get());
  ASSERT_EQ(tree.Find(3), tree.root->left->right.get());
  ASSERT_EQ(tree.Find(5), tree.root->right->left.get());
  ASSERT_EQ(tree.Find(7), tree.root->right->right.get());
}

TEST_F(BSTSearching, CheckingIfValueExistsInTree) {
  ASSERT_TRUE(tree.Find(1));
  ASSERT_TRUE(tree.Find(4));
  ASSERT_TRUE(tree.Find(5));
  ASSERT_TRUE(tree.Find(6));

  ASSERT_FALSE(tree.Find(-100));
  ASSERT_FALSE(tree.Find(100));
}

TEST_F(BSTSearching, FindingTheMinValueInTree) {
  ASSERT_EQ(tree.GetMin(), 1);
  ASSERT_TRUE(tree.Remove(1));
  ASSERT_EQ(tree.GetMin(), 2);
  ASSERT_TRUE(tree.Remove(3));
  ASSERT_EQ(tree.GetMin(), 2);
  ASSERT_TRUE(tree.Remove(2));
  ASSERT_EQ(tree.GetMin(), 4);
  ASSERT_TRUE(tree.Insert(0));
  ASSERT_EQ(tree.GetMin(), 0);
}

TEST_F(BSTSearching, FindingTheMaxValueInTree) {
  ASSERT_EQ(tree.GetMax(), 7);
  ASSERT_TRUE(tree.Remove(7));
  ASSERT_EQ(tree.GetMax(), 6);
  ASSERT_TRUE(tree.Remove(6));
  ASSERT_EQ(tree.GetMax(), 5);
  ASSERT_TRUE(tree.Remove(5));
  ASSERT_EQ(tree.GetMax(), 4);
  ASSERT_TRUE(tree.Insert(99));
  ASSERT_EQ(tree.GetMax(), 99);
}

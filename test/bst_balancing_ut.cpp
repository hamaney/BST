//
//  bst_balancing_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-27.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//
#include <vector>
#include "bst.hpp"
#include "gtest/gtest.h"

using namespace BSTNS;

class BSTBalancing : public ::testing::Test {
 public:
  virtual void SetUp() {}
  virtual void TearDown(){};
  Tree tree;
};

TEST_F(BSTBalancing, AlreadyBalancedTreeWillNotBeModified) {
  Tree tree({2, 1, 3});
  tree.Balance();

  ASSERT_EQ(tree.root->data, 2);
  ASSERT_EQ(tree.root->height, 1);
  ASSERT_EQ(tree.root->left->data, 1);
  ASSERT_EQ(tree.root->left->height, 0);
  ASSERT_EQ(tree.root->right->data, 3);
  ASSERT_EQ(tree.root->right->height, 0);
}
TEST_F(BSTBalancing, LeftLeftbalancingBasicCase) {
  Tree tree({3, 2, 1});
  tree.Balance();

  ASSERT_EQ(tree.root->data, 2);
  ASSERT_EQ(tree.root->height, 1);
  ASSERT_EQ(tree.root->left->data, 1);
  ASSERT_EQ(tree.root->left->height, 0);
  ASSERT_EQ(tree.root->right->data, 3);
  ASSERT_EQ(tree.root->right->height, 0);
}
TEST_F(BSTBalancing, LeftRightBalancingBasicCase) {
  Tree tree({3, 1, 2});
  tree.Balance();

  ASSERT_EQ(tree.root->data, 2);
  ASSERT_EQ(tree.root->height, 1);
  ASSERT_EQ(tree.root->left->data, 1);
  ASSERT_EQ(tree.root->left->height, 0);
  ASSERT_EQ(tree.root->right->data, 3);
  ASSERT_EQ(tree.root->right->height, 0);
}
TEST_F(BSTBalancing, RightLeftBalancingBasicCase) {
  Tree tree({1, 3, 2});
  tree.Balance();
  ASSERT_EQ(tree.root->data, 2);
  ASSERT_EQ(tree.root->height, 1);
  ASSERT_EQ(tree.root->left->data, 1);
  ASSERT_EQ(tree.root->left->height, 0);
  ASSERT_EQ(tree.root->right->data, 3);
  ASSERT_EQ(tree.root->right->height, 0);
}
TEST_F(BSTBalancing, RightRightBalancingBasicCase) {
  Tree tree({1, 2, 3});
  tree.Balance();
  ASSERT_EQ(tree.root->data, 2);
  ASSERT_EQ(tree.root->height, 1);
  ASSERT_EQ(tree.root->left->data, 1);
  ASSERT_EQ(tree.root->left->height, 0);
  ASSERT_EQ(tree.root->right->data, 3);
  ASSERT_EQ(tree.root->right->height, 0);
}
TEST_F(BSTBalancing, RightRightBalancingTwiceInTheSameBranch) {
  Tree tree({1, 2, 3, 4, 5});
  /*      [1]_
   //         \
   //         [2]_
   //             \
   //             [3]_
   //                 \
   //                 [4]_
   //                     \
   //                     [5]
   */
  tree.Balance();
 
  ASSERT_EQ(tree.root->data, 2);
  ASSERT_EQ(tree.root->height, 2);
  ASSERT_EQ(tree.root->left->data, 1);
  ASSERT_EQ(tree.root->left->height, 0);
  ASSERT_EQ(tree.root->right->data, 4);
  ASSERT_EQ(tree.root->right->height, 1);
  ASSERT_EQ(tree.root->right->left->data, 3);
  ASSERT_EQ(tree.root->right->left->height, 0);
  ASSERT_EQ(tree.root->right->right->data, 5);
  ASSERT_EQ(tree.root->right->right->height, 0);
}

 TEST_F(BSTBalancing, BalancingATreeWithASenario) {
  Tree tree({7, 3, 11, 9, 13, 12});
  /*            _[7]_
   //          /     \
   //        [3]     [11]_
   //               /     \
   //              [9]   [13]
   //                   /
   //                 [12]
   */
  tree.Balance();
  /*             _[11]_
   //           /      \
   //        _[7]      [13]
   //       /    \     /
   //    _[3]    [9] [12]
   */
  ASSERT_EQ(tree.root->data, 11);
  ASSERT_EQ(tree.root->height, 2);
  ASSERT_EQ(tree.root->left->data, 7);
  ASSERT_EQ(tree.root->left->height, 1);
  ASSERT_EQ(tree.root->right->data, 13);
  ASSERT_EQ(tree.root->right->height, 1);
  ASSERT_EQ(tree.root->right->left->data, 12);
  ASSERT_EQ(tree.root->right->left->height, 0);
  ASSERT_EQ(tree.root->left->left->data, 3);
  ASSERT_EQ(tree.root->left->left->height, 0);
  ASSERT_EQ(tree.root->left->right->data, 9);
  ASSERT_EQ(tree.root->left->right->height, 0);
}

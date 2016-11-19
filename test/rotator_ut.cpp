//
//  rotator_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-14.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "gtest/gtest.h"

#include "bst.hpp"
#include "rotator.hpp"
//#include "tree_printer.hpp"

using namespace BSTNS;
using namespace BSTNS::Rotator;

class RotatorClass : public ::testing::Test
{
public:
  virtual void SetUp() {}
  virtual void TearDown(){};
  Data x;
  Data y;
  Data x_left;
  Data x_right;
  Data y_left;
  Data y_right;
};

TEST_F(RotatorClass, RotateLeftAboutTheTreeRoot)
{
  x = 2;
  x_left = 1;
  y = 4;
  y_left = 3;
  y_right = 5;
  Tree tree(x);
  tree.Add(x_left);
  tree.Add(y);
  tree.Add(y_left);
  tree.Add(y_right);
  /*        __[x=2]__
  //       /         \
  //   [xLeft=1]  _[y=4]_
  //             /       \
  //       [yLeft=3]  [yRight=5]
  */
  ASSERT_TRUE(RotateLeftAround(tree.root));
  /*             __[y=4](2)__
  //            /            \
  //        __[x=2](1)__  [yRight=5](0)
  //       /            \
  //   [xLeft=1](0)  [yLeft=3](0)
  */

  // tree connections after
  // |-Data
  ASSERT_EQ(tree.root->data, y);
  ASSERT_EQ(tree.root->left->data, x);
  ASSERT_EQ(tree.root->left->left->data, x_left);
  ASSERT_EQ(tree.root->left->right->data, y_left);
  ASSERT_EQ(tree.root->right->data, y_right);
  // |-Parents
  ASSERT_FALSE(tree.Find(y)->parent);
  ASSERT_EQ(tree.Find(x)->parent->data, y);
  ASSERT_EQ(tree.Find(y_right)->parent->data, y);
  ASSERT_EQ(tree.Find(x_left)->parent->data, x);
  ASSERT_EQ(tree.Find(y_left)->parent->data, x);
  // |-Left flag testing
  ASSERT_FALSE(tree.Find(y)->is_left_node);
  ASSERT_FALSE(tree.Find(y_left)->is_left_node);
  ASSERT_FALSE(tree.Find(y_right)->is_left_node);
  ASSERT_TRUE(tree.Find(x)->is_left_node);
  ASSERT_TRUE(tree.Find(x_left)->is_left_node);
  //  |- Height testing
  ASSERT_EQ(tree.Find(y)->height, 2);
  ASSERT_EQ(tree.Find(x)->height, 1);
  ASSERT_EQ(tree.Find(y_right)->height, 0);
  ASSERT_EQ(tree.Find(x_left)->height, 0);
  ASSERT_EQ(tree.Find(y_left)->height, 0);
}

TEST_F(RotatorClass, RotateLeftAboutLeftChild)
{
  x = 2;
  x_left = 1;
  y = 4;
  y_left = 3;
  y_right = 5;
  Tree tree(6);
  tree.Add(7);
  tree.Add(x);
  tree.Add(x_left);
  tree.Add(y);
  tree.Add(y_left);
  tree.Add(y_right);
  /*
  //             __[6]__
  //            /       \
  //        __[x=2]__   [7]
  //       /         \
  //   [xLeft=1]  _[y=4]_
  //             /       \
  //       [yLeft=3]  [yRight=5]
  */
  ASSERT_TRUE(RotateLeftAround(tree.root->left));
  /*
  //                  __[6](3)__
  //                 /          \
  //             __[y=4](2)__   [7](0)
  //            /            \
  //        __[x=2](1)__  [yRight=5](0)
  //       /            \
  //   [xLeft=1](0)  [yLeft=3](0)
  */

  // tree connections after
  // |-Data
  ASSERT_EQ(tree.root->data, 6);
  ASSERT_EQ(tree.root->right->data, 7);
  ASSERT_EQ(tree.root->left->data, y);
  ASSERT_EQ(tree.root->left->left->data, x);
  ASSERT_EQ(tree.root->left->left->left->data, x_left);
  ASSERT_EQ(tree.root->left->left->right->data, y_left);
  ASSERT_EQ(tree.root->left->right->data, y_right);
  // |-Parents
  ASSERT_FALSE(tree.Find(6)->parent);
  ASSERT_EQ(tree.Find(7)->parent->data, 6);
  ASSERT_EQ(tree.Find(y)->parent->data, 6);
  ASSERT_EQ(tree.Find(x)->parent->data, y);
  ASSERT_EQ(tree.Find(y_right)->parent->data, y);
  ASSERT_EQ(tree.Find(x_left)->parent->data, x);
  ASSERT_EQ(tree.Find(y_left)->parent->data, x);
  // |-Left flag testing
  ASSERT_FALSE(tree.Find(6)->is_left_node);
  ASSERT_FALSE(tree.Find(7)->is_left_node);
  ASSERT_FALSE(tree.Find(y_left)->is_left_node);
  ASSERT_FALSE(tree.Find(y_right)->is_left_node);
  ASSERT_TRUE(tree.Find(y)->is_left_node);
  ASSERT_TRUE(tree.Find(x)->is_left_node);
  ASSERT_TRUE(tree.Find(x_left)->is_left_node);
  //  |- Height testing
  ASSERT_EQ(tree.Find(6)->height, 3);
  ASSERT_EQ(tree.Find(7)->height, 0);
  ASSERT_EQ(tree.Find(y)->height, 2);
  ASSERT_EQ(tree.Find(x)->height, 1);
  ASSERT_EQ(tree.Find(y_right)->height, 0);
  ASSERT_EQ(tree.Find(x_left)->height, 0);
  ASSERT_EQ(tree.Find(y_left)->height, 0);
}

TEST_F(RotatorClass, RotateLeftAboutTheRightChild)
{

  x = 2;
  x_left = 1;
  y = 4;
  y_left = 3;
  y_right = 5;
  Tree tree(-1);
  tree.Add(-2);
  tree.Add(x);
  tree.Add(x_left);
  tree.Add(y);
  tree.Add(y_left);
  tree.Add(y_right);
  /*
     //     _[-1]__
     //    /       \
     //  [-2]  __[x=2]__
     //       /         \
     //   [xLeft=1]  _[y=4]_
     //             /       \
     //       [yLeft=3]  [yRight=5]
     */
  ASSERT_TRUE(RotateLeftAround(tree.root->right));
  /*
     //      ____[-1]__
     //     /          \
     //  [-2]       __[y=4](2)__
     //            /            \
     //        __[x=2](1)__  [yRight=5](0)
     //       /            \
     //   [xLeft=1](0)  [yLeft=3](0)
     */
  // tree connections after
  // |-Data
  ASSERT_EQ(tree.root->data, -1);
  ASSERT_EQ(tree.root->left->data, -2);
  ASSERT_EQ(tree.root->right->data, y);
  ASSERT_EQ(tree.root->right->left->data, x);
  ASSERT_EQ(tree.root->right->left->left->data, x_left);
  ASSERT_EQ(tree.root->right->left->right->data, y_left);
  ASSERT_EQ(tree.root->right->right->data, y_right);
  // |-Parents
  ASSERT_FALSE(tree.Find(-1)->parent);
  ASSERT_EQ(tree.Find(y)->parent->data, -1);
  ASSERT_EQ(tree.Find(x)->parent->data, y);
  ASSERT_EQ(tree.Find(y_right)->parent->data, y);
  ASSERT_EQ(tree.Find(x_left)->parent->data, x);
  ASSERT_EQ(tree.Find(y_left)->parent->data, x);
  // |-Left flag testing
  ASSERT_FALSE(tree.Find(-1)->is_left_node);
  ASSERT_FALSE(tree.Find(y_left)->is_left_node);
  ASSERT_FALSE(tree.Find(y_right)->is_left_node);
  ASSERT_FALSE(tree.Find(y)->is_left_node);
  ASSERT_TRUE(tree.Find(x)->is_left_node);
  ASSERT_TRUE(tree.Find(x_left)->is_left_node);
  //  |- Height testing
  ASSERT_EQ(tree.Find(-1)->height, 3);
  ASSERT_EQ(tree.Find(-1)->height, 3);
  ASSERT_EQ(tree.Find(y)->height, 2);
  ASSERT_EQ(tree.Find(x)->height, 1);
  ASSERT_EQ(tree.Find(y_right)->height, 0);
  ASSERT_EQ(tree.Find(x_left)->height, 0);
  ASSERT_EQ(tree.Find(y_left)->height, 0);
}

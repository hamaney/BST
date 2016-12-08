//
//  node_finder_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-19.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//
#include <vector>
#include "bst.hpp"
#include "gtest/gtest.h"

namespace BSTNS{
class NodeFinderFunctionCollections : public ::testing::Test {
 public:
  virtual void SetUp() {}
  virtual void TearDown(){};
  std::vector<Data> entries;
  Tree tree;
};
TEST_F(NodeFinderFunctionCollections, FindAValueInTree) {
  entries = {1, 4, 7, 3, 21, 9, 0};
  Tree tree(entries);
  /*        __[1]__
  //       /       \
  //      [0]     _[4]_
  //             /     \
  //           [3]    _[7]_
  //                 /     \
  //                [9]    [21]
  //
  */
  ASSERT_EQ(tree.FindNode(tree.root.get(), 4), tree.root->right.get());
  ASSERT_EQ(tree.FindNode(tree.root.get(), 3), tree.root->right->left.get());
  ASSERT_EQ(tree.FindNode(tree.root.get(), 1), tree.root.get());
  ASSERT_EQ(tree.FindNode(tree.root.get(), 0), tree.root->left.get());
  ASSERT_FALSE(tree.FindNode(tree.root.get(), -1));
}
TEST_F(NodeFinderFunctionCollections, FindMinValue) {
  entries = {1, 4, 7, 3, 2, 21, 6, 0};
  Tree tree(entries);
  /*        __[1]__
  //       /       \
  //      [0]     _[4]_
  //             /     \
  //          _[3]    _[7]_
  //         /       /     \
  //        [2]    [6]    [21]
  */
  ASSERT_EQ(tree.FindMinNode(tree.root.get())->data, 0);

  tree.Remove(0);
  tree.Remove(1);
  /*        _[4]_
  //       /     \
  //    _[3]    _[7]_
  //   /       /     \
  //  [2]    [6]    [21]
  */
  ASSERT_EQ(tree.FindMinNode(tree.root.get())->data, 2);

  tree.Insert(-1);
  /*          _[4]_
  //         /     \
  //       _[3]   _[7]_
  //      /      /     \
  //   _[2]    [6]    [21]
  //  /
  // [-1]
  */
  ASSERT_EQ(tree.FindMinNode(tree.root.get())->data, -1);

  // Find a min in a branch
  ASSERT_EQ(tree.FindMinNode(tree.Find(7))->data, 6);

  // TODO : delte the line
  // empty_tree.root->data =1;
  // from the test after changing the tree initilization step
  /*
  Tree empty_tree;
  empty_tree.root->data =1;
  ASSERT_FALSE(tree.FindMinNode(empty_tree.root.get()));
  */
}
TEST_F(NodeFinderFunctionCollections, FindMaxValue) {
  entries = {1, 4, 7, 3, 21, 9, 0};
  Tree tree(entries);
  /*        __[1]__
  //       /       \
  //      [0]     _[4]_
  //             /     \
  //           [3]    _[7]_
  //                 /     \
  //                [9]    [21]
  */
  ASSERT_EQ(tree.FindMaxNode(tree.root.get())->data, 21);
  ASSERT_EQ(tree.FindMaxNode(tree.Find(7))->data, 21);

  tree.Remove(21);
  tree.Remove(9);
  /*        __[1]__
  //       /       \
  //      [0]     _[4]_
  //             /     \
  //           [3]    [7]
  */
  ASSERT_EQ(tree.FindMaxNode(tree.root.get())->data, 7);

  tree.Insert(100);
  /*        __[1]__
  //       /       \
  //      [0]     _[4]_
  //             /     \
  //           [3]    [7]_
  //                      \
  //                     [100]
  */
  ASSERT_EQ(tree.FindMaxNode(tree.root.get())->data, 100);

  // TODO : delte the line
  // empty_tree.root->data =1;
  // from the test after changing the tree initilization step
  // Tree empty_tree(1);
  // empty_tree.root->data =1;
  // ASSERT_FALSE(tree.FindMaxNode(empty_tree.root.get()));
}

TEST_F(NodeFinderFunctionCollections, WhenMaxValueIsTheSameAsMinValue) {
  entries = {1};
  Tree tree(entries);
  /*     [1]
  */
  ASSERT_EQ(tree.FindMaxNode(tree.root.get())->data, 1);
  ASSERT_EQ(tree.FindMinNode(tree.root.get())->data, 1);
}
}

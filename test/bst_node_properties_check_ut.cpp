//
//  bst_properties_check_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-10-25.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include <vector>
#include "bst.hpp"
#include "gtest/gtest.h"

using namespace BSTNS;
class BSTNodeProperties : public ::testing::Test {
 public:
  virtual void SetUp() {}
  virtual void TearDown(){};
  std::vector<Data> entries;
  Tree tree;
};
TEST_F(BSTNodeProperties, CheckIfNodeIsLeaf) {
  entries = {7, 3, 11, 1, 5, 9, 13};
  Tree tree(entries);
  /*
  //
  //        ________[7]_______
  //       /                  \
  //     _[3]__            __[11]_
  //    /      \          /       \
  //  [1]      [5]      [9]       [13]
  //
  */

  ASSERT_TRUE(tree.IsLeaf(1));
  ASSERT_TRUE(tree.IsLeaf(5));
  ASSERT_TRUE(tree.IsLeaf(9));
  ASSERT_TRUE(tree.IsLeaf(13));
  ASSERT_FALSE(tree.IsLeaf(3));
  ASSERT_FALSE(tree.IsLeaf(11));
  ASSERT_FALSE(tree.IsLeaf(7));
  ASSERT_FALSE(tree.IsLeaf(99));
  ASSERT_FALSE(tree.IsLeaf(-99));
}

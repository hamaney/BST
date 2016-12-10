//
//  node_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-10-20.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "gtest/gtest.h"
#include "bst.hpp"

namespace BSTNS {
    


class NodeClass : public ::testing::Test {
 public:
  virtual void SetUp() {}
  virtual void TearDown(){};
};

TEST_F(NodeClass, NodeConstructionDefaultValue) {
  auto node = Node::CreateNode();
  ASSERT_EQ(node->data, 0);
  ASSERT_FALSE(node->parent);
  ASSERT_FALSE(node->left);
  ASSERT_FALSE(node->right);
  ASSERT_FALSE(node->is_left_node);
  ASSERT_EQ(node->height, 0);
  auto node_with_initial_value = Node::CreateNode(1);;
  ASSERT_EQ(node_with_initial_value->data, 1);
}
}

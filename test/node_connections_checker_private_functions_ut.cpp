//
//  node_connections_checker_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "gtest/gtest.h"
#include "bst.hpp"

namespace BSTNS{

class NodeConnectionsCheckerFunctionCollection : public ::testing::Test {
 public:
  virtual void SetUp() {
      
      
    node_with_no_children = std::make_unique<Node>();

    node_with_two_children = std::make_unique<Node>();
    node_with_two_children->left = std::make_unique<Node>();
    node_with_two_children->right = std::make_unique<Node>();

    node_with_only_left_child = std::make_unique<Node>();
    node_with_only_left_child->left = std::make_unique<Node>();

    node_with_only_right_child = std::make_unique<Node>();
    node_with_only_right_child->right = std::make_unique<Node>();
  }
  virtual void TearDown(){};
    Tree dummy_tree;
  NodeUPtr node_with_no_children;
  NodeUPtr node_with_two_children;
  NodeUPtr node_with_only_left_child;
  NodeUPtr node_with_only_right_child;
};

TEST_F(NodeConnectionsCheckerFunctionCollection, CheckIfNodeHasNoChildren) {
  ASSERT_FALSE(dummy_tree.HasNoChildren_(nullptr));
  ASSERT_TRUE(dummy_tree.HasNoChildren_(node_with_no_children.get()));
  ASSERT_FALSE(dummy_tree.HasNoChildren_(node_with_two_children.get()));
  ASSERT_FALSE(dummy_tree.HasNoChildren_(node_with_only_left_child.get()));
  ASSERT_FALSE(dummy_tree.HasNoChildren_(node_with_only_right_child.get()));
}

TEST_F(NodeConnectionsCheckerFunctionCollection, CheckIfNodeHasTwoChildren) {
  ASSERT_FALSE(dummy_tree.HasTwoChildren_(nullptr));
  ASSERT_FALSE(dummy_tree.HasTwoChildren_(node_with_no_children.get()));
  ASSERT_TRUE(dummy_tree.HasTwoChildren_(node_with_two_children.get()));
  ASSERT_FALSE(dummy_tree.HasTwoChildren_(node_with_only_left_child.get()));
  ASSERT_FALSE(dummy_tree.HasTwoChildren_(node_with_only_right_child.get()));
}
TEST_F(NodeConnectionsCheckerFunctionCollection, CheckIfNodeHasOnlyLeftChild) {
  ASSERT_FALSE(dummy_tree.HasOnlyLeftChild_(node_with_no_children.get()));
  ASSERT_FALSE(dummy_tree.HasOnlyLeftChild_(nullptr));
  ASSERT_FALSE(dummy_tree.HasOnlyLeftChild_(node_with_two_children.get()));
  ASSERT_TRUE(dummy_tree.HasOnlyLeftChild_(node_with_only_left_child.get()));
  ASSERT_FALSE(dummy_tree.HasOnlyLeftChild_(node_with_only_right_child.get()));
}
TEST_F(NodeConnectionsCheckerFunctionCollection, CheckIfNodeHasOnlyRightChild) {
  ASSERT_FALSE(dummy_tree.HasOnlyRightChild_(nullptr));
  ASSERT_FALSE(dummy_tree.HasOnlyRightChild_(node_with_no_children.get()));
  ASSERT_FALSE(dummy_tree.HasOnlyRightChild_(node_with_two_children.get()));
  ASSERT_FALSE(dummy_tree.HasOnlyRightChild_(node_with_only_left_child.get()));
  ASSERT_TRUE(dummy_tree.HasOnlyRightChild_(node_with_only_right_child.get()));
}
}



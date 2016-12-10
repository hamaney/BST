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
      
      
    node_with_no_children = Node::CreateNode();
      
      node_with_no_children = Node::CreateNode();

    node_with_two_children = Node::CreateNode();
    node_with_two_children->left = Node::CreateNode();
    node_with_two_children->right = Node::CreateNode();

    node_with_only_left_child = Node::CreateNode();
    node_with_only_left_child->left = Node::CreateNode();

    node_with_only_right_child = Node::CreateNode();
    node_with_only_right_child->right = Node::CreateNode();
  }
  virtual void TearDown(){};
    BST dummy_tree;
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



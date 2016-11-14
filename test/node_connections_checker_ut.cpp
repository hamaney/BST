//
//  node_connections_checker_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "gtest/gtest.h"
#include "node_connections_checker.hpp"

class NodeConnectionsCheckerClass : public ::testing::Test {
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
  NodeConnectionsChecker check_node;
  std::unique_ptr<Node> node_with_no_children;
  std::unique_ptr<Node> node_with_two_children;
  std::unique_ptr<Node> node_with_only_left_child;
  std::unique_ptr<Node> node_with_only_right_child;
};

TEST_F(NodeConnectionsCheckerClass, CheckIfNodeHasNoChildren) {
  ASSERT_FALSE(check_node.HasNoChildren(nullptr));
  ASSERT_TRUE(check_node.HasNoChildren(node_with_no_children.get()));
  ASSERT_FALSE(check_node.HasNoChildren(node_with_two_children.get()));
  ASSERT_FALSE(check_node.HasNoChildren(node_with_only_left_child.get()));
  ASSERT_FALSE(check_node.HasNoChildren(node_with_only_right_child.get()));
}

TEST_F(NodeConnectionsCheckerClass, CheckIfNodeHasTwoChildren) {
  ASSERT_FALSE(check_node.HasTwoChildren(nullptr));
  ASSERT_FALSE(check_node.HasTwoChildren(node_with_no_children.get()));
  ASSERT_TRUE(check_node.HasTwoChildren(node_with_two_children.get()));
  ASSERT_FALSE(check_node.HasTwoChildren(node_with_only_left_child.get()));
  ASSERT_FALSE(check_node.HasTwoChildren(node_with_only_right_child.get()));
}
TEST_F(NodeConnectionsCheckerClass, CheckIfNodeHasOnlyLeftChild) {
  ASSERT_FALSE(check_node.HasOnlyLeftChild(node_with_no_children.get()));
  ASSERT_FALSE(check_node.HasOnlyLeftChild(nullptr));
  ASSERT_FALSE(check_node.HasOnlyLeftChild(node_with_two_children.get()));
  ASSERT_TRUE(check_node.HasOnlyLeftChild(node_with_only_left_child.get()));
  ASSERT_FALSE(check_node.HasOnlyLeftChild(node_with_only_right_child.get()));
}
TEST_F(NodeConnectionsCheckerClass, CheckIfNodeHasOnlyRightChild) {
  ASSERT_FALSE(check_node.HasOnlyRightChild(nullptr));
  ASSERT_FALSE(check_node.HasOnlyRightChild(node_with_no_children.get()));
  ASSERT_FALSE(check_node.HasOnlyRightChild(node_with_two_children.get()));
  ASSERT_FALSE(check_node.HasOnlyRightChild(node_with_only_left_child.get()));
  ASSERT_TRUE(check_node.HasOnlyRightChild(node_with_only_right_child.get()));
}

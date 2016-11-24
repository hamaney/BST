//
//  node_connections_checker_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "gtest/gtest.h"
#include "node_connections_checker.hpp"

using namespace BSTNS;
using namespace BSTNS::NodeConnectionsChecker;

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
  NodeUPtr node_with_no_children;
  NodeUPtr node_with_two_children;
  NodeUPtr node_with_only_left_child;
  NodeUPtr node_with_only_right_child;
};

TEST_F(NodeConnectionsCheckerFunctionCollection, CheckIfNodeHasNoChildren) {
  ASSERT_FALSE(HasNoChildren(nullptr));
  ASSERT_TRUE(HasNoChildren(node_with_no_children.get()));
  ASSERT_FALSE(HasNoChildren(node_with_two_children.get()));
  ASSERT_FALSE(HasNoChildren(node_with_only_left_child.get()));
  ASSERT_FALSE(HasNoChildren(node_with_only_right_child.get()));
}

TEST_F(NodeConnectionsCheckerFunctionCollection, CheckIfNodeHasTwoChildren) {
  ASSERT_FALSE(HasTwoChildren(nullptr));
  ASSERT_FALSE(HasTwoChildren(node_with_no_children.get()));
  ASSERT_TRUE(HasTwoChildren(node_with_two_children.get()));
  ASSERT_FALSE(HasTwoChildren(node_with_only_left_child.get()));
  ASSERT_FALSE(HasTwoChildren(node_with_only_right_child.get()));
}
TEST_F(NodeConnectionsCheckerFunctionCollection, CheckIfNodeHasOnlyLeftChild) {
  ASSERT_FALSE(HasOnlyLeftChild(node_with_no_children.get()));
  ASSERT_FALSE(HasOnlyLeftChild(nullptr));
  ASSERT_FALSE(HasOnlyLeftChild(node_with_two_children.get()));
  ASSERT_TRUE(HasOnlyLeftChild(node_with_only_left_child.get()));
  ASSERT_FALSE(HasOnlyLeftChild(node_with_only_right_child.get()));
}
TEST_F(NodeConnectionsCheckerFunctionCollection, CheckIfNodeHasOnlyRightChild) {
  ASSERT_FALSE(HasOnlyRightChild(nullptr));
  ASSERT_FALSE(HasOnlyRightChild(node_with_no_children.get()));
  ASSERT_FALSE(HasOnlyRightChild(node_with_two_children.get()));
  ASSERT_FALSE(HasOnlyRightChild(node_with_only_left_child.get()));
  ASSERT_TRUE(HasOnlyRightChild(node_with_only_right_child.get()));
}
//
//  BST_UT.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-10-08.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include <memory>
#include "BST.cpp"
#include "BST.hpp"
#include "gtest/gtest.h"

class BSTCreation : public ::testing::Test {
 public:
  virtual void SetUp() {}
  virtual void TearDown(){};
};
TEST_F(BSTCreation, TreeInitilization) {
  auto empty_tree = std::make_unique<Tree>();
  ASSERT_EQ(empty_tree->root->data, 0);
  ASSERT_EQ(empty_tree->root->left, nullptr);
  ASSERT_EQ(empty_tree->root->right, nullptr);
  auto tree_with_initial_value = std::make_unique<Tree>(5);
  ASSERT_EQ(tree_with_initial_value->root->data, 5);
  ASSERT_EQ(tree_with_initial_value->root->left, nullptr);
  ASSERT_EQ(tree_with_initial_value->root->right, nullptr);
}
TEST_F(BSTCreation, AddingEntryToTheTree) {
  //
  //        ________[4]_______
  //       /                  \
  //     _[2]__            __[6]_
  //    /      \          /      \
  //  [1]      [3]      [5]      [7]

  auto tree = std::make_unique<Tree>(4);
  ASSERT_EQ(tree->root->data, 4);
  ASSERT_EQ(tree->root->left, nullptr);
  ASSERT_EQ(tree->root->right, nullptr);

  tree->Add(2);
  ASSERT_EQ(tree->root->data, 4);
  ASSERT_EQ(tree->root->left->data, 2);
  ASSERT_EQ(tree->root->right, nullptr);

  tree->Add(6);
  ASSERT_EQ(tree->root->data, 4);
  ASSERT_EQ(tree->root->left->data, 2);
  ASSERT_EQ(tree->root->right->data, 6);

  tree->Add(1);
  ASSERT_EQ(tree->root->data, 4);
  ASSERT_EQ(tree->root->left->data, 2);
  ASSERT_EQ(tree->root->right->data, 6);
  ASSERT_EQ(tree->root->left->left->data, 1);

  tree->Add(3);
  ASSERT_EQ(tree->root->data, 4);
  ASSERT_EQ(tree->root->left->data, 2);
  ASSERT_EQ(tree->root->right->data, 6);
  ASSERT_EQ(tree->root->left->left->data, 1);
  ASSERT_EQ(tree->root->left->right->data, 3);

  tree->Add(5);
  ASSERT_EQ(tree->root->data, 4);
  ASSERT_EQ(tree->root->left->data, 2);
  ASSERT_EQ(tree->root->right->data, 6);
  ASSERT_EQ(tree->root->left->left->data, 1);
  ASSERT_EQ(tree->root->left->right->data, 3);
  ASSERT_EQ(tree->root->right->left->data, 5);

  tree->Add(7);
  ASSERT_EQ(tree->root->data, 4);
  ASSERT_EQ(tree->root->left->data, 2);
  ASSERT_EQ(tree->root->right->data, 6);
  ASSERT_EQ(tree->root->left->left->data, 1);
  ASSERT_EQ(tree->root->left->right->data, 3);
  ASSERT_EQ(tree->root->right->left->data, 5);
  ASSERT_EQ(tree->root->right->right->data, 7);
}
TEST_F(BSTCreation, FindingAKeyValue) {
  //
  //        ________[4]_______
  //       /                  \
  //     _[2]__            __[6]_
  //    /      \          /      \
  //  [1]      [3]      [5]      [7]
  //

  auto tree = std::make_unique<Tree>(4);
  tree->Add(1);
  tree->Add(2);
  tree->Add(6);
  tree->Add(3);
  tree->Add(5);
  tree->Add(7);

  Data root_data = (tree->Find(4))->data;
  ASSERT_EQ(root_data, 4);

  Data rand_data = (tree->Find(5))->data;
  ASSERT_EQ(rand_data, 5);

  Tree::Node* target_node = tree->Find(0);
  ASSERT_EQ(target_node, nullptr);
}
TEST_F(BSTCreation, CheckIfKeyExists) {
  //
  //        ________[4]_______
  //       /                  \
  //     _[2]__            __[6]_
  //    /      \          /      \
  //  [1]      [3]      [5]      [7]
  //

  auto tree = std::make_unique<Tree>(4);
  tree->Add(1);
  tree->Add(2);
  tree->Add(6);
  tree->Add(3);
  tree->Add(5);
  tree->Add(7);
  ASSERT_TRUE(tree->Exist(4));
  ASSERT_TRUE(tree->Exist(7));
  ASSERT_FALSE(tree->Exist(0));
  ASSERT_FALSE(tree->Exist(-1));
}
TEST_F(BSTCreation, AddAnExistingKey) {
  //
  //        ________[4]_______
  //       /                  \
  //     _[2]__            __[6]_
  //    /      \          /      \
  //  [1]      [3]      [5]      [7]
  //

  auto tree = std::make_unique<Tree>(4);
  tree->Add(1);
  tree->Add(2);
  tree->Add(6);
  tree->Add(3);
  tree->Add(5);
  tree->Add(7);
  ASSERT_EXIT(tree->Add(7), ::testing::ExitedWithCode(Tree::KEntryExist + 1),
              "The entry added already exists!");
}

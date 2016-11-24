//
//  BST_UT.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-10-08.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "bst.hpp"
#include "gtest/gtest.h"
#include "node_inserter.hpp"

using namespace BSTNS;
using namespace BSTNS::NodeInserter;

class NodeInserterFunctionsCollection : public ::testing::Test {
 public:
  virtual void SetUp() {}
  virtual void TearDown(){};
};

TEST_F(NodeInserterFunctionsCollection, InsertUniqueEntriesToTheTree) {
  // will test this tree (final shape)

  /*        ________[4]_______
  //       /                  \
  //     _[2]__            __[6]_
  //    /      \          /      \
  //  [1]      [3]      [5]      [7]
  */
  Tree tree;

  ASSERT_FALSE(InsertValue(tree.root, 4));  // return the parent wich is null

  ASSERT_FALSE(tree.root->parent);
  ASSERT_FALSE(tree.root->left);
  ASSERT_FALSE(tree.root->right);
  ASSERT_FALSE(tree.root->is_left_node);

  ASSERT_TRUE(
      InsertValue(tree.root, 2));  // return the parentwich is node contain 4
  ASSERT_EQ(tree.root->data, 4);   //------------- 4
  ASSERT_FALSE(tree.root->parent);
  ASSERT_TRUE(tree.root->left);
  ASSERT_FALSE(tree.root->right);
  ASSERT_FALSE(tree.root->is_left_node);
  ASSERT_EQ(tree.root->left->data, 2);  //------------- 2
  ASSERT_EQ(tree.root->left->parent, tree.root.get());
  ASSERT_FALSE(tree.root->left->left);
  ASSERT_FALSE(tree.root->left->right);
  ASSERT_TRUE(tree.root->left->is_left_node);

  ASSERT_TRUE(InsertValue(tree.root, 6));

  ASSERT_EQ(tree.root->data, 4);  //------------- 4
  ASSERT_FALSE(tree.root->parent);
  ASSERT_TRUE(tree.root->left);
  ASSERT_TRUE(tree.root->right);
  ASSERT_FALSE(tree.root->is_left_node);
  ASSERT_EQ(tree.root->left->data, 2);  //------------- 2
  ASSERT_EQ(tree.root->left->parent, tree.root.get());
  ASSERT_FALSE(tree.root->left->left);
  ASSERT_FALSE(tree.root->left->right);
  ASSERT_TRUE(tree.root->left->is_left_node);
  ASSERT_EQ(tree.root->right->data, 6);  //------------- 6
  ASSERT_EQ(tree.root->right->parent, tree.root.get());
  ASSERT_FALSE(tree.root->right->left);
  ASSERT_FALSE(tree.root->right->right);
  ASSERT_FALSE(tree.root->right->is_left_node);

  ASSERT_TRUE(InsertValue(tree.root, 1));

  ASSERT_EQ(tree.root->data, 4);  //------------- 4
  ASSERT_FALSE(tree.root->parent);
  ASSERT_TRUE(tree.root->left);
  ASSERT_TRUE(tree.root->right);
  ASSERT_FALSE(tree.root->is_left_node);
  ASSERT_EQ(tree.root->left->data, 2);  //------------- 2
  ASSERT_EQ(tree.root->left->parent, tree.root.get());
  ASSERT_TRUE(tree.root->left->left);
  ASSERT_FALSE(tree.root->left->right);
  ASSERT_TRUE(tree.root->left->is_left_node);
  ASSERT_EQ(tree.root->right->data, 6);  //------------- 6
  ASSERT_EQ(tree.root->right->parent, tree.root.get());
  ASSERT_FALSE(tree.root->right->left);
  ASSERT_FALSE(tree.root->right->right);
  ASSERT_FALSE(tree.root->right->is_left_node);
  ASSERT_EQ(tree.root->left->left->data, 1);  //------------- 1
  ASSERT_EQ(tree.root->left->left->parent, tree.root->left.get());
  ASSERT_FALSE(tree.root->left->left->left);
  ASSERT_FALSE(tree.root->left->left->right);
  ASSERT_TRUE(tree.root->left->left->is_left_node);

  ASSERT_TRUE(InsertValue(tree.root, 3));

  ASSERT_EQ(tree.root->data, 4);  //------------- 4
  ASSERT_FALSE(tree.root->parent);
  ASSERT_TRUE(tree.root->left);
  ASSERT_TRUE(tree.root->right);
  ASSERT_FALSE(tree.root->is_left_node);
  ASSERT_EQ(tree.root->left->data, 2);  //------------- 2
  ASSERT_EQ(tree.root->left->parent, tree.root.get());
  ASSERT_TRUE(tree.root->left->left);
  ASSERT_TRUE(tree.root->left->right);
  ASSERT_TRUE(tree.root->left->is_left_node);
  ASSERT_EQ(tree.root->right->data, 6);  //------------- 6
  ASSERT_EQ(tree.root->right->parent, tree.root.get());
  ASSERT_FALSE(tree.root->right->left);
  ASSERT_FALSE(tree.root->right->right);
  ASSERT_FALSE(tree.root->right->is_left_node);
  ASSERT_EQ(tree.root->left->left->data, 1);  //------------- 1
  ASSERT_EQ(tree.root->left->left->parent, tree.root->left.get());
  ASSERT_FALSE(tree.root->left->left->left);
  ASSERT_FALSE(tree.root->left->left->right);
  ASSERT_TRUE(tree.root->left->left->is_left_node);
  ASSERT_EQ(tree.root->left->right->data, 3);  //------------- 3
  ASSERT_EQ(tree.root->left->right->parent, tree.root->left.get());
  ASSERT_FALSE(tree.root->left->right->left);
  ASSERT_FALSE(tree.root->left->right->right);
  ASSERT_FALSE(tree.root->left->right->is_left_node);

  ASSERT_TRUE(InsertValue(tree.root, 5));

  ASSERT_EQ(tree.root->data, 4);  //------------- 4
  ASSERT_FALSE(tree.root->parent);
  ASSERT_TRUE(tree.root->left);
  ASSERT_TRUE(tree.root->right);
  ASSERT_FALSE(tree.root->is_left_node);
  ASSERT_EQ(tree.root->left->data, 2);  //------------- 2
  ASSERT_EQ(tree.root->left->parent, tree.root.get());
  ASSERT_TRUE(tree.root->left->left);
  ASSERT_TRUE(tree.root->left->right);
  ASSERT_TRUE(tree.root->left->is_left_node);
  ASSERT_EQ(tree.root->right->data, 6);  //------------- 6
  ASSERT_EQ(tree.root->right->parent, tree.root.get());
  ASSERT_TRUE(tree.root->right->left);
  ASSERT_FALSE(tree.root->right->right);
  ASSERT_FALSE(tree.root->right->is_left_node);
  ASSERT_EQ(tree.root->left->left->data, 1);  //------------- 1
  ASSERT_EQ(tree.root->left->left->parent, tree.root->left.get());
  ASSERT_FALSE(tree.root->left->left->left);
  ASSERT_FALSE(tree.root->left->left->right);
  ASSERT_TRUE(tree.root->left->left->is_left_node);
  ASSERT_EQ(tree.root->left->right->data, 3);  //------------- 3
  ASSERT_EQ(tree.root->left->right->parent, tree.root->left.get());
  ASSERT_FALSE(tree.root->left->right->left);
  ASSERT_FALSE(tree.root->left->right->right);
  ASSERT_FALSE(tree.root->left->right->is_left_node);
  ASSERT_EQ(tree.root->right->left->data, 5);  //------------- 5
  ASSERT_EQ(tree.root->right->left->parent, tree.root->right.get());
  ASSERT_FALSE(tree.root->right->left->left);
  ASSERT_FALSE(tree.root->right->left->right);
  ASSERT_TRUE(tree.root->right->left->is_left_node);

  ASSERT_TRUE(InsertValue(tree.root, 7));

  ASSERT_EQ(tree.root->data, 4);  //------------- 4
  ASSERT_FALSE(tree.root->parent);
  ASSERT_TRUE(tree.root->left);
  ASSERT_TRUE(tree.root->right);
  ASSERT_FALSE(tree.root->is_left_node);
  ASSERT_EQ(tree.root->left->data, 2);  //------------- 2
  ASSERT_EQ(tree.root->left->parent, tree.root.get());
  ASSERT_TRUE(tree.root->left->left);
  ASSERT_TRUE(tree.root->left->right);
  ASSERT_TRUE(tree.root->left->is_left_node);
  ASSERT_EQ(tree.root->right->data, 6);  //------------- 6
  ASSERT_EQ(tree.root->right->parent, tree.root.get());
  ASSERT_TRUE(tree.root->right->left);
  ASSERT_TRUE(tree.root->right->right);
  ASSERT_FALSE(tree.root->right->is_left_node);
  ASSERT_EQ(tree.root->left->left->data, 1);  //------------- 1
  ASSERT_EQ(tree.root->left->left->parent, tree.root->left.get());
  ASSERT_FALSE(tree.root->left->left->left);
  ASSERT_FALSE(tree.root->left->left->right);
  ASSERT_TRUE(tree.root->left->left->is_left_node);
  ASSERT_EQ(tree.root->left->right->data, 3);  //------------- 3
  ASSERT_EQ(tree.root->left->right->parent, tree.root->left.get());
  ASSERT_FALSE(tree.root->left->right->left);
  ASSERT_FALSE(tree.root->left->right->right);
  ASSERT_FALSE(tree.root->left->right->is_left_node);
  ASSERT_EQ(tree.root->right->left->data, 5);  //------------- 5
  ASSERT_EQ(tree.root->right->left->parent, tree.root->right.get());
  ASSERT_FALSE(tree.root->right->left->left);
  ASSERT_FALSE(tree.root->right->left->right);
  ASSERT_TRUE(tree.root->right->left->is_left_node);
  ASSERT_EQ(tree.root->right->right->data, 7);  //------------- 7
  ASSERT_EQ(tree.root->right->right->parent, tree.root->right.get());
  ASSERT_FALSE(tree.root->right->right->left);
  ASSERT_FALSE(tree.root->right->right->right);
  ASSERT_FALSE(tree.root->right->right->is_left_node);
  // Tested this tree

  /*        ________[4]_______
  //       /                  \
  //     _[2]__            __[6]_
  //    /      \          /      \
  //  [1]      [3]      [5]      [7]
  */
}

TEST_F(NodeInserterFunctionsCollection, InsertAnExistingEntryToTheTree) {
  Tree tree({4, 2, 6, 1, 3, 5, 7});

  ASSERT_FALSE(InsertValue(tree.root, 4));
  ASSERT_FALSE(InsertValue(tree.root, 2));
  ASSERT_FALSE(InsertValue(tree.root, 6));
  ASSERT_FALSE(InsertValue(tree.root, 7));
}

TEST_F(NodeInserterFunctionsCollection, InsertingNewRootNodeAfterEmptyingTheTree) {
  Tree tree({4, 2, 6});
  ASSERT_TRUE(tree.Remove(2));
  ASSERT_TRUE(tree.Remove(6));
  ASSERT_TRUE(tree.Remove(4));
  ASSERT_FALSE(InsertValue(tree.root, 7));
  ASSERT_EQ(tree.root->data, 7);
  ASSERT_FALSE(tree.root->parent);
}

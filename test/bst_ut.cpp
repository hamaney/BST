//
//  BST_UT.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-10-08.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include <memory>
#include "bst.cpp"
#include "bst.hpp"
#include "gtest/gtest.h"

class BSTCreation : public ::testing::Test
{
public:
  virtual void SetUp() {}
  virtual void TearDown(){};
};

TEST_F(BSTCreation, TreeInitilization)
{
  Tree tree;
  ASSERT_EQ(tree.root->data, 0);
  ASSERT_EQ(tree.root->data, 0);

  Tree tree_with_initial_value(1);
  ASSERT_EQ(tree_with_initial_value.root->data, 1);
}

TEST_F(BSTCreation, AddingUniqueEntriesToTheTree)
{

  // will test this tree (final shape)
  //
  //        ________[4]_______
  //       /                  \
    //     _[2]__            __[6]_
  //    /      \          /      \
    //  [1]      [3]      [5]      [7]

  Tree tree(4);

  ASSERT_TRUE(tree.Add(2));
  ASSERT_EQ(tree.root->data, 4);
  ASSERT_FALSE(tree.root->parent);
  ASSERT_TRUE(tree.root->left);
  ASSERT_FALSE(tree.root->right);
  ASSERT_FALSE(tree.root->is_left_node);
  ASSERT_EQ(tree.root->left->data, 2);
  ASSERT_EQ(tree.root->left->parent, tree.root.get());
  ASSERT_FALSE(tree.root->left->left);
  ASSERT_FALSE(tree.root->left->right);
  ASSERT_TRUE(tree.root->left->is_left_node);

  ASSERT_TRUE(tree.Add(6));
  ASSERT_EQ(tree.root->data, 4);
  ASSERT_FALSE(tree.root->parent);
  ASSERT_TRUE(tree.root->left);
  ASSERT_TRUE(tree.root->right);
  ASSERT_FALSE(tree.root->is_left_node);
  ASSERT_EQ(tree.root->left->data, 2);
  ASSERT_EQ(tree.root->left->parent, tree.root.get());
  ASSERT_FALSE(tree.root->left->left);
  ASSERT_FALSE(tree.root->left->right);
  ASSERT_TRUE(tree.root->left->is_left_node);
  ASSERT_EQ(tree.root->right->data, 6);
  ASSERT_EQ(tree.root->right->parent, tree.root.get());
  ASSERT_FALSE(tree.root->right->left);
  ASSERT_FALSE(tree.root->right->right);
  ASSERT_FALSE(tree.root->right->is_left_node);

  ASSERT_TRUE(tree.Add(1));
  ASSERT_EQ(tree.root->data, 4);
  ASSERT_FALSE(tree.root->parent);
  ASSERT_TRUE(tree.root->left);
  ASSERT_TRUE(tree.root->right);
  ASSERT_FALSE(tree.root->is_left_node);
  ASSERT_EQ(tree.root->left->data, 2);
  ASSERT_EQ(tree.root->left->parent, tree.root.get());
  ASSERT_TRUE(tree.root->left->left);
  ASSERT_FALSE(tree.root->left->right);
  ASSERT_TRUE(tree.root->left->is_left_node);
  ASSERT_EQ(tree.root->right->data, 6);
  ASSERT_EQ(tree.root->right->parent, tree.root.get());
  ASSERT_FALSE(tree.root->right->left);
  ASSERT_FALSE(tree.root->right->right);
  ASSERT_FALSE(tree.root->right->is_left_node);
  ASSERT_EQ(tree.root->left->left->data, 1);
  ASSERT_EQ(tree.root->left->left->parent, tree.root->left.get());
  ASSERT_FALSE(tree.root->left->left->left);
  ASSERT_FALSE(tree.root->left->left->right);
  ASSERT_TRUE(tree.root->left->left->is_left_node);

  ASSERT_TRUE(tree.Add(3));
  ASSERT_EQ(tree.root->data, 4);
  ASSERT_FALSE(tree.root->parent);
  ASSERT_TRUE(tree.root->left);
  ASSERT_TRUE(tree.root->right);
  ASSERT_FALSE(tree.root->is_left_node);
  ASSERT_EQ(tree.root->left->data, 2);
  ASSERT_EQ(tree.root->left->parent, tree.root.get());
  ASSERT_TRUE(tree.root->left->left);
  ASSERT_TRUE(tree.root->left->right);
  ASSERT_TRUE(tree.root->left->is_left_node);
  ASSERT_EQ(tree.root->right->data, 6);
  ASSERT_EQ(tree.root->right->parent, tree.root.get());
  ASSERT_FALSE(tree.root->right->left);
  ASSERT_FALSE(tree.root->right->right);
  ASSERT_FALSE(tree.root->right->is_left_node);
  ASSERT_EQ(tree.root->left->left->data, 1);
  ASSERT_EQ(tree.root->left->left->parent, tree.root->left.get());
  ASSERT_FALSE(tree.root->left->left->left);
  ASSERT_FALSE(tree.root->left->left->right);
  ASSERT_TRUE(tree.root->left->left->is_left_node);
  ASSERT_EQ(tree.root->left->right->data, 3);
  ASSERT_EQ(tree.root->left->right->parent, tree.root->left.get());
  ASSERT_FALSE(tree.root->left->right->left);
  ASSERT_FALSE(tree.root->left->right->right);
  ASSERT_FALSE(tree.root->left->right->is_left_node);

  ASSERT_TRUE(tree.Add(5));
  ASSERT_EQ(tree.root->data, 4);
  ASSERT_FALSE(tree.root->parent);
  ASSERT_TRUE(tree.root->left);
  ASSERT_TRUE(tree.root->right);
  ASSERT_FALSE(tree.root->is_left_node);
  ASSERT_EQ(tree.root->left->data, 2);
  ASSERT_EQ(tree.root->left->parent, tree.root.get());
  ASSERT_TRUE(tree.root->left->left);
  ASSERT_TRUE(tree.root->left->right);
  ASSERT_TRUE(tree.root->left->is_left_node);
  ASSERT_EQ(tree.root->right->data, 6);
  ASSERT_EQ(tree.root->right->parent, tree.root.get());
  ASSERT_TRUE(tree.root->right->left);
  ASSERT_FALSE(tree.root->right->right);
  ASSERT_FALSE(tree.root->right->is_left_node);
  ASSERT_EQ(tree.root->left->left->data, 1);
  ASSERT_EQ(tree.root->left->left->parent, tree.root->left.get());
  ASSERT_FALSE(tree.root->left->left->left);
  ASSERT_FALSE(tree.root->left->left->right);
  ASSERT_TRUE(tree.root->left->left->is_left_node);
  ASSERT_EQ(tree.root->left->right->data, 3);
  ASSERT_EQ(tree.root->left->right->parent, tree.root->left.get());
  ASSERT_FALSE(tree.root->left->right->left);
  ASSERT_FALSE(tree.root->left->right->right);
  ASSERT_FALSE(tree.root->left->right->is_left_node);
  ASSERT_EQ(tree.root->right->left->data, 5);
  ASSERT_EQ(tree.root->right->left->parent, tree.root->right.get());
  ASSERT_FALSE(tree.root->right->left->left);
  ASSERT_FALSE(tree.root->right->left->right);
  ASSERT_TRUE(tree.root->right->left->is_left_node);

  ASSERT_TRUE(tree.Add(7));
  ASSERT_EQ(tree.root->data, 4);
  ASSERT_FALSE(tree.root->parent);
  ASSERT_TRUE(tree.root->left);
  ASSERT_TRUE(tree.root->right);
  ASSERT_FALSE(tree.root->is_left_node);
  ASSERT_EQ(tree.root->left->data, 2);
  ASSERT_EQ(tree.root->left->parent, tree.root.get());
  ASSERT_TRUE(tree.root->left->left);
  ASSERT_TRUE(tree.root->left->right);
  ASSERT_TRUE(tree.root->left->is_left_node);
  ASSERT_EQ(tree.root->right->data, 6);
  ASSERT_EQ(tree.root->right->parent, tree.root.get());
  ASSERT_TRUE(tree.root->right->left);
  ASSERT_TRUE(tree.root->right->right);
  ASSERT_FALSE(tree.root->right->is_left_node);
  ASSERT_EQ(tree.root->left->left->data, 1);
  ASSERT_EQ(tree.root->left->left->parent, tree.root->left.get());
  ASSERT_FALSE(tree.root->left->left->left);
  ASSERT_FALSE(tree.root->left->left->right);
  ASSERT_TRUE(tree.root->left->left->is_left_node);
  ASSERT_EQ(tree.root->left->right->data, 3);
  ASSERT_EQ(tree.root->left->right->parent, tree.root->left.get());
  ASSERT_FALSE(tree.root->left->right->left);
  ASSERT_FALSE(tree.root->left->right->right);
  ASSERT_FALSE(tree.root->left->right->is_left_node);
  ASSERT_EQ(tree.root->right->left->data, 5);
  ASSERT_EQ(tree.root->right->left->parent, tree.root->right.get());
  ASSERT_FALSE(tree.root->right->left->left);
  ASSERT_FALSE(tree.root->right->left->right);
  ASSERT_TRUE(tree.root->right->left->is_left_node);
  ASSERT_EQ(tree.root->right->right->data, 7);
  ASSERT_EQ(tree.root->right->right->parent, tree.root->right.get());
  ASSERT_FALSE(tree.root->right->right->left);
  ASSERT_FALSE(tree.root->right->right->right);
  ASSERT_FALSE(tree.root->right->right->is_left_node);
  // Tested this tree
  //
  //        ________[4]_______
  //       /                  \
    //     _[2]__            __[6]_
  //    /      \          /      \
    //  [1]      [3]      [5]      [7]
}

class BSTSearching : public ::testing::Test
{
public:
  virtual void SetUp()
  {
    tree.root->data = 4;
    tree.Add(2);
    tree.Add(6);
    tree.Add(1);
    tree.Add(3);
    tree.Add(5);
    tree.Add(7);
    //
    //        ________[4]_______
    //       /                  \
    //     _[2]__            __[6]_
    //    /      \          /      \
    //  [1]      [3]      [5]      [7]
    //
  }
  virtual void TearDown(){};
  Tree tree;
};

TEST_F(BSTSearching, FindingAValueInTree)
{
  ASSERT_EQ(tree.Find(4), tree.root.get());
  ASSERT_EQ(tree.Find(2), tree.root->left.get());
  ASSERT_EQ(tree.Find(6), tree.root->right.get());
  ASSERT_EQ(tree.Find(1), tree.root->left->left.get());
  ASSERT_EQ(tree.Find(3), tree.root->left->right.get());
  ASSERT_EQ(tree.Find(5), tree.root->right->left.get());
  ASSERT_EQ(tree.Find(7), tree.root->right->right.get());
}

TEST_F(BSTSearching, CheckingIfValueExistsInTree)
{
  ASSERT_TRUE(tree.Find(1));
  ASSERT_TRUE(tree.Find(2));
  ASSERT_TRUE(tree.Find(3));
  ASSERT_TRUE(tree.Find(4));
  ASSERT_TRUE(tree.Find(5));
  ASSERT_TRUE(tree.Find(6));
  ASSERT_TRUE(tree.Find(7));
  ASSERT_FALSE(tree.Find(-100));
  ASSERT_FALSE(tree.Find(100));
}

TEST_F(BSTCreation, AddingExistingEntryToTheTree)
{
  Tree tree(4);
  tree.Add(2);
  tree.Add(6);
  tree.Add(1);
  tree.Add(3);
  tree.Add(5);
  tree.Add(7);
  ASSERT_FALSE(tree.Add(4));
  ASSERT_FALSE(tree.Add(2));
  ASSERT_FALSE(tree.Add(6));
  ASSERT_FALSE(tree.Add(1));
  ASSERT_FALSE(tree.Add(3));
  ASSERT_FALSE(tree.Add(5));
  ASSERT_FALSE(tree.Add(7));
}

class BSTPropertiesCheck : public ::testing::Test
{
public:
  virtual void SetUp()
  {
    tree.root->data = 4;
    tree.Add(2);
    tree.Add(6);
    tree.Add(1);
    tree.Add(3);
    tree.Add(5);
    tree.Add(7);
    //
    //        ________[4]_______
    //       /                  \
        //     _[2]__            __[6]_
    //    /      \          /      \
        //  [1]      [3]      [5]      [7]
    //
  }
  virtual void TearDown(){};
  Tree tree;
};
TEST_F(BSTPropertiesCheck, CheckIfLeafNode)
{
  ASSERT_TRUE(tree.isLeaf(1));
  ASSERT_TRUE(tree.isLeaf(3));
  ASSERT_TRUE(tree.isLeaf(5));
  ASSERT_TRUE(tree.isLeaf(7));
  ASSERT_FALSE(tree.isLeaf(4));
  ASSERT_FALSE(tree.isLeaf(2));
  ASSERT_FALSE(tree.isLeaf(6));
}

TEST_F(BSTPropertiesCheck, CheckIfNodeHasOneLeftChild)
{
  ASSERT_TRUE(tree.isLeaf(1));
  ASSERT_TRUE(tree.isLeaf(3));
  ASSERT_TRUE(tree.isLeaf(5));
  ASSERT_TRUE(tree.isLeaf(7));
  ASSERT_FALSE(tree.isLeaf(4));
  ASSERT_FALSE(tree.isLeaf(2));
  ASSERT_FALSE(tree.isLeaf(6));
}
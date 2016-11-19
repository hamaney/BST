//
//  bst_node_removal_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-10-26.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "bst.hpp"
#include "gtest/gtest.h"

using namespace BSTNS;

class BSTNodeRemoval : public ::testing::Test
{
public:
  virtual void SetUp()
  {
    tree.root->data = 7;
    tree.Add(3);
    tree.Add(11);
    tree.Add(1);
    tree.Add(5);
    tree.Add(9);
    tree.Add(13);
    /*        ________[7]_______
    //       /                  \
    //     _[3]__            __[11]_
    //    /      \          /        \
    //  [1]      [5]      [9]        [13]
    */
  }
  virtual void TearDown(){};
  Tree tree;
};

TEST_F(BSTNodeRemoval, RemoveNodeWithNoChildren)
{
  //        ________[7]_______
  //       /                  \
    //     _[3]__            __[11]_
  //    /      \          /       \
    //  [1]X     [5]      [9]        [13]
  ASSERT_TRUE(tree.Find(1));
  ASSERT_TRUE(tree.Remove(1));
  ASSERT_FALSE(tree.Find(1));
  //        ________[7]_______
  //       /                  \
    //      [3]_             __[11]_
  //          \           /       \
    //           [5]      [9]       [13]
  // parent status after removing
  ASSERT_FALSE(tree.Find(3)->left.get());
  ASSERT_EQ(tree.Find(3)->right->data, 5);
  ASSERT_EQ(tree.Find(3)->parent->data, 7);
  // Sibling status after removing
  ASSERT_EQ(tree.Find(5)->parent->data, 3);

  //--------------------------------------------------------------------------

  //        ________[7]_______
  //       /                  \
    //      [3]__            __[11]_
  //           \          /       \
    //          [5]      [9]       [13]X
  ASSERT_TRUE(tree.Find(13));
  ASSERT_TRUE(tree.Remove(13));
  ASSERT_FALSE(tree.Find(13));
  //        ________[7]_______
  //       /                  \
    //      [3]__            __[11]
  //           \          /
  //           [5]      [9]
  // parent status after removing
  ASSERT_FALSE(tree.Find(11)->right.get());
  ASSERT_EQ(tree.Find(11)->left->data, 9);
  ASSERT_EQ(tree.Find(11)->parent->data, 7);
  // Sibling status after removing
  ASSERT_EQ(tree.Find(9)->parent->data, 11);

  //--------------------------------------------------------------------------

  //        ________[7]_______
  //       /                  \
    //
  Tree tree_with_root_node_only(7);
  ASSERT_TRUE(tree_with_root_node_only.Remove(7));
  ASSERT_FALSE(tree_with_root_node_only.Find(7));
  ASSERT_FALSE(tree_with_root_node_only.root);
}
TEST_F(BSTNodeRemoval, CheckNodeHightAfterRemovingANodeWithNoChildren)
{
  /*        ________[7]_______
  //       /                  \
  //     _[3]__            __[11]_
  //    /      \          /       \
  //  [1]      [5]      [9]        [13]
  */
  tree.Add(-1);
  tree.Add(-2);
  ASSERT_EQ(tree.root->height, 4);
  /*             ________[7]_______
  //            /                  \
  //         _[3]__            __[11]_
  //        /      \          /       \
  //      [1]      [5]      [9]        [13]
  //     /
  //   [-1]
  //    /
  //   [-2]
  */
  tree.Remove(-2);
  /*             ________[7]_______
  //            /                  \
  //         _[3]__            __[11]_
  //        /      \          /       \
  //      [1]     [5]      [9]        [13]
  //     /
  //   [-1]
  */
  ASSERT_EQ(tree.Find(-1)->height, 0);
  ASSERT_EQ(tree.Find(1)->height, 1);
  ASSERT_EQ(tree.Find(5)->height, 0);
  ASSERT_EQ(tree.Find(3)->height, 2);
  ASSERT_EQ(tree.Find(9)->height, 0);
  ASSERT_EQ(tree.Find(13)->height, 0);
  ASSERT_EQ(tree.Find(11)->height, 1);
  ASSERT_EQ(tree.root->height, 3);
    

  /*              ________[7]_______
   //            /                  \
   //         _[3]__            __[11]_
   //        /      \          /       \
   //      [1]     [5]      [9]        [13]
   //     /
   //   [-1]X
   */
  tree.Remove(-1);
  /*              ________[7]_______
   //            /                  \
   //         _[3]__            __[11]_
   //        /      \          /       \
   //      [1]     [5]      [9]        [13]
   */
  ASSERT_EQ(tree.root->height, 2);
  ASSERT_EQ(tree.Find(3)->height, 1);
  ASSERT_EQ(tree.Find(11)->height, 1);
  ASSERT_EQ(tree.Find(1)->height, 0);
  ASSERT_EQ(tree.Find(5)->height, 0);
  ASSERT_EQ(tree.Find(9)->height, 0);
  ASSERT_EQ(tree.Find(13)->height, 0);

  /*        ________[7]_______
  //       /                  \
  //     _[3]__            __[11]_
  //    /      \          /       \
  //  [1]X     [5]      [9]        [13]
  */
  tree.Remove(1);
  /*        ________[7]_______
  //       /                  \
  //      [3]_             __[11]_
  //          \           /       \
  //           [5]      [9]       [13]
  */
  ASSERT_EQ(tree.root->height, 2);
  ASSERT_EQ(tree.Find(3)->height, 1);
  ASSERT_EQ(tree.Find(11)->height, 1);
  ASSERT_EQ(tree.Find(5)->height, 0);
  ASSERT_EQ(tree.Find(9)->height, 0);
  ASSERT_EQ(tree.Find(13)->height, 0);

  /*        ________[7]_______
  //       /                  \
  //      [3]__            __[11]_
  //           \          /       \
  //          [5]X      [9]       [13]
  */
  tree.Remove(5);
  /*        ________[7]_______
  //       /                  \
  //      [3]              __[11]_
  //                      /       \
  //                    [9]       [13]
  */
  ASSERT_EQ(tree.root->height, 2);
  ASSERT_EQ(tree.Find(3)->height, 0);
  ASSERT_EQ(tree.Find(11)->height, 1);
  ASSERT_EQ(tree.Find(9)->height, 0);
  ASSERT_EQ(tree.Find(13)->height, 0);

  /*        ________[7]_______
  //       /                  \
  //      [3]X             __[11]_
  //                      /       \
  //                    [9]       [13]
  */
  tree.Remove(3);
  /*                [7]_______
  //                          \
  //                       __[11]_
  //                      /       \
  //                    [9]       [13]
  */
  ASSERT_EQ(tree.root->height, 2);
  ASSERT_EQ(tree.Find(11)->height, 1);
  ASSERT_EQ(tree.Find(9)->height, 0);
  ASSERT_EQ(tree.Find(13)->height, 0);

  /*                [7]_______
  //                          \
  //                       __[11]_
  //                      /       \
  //                    [9]X       [13]
  */
  tree.Remove(9);
  /*                [7]_______
  //                          \
  //                         [11]_
  //                              \
  //                              [13]
  */
  ASSERT_EQ(tree.root->height, 2);
  ASSERT_EQ(tree.Find(11)->height, 1);
  ASSERT_EQ(tree.Find(13)->height, 0);

  /*                [7]_______
  //                          \
  //                         [11]_
  //                              \
  //                              [13]X
  */

  tree.Remove(13);
  /*                [7]_______
  //                          \
  //                         [11]
  */
  ASSERT_EQ(tree.root->height, 1);
  ASSERT_EQ(tree.Find(11)->height, 0);

  /*                [7]_______
  //                          \
  //                         [11]X
  */
  tree.Remove(11);
  /*                [7]
  */
  ASSERT_EQ(tree.root->height, 0);
  tree.Remove(7);
}
TEST_F(BSTNodeRemoval, RemoveNodeWithOnlyLeftChild)
{
  /*        ________[7]_______
  //       /                  \
  //     _[3]__            __[11]_
  //    /      \          /       \
  //  [1]      [5]X      [9]       [13]
  // prepare to have a Node with only left child
  */
  ASSERT_TRUE(tree.Find(5));
  ASSERT_TRUE(tree.Remove(5));
  ASSERT_FALSE(tree.Find(5));
  /*        ________[7]_______
  //       /                  \
  //     _[3]X             __[11]_
  //    /                 /       \
  //  [1]               [9]       [13]
  */
  // remove a node with onlu left child
  ASSERT_TRUE(tree.Find(3));
  ASSERT_TRUE(tree.Remove(3));
  ASSERT_FALSE(tree.Find(3));
  /*        ________[7]______
  //       /                 \
  //      [1]             __[11]_
  //                     /       \
  //                   [9]       [13]
  */
  // Checks the tree status after removing the node
  // parent status after removing
  ASSERT_EQ(tree.Find(7)->left->data, 1);
  ASSERT_FALSE(tree.Find(7)->parent);
  // Sibling status after removing
  ASSERT_EQ(tree.Find(11)->parent->data, 7);
  ASSERT_EQ(tree.Find(11)->parent->left->data, 1);
  // check the new node
  ASSERT_EQ(tree.Find(1)->parent->data, 7);
  ASSERT_TRUE(tree.Find(1)->is_left_node);

  //--------------------------------------------------------------------------

  /*        ________[7]X
  //       /
  //      [1]
  */
  Tree tree_with_root_that_has_only_left_child(7);
  ASSERT_TRUE(tree_with_root_that_has_only_left_child.Add(1));
  ASSERT_TRUE(tree_with_root_that_has_only_left_child.Remove(7));
  ASSERT_FALSE(tree_with_root_that_has_only_left_child.Find(7));
  //        ________[1]
  //       /
  ASSERT_EQ(tree_with_root_that_has_only_left_child.root->data, 1);

  ASSERT_FALSE(tree_with_root_that_has_only_left_child.root->parent);
  ASSERT_FALSE(tree_with_root_that_has_only_left_child.root->is_left_node);
}
TEST_F(BSTNodeRemoval, CheckNodeHightAfterRemovingANodeWithOnlyLeftChild)
{
  /*        ________[7]_______
  //       /                  \
  //     _[3]__            __[11]_
  //    /      \          /       \
  //  [1]      [5]X      [9]       [13]
  */
  // prepare to have a Node with only left child
  tree.Remove(5);
  /*        ________[7]_______
  //       /                  \
  //     _[3]X             __[11]_
  //    /                 /       \
  //  [1]               [9]       [13]
  */
  tree.Remove(3);
  /*        ________[7]______
  //       /                 \
  //      [1]             __[11]_
  //                     /       \
  //                   [9]       [13]
  */
  ASSERT_EQ(tree.root->height, 2);
  ASSERT_EQ(tree.Find(1)->height, 0);
  ASSERT_EQ(tree.Find(11)->height, 1);
  ASSERT_EQ(tree.Find(9)->height, 0);
  ASSERT_EQ(tree.Find(13)->height, 0);
  //--------------------------------------------------------------------------

  //        ________[7]X
  //       /
  //      [1]
  Tree tree_with_root_that_has_only_left_child(7);
  tree_with_root_that_has_only_left_child.Add(1);
  tree_with_root_that_has_only_left_child.Remove(7);
  //        ________[1]
  //       /
  ASSERT_EQ(tree_with_root_that_has_only_left_child.root->height, 0);
}
TEST_F(BSTNodeRemoval, RemoveNodeWithOnlyRightChild)
{
  //        ________[7]_______
  //       /                  \
    //     _[3]__            __[11]_
  //    /      \          /       \
    //  [1]X      [5]      [9]       [13]
  // prepare to have a Node with only left child
  ASSERT_TRUE(tree.Find(1));
  ASSERT_TRUE(tree.Remove(1));
  ASSERT_FALSE(tree.Find(1));
  //        ________[7]_______
  //       /                  \
    //      [3]X             __[11]_
  //         \            /       \
    //         [5]       [9]       [13]
  // remove a node with only left child
  ASSERT_TRUE(tree.Find(3));
  ASSERT_TRUE(tree.Remove(3));
  ASSERT_FALSE(tree.Find(3));

  //        ________[7]______
  //       /                 \
    //      [5]             __[11]_
  //                     /       \
    //                   [9]       [13]
  // Checks the tree status after removing the node
  // parent status after removing
  ASSERT_EQ(tree.Find(7)->left->data, 5);
  ASSERT_FALSE(tree.Find(7)->parent);
  // Sibling status after removing
  ASSERT_EQ(tree.Find(11)->parent->data, 7);
  ASSERT_EQ(tree.Find(11)->parent->left->data, 5);
  // check the new node
  ASSERT_EQ(tree.Find(5)->parent->data, 7);
  ASSERT_TRUE(tree.Find(5)->is_left_node);
  //--------------------------------------------------------------------------

  /*        ________[7]X____
  //       /                 \
  //                        [11]
  */
  Tree tree_with_root_that_has_only_right_child(7);
  ASSERT_TRUE(tree_with_root_that_has_only_right_child.Add(11));
  ASSERT_TRUE(tree_with_root_that_has_only_right_child.Remove(7));
  ASSERT_FALSE(tree_with_root_that_has_only_right_child.Find(7));
  /*        ________[1]
  //       /
  */
  ASSERT_EQ(tree_with_root_that_has_only_right_child.root->data, 11);
  ASSERT_FALSE(tree_with_root_that_has_only_right_child.root->parent);
  ASSERT_FALSE(tree_with_root_that_has_only_right_child.root->is_left_node);
}
TEST_F(BSTNodeRemoval, CheckNodeHightAfterRemovingANodeWithOnlyRightChild)
{
  /*        ________[7]_______
  //       /                  \
  //     _[3]__            __[11]_
  //    /      \          /       \
  //  [1]X      [5]      [9]       [13]
  */
  // prepare to have a Node with only left child
  tree.Remove(1);
  /*        ________[7]_______
  //       /                  \
  //      [3]X             __[11]_
  //         \            /       \
  //         [5]       [9]       [13]
  */
  tree.Remove(3);
  /*        ________[7]______
  //       /                 \
  //      [5]             __[11]_
  //                     /       \
  //                   [9]       [13]
  */
  ASSERT_EQ(tree.root->height, 2);
  ASSERT_EQ(tree.Find(5)->height, 0);
  ASSERT_EQ(tree.Find(11)->height, 1);
  ASSERT_EQ(tree.Find(9)->height, 0);
  ASSERT_EQ(tree.Find(13)->height, 0);

  //--------------------------------------------------------------------------

  /*        ________[7]X____
  //       /                 \
  //                        [11]
  */
  Tree tree_with_root_that_has_only_right_child(7);
  tree_with_root_that_has_only_right_child.Add(11);
  tree_with_root_that_has_only_right_child.Remove(7);
  /*        ________[11]
  */
  ASSERT_EQ(tree_with_root_that_has_only_right_child.root->height, 0);
}
TEST_F(BSTNodeRemoval, RemoveNodeWithTwoChildrenNodeIsALeftChild)
{
  /*        ________[7]_______
  //       /                  \
  //     _[3]X_            __[11]_
  //    /      \          /       \
  //  [1]      [5]      [9]       [13]
  */
  ASSERT_TRUE(tree.Remove(3));
  ASSERT_FALSE(tree.Find(3));
  /*        ________[7]_______
  //       /                  \
  //     _[5]              __[11]_
  //    /                 /       \
  //   [1]             [9]       [13]
  */
  // Checks the tree status after removing the node
  // parent status after removing
  ASSERT_EQ(tree.Find(7)->left->data, 5);
  ASSERT_FALSE(tree.Find(7)->parent);
  ASSERT_FALSE(tree.Find(7)->is_left_node);
  // Sibling status after removing
  ASSERT_EQ(tree.Find(1)->parent->data, 5);
  ASSERT_TRUE(tree.Find(1)->is_left_node);
  // check the new node
  ASSERT_EQ(tree.Find(5)->parent->data, 7);
  ASSERT_TRUE(tree.Find(5)->is_left_node);
  ASSERT_TRUE(tree.Find(5)->left);
  ASSERT_FALSE(tree.Find(5)->right);
}
TEST_F(BSTNodeRemoval,
       CheckNodeHeightAfterRemoveingNodeWithTwoChildrenNodeIsALeftChild)
{
  /*        ________[7]_______
   //       /                  \
   //     _[3]X_            __[11]_
   //    /      \          /       \
   //  [1]      [5]      [9]       [13]
   */
  tree.Remove(3);
  /*        ________[7]_______
  //       /                  \
  //     _[5]              __[11]_
  //    /                 /       \
  //   [1]             [9]       [13]
  */
  ASSERT_EQ(tree.root->height, 2);
  ASSERT_EQ(tree.Find(5)->height, 1);
  ASSERT_EQ(tree.Find(11)->height, 1);
  ASSERT_EQ(tree.Find(1)->height, 0);
  ASSERT_EQ(tree.Find(9)->height, 0);
  ASSERT_EQ(tree.Find(13)->height, 0);
}
TEST_F(BSTNodeRemoval, RemoveNodeWithTwoChildrenNodeIsARighttChild)
{
  //        ________[7]_______
  //       /                  \
    //     _[3]__            __[11]X_
  //    /      \          /       \
    //  [1]      [5]      [9]       [13]
  ASSERT_TRUE(tree.Remove(11));
  ASSERT_FALSE(tree.Find(11));
  //        ________[7]_______
  //       /                  \
    //     _[3]_               [13]
  //    /     \             /
  //  [1]      [5]        [9]
  // Checks the tree status after removing the node
  // parent status after removing
  ASSERT_FALSE(tree.Find(7)->parent);
  ASSERT_EQ(tree.Find(7)->right->data, 13);
  ASSERT_EQ(tree.Find(7)->left->data, 3);
  ASSERT_FALSE(tree.Find(7)->is_left_node);
  // Sibling status after removing
  ASSERT_EQ(tree.Find(3)->parent->data, 7);
  ASSERT_TRUE(tree.Find(3)->is_left_node);
  // check the new node
  ASSERT_EQ(tree.Find(13)->parent->data, 7);
  ASSERT_FALSE(tree.Find(13)->right);
  ASSERT_EQ(tree.Find(13)->left->data, 9);
  ASSERT_FALSE(tree.Find(13)->is_left_node);
}
TEST_F(BSTNodeRemoval,
       CheckNodeHeightAfterRemovingNodeWithTwoChildrenNodeIsARightChild)
{
  /*        ________[7]_______
  //       /                  \
  //     _[3]__            __[11]X
  //    /      \          /       \
  //  [1]      [5]      [9]       [13]
  */
  tree.Remove(11);
  /*        ________[7]_______
  //       /                  \
  //     _[3]_               [13]
  //    /     \             /
  //  [1]      [5]        [9]
  */
  ASSERT_EQ(tree.root->height, 2);
  ASSERT_EQ(tree.Find(3)->height, 1);
  ASSERT_EQ(tree.Find(13)->height, 1);
  ASSERT_EQ(tree.Find(1)->height, 0);
  ASSERT_EQ(tree.Find(5)->height, 0);
  ASSERT_EQ(tree.Find(9)->height, 0);
}
TEST_F(BSTNodeRemoval, RemoveNodeWithTwoChildrenNodeIsTheRoot)
{
  //        ________[7]X______
  //       /                  \
  //     _[3]__            __[11]_
  //    /      \          /       \
  //  [1]      [5]      [9]       [13]

  ASSERT_TRUE(tree.Remove(7));
  ASSERT_FALSE(tree.Find(7));
  //        ________[9]_______
  //       /                  \
  //     _[3]__              [11]_
  //    /      \                  \
  //  [1]      [5]                [13]

  // Checks the tree status after removing the node
  // parent status after removing
  ASSERT_FALSE(tree.root->parent);
  ASSERT_EQ(tree.root->data, 9);
  ASSERT_EQ(tree.root->left->data, 3);
  ASSERT_EQ(tree.root->right->data, 11);
  ASSERT_FALSE(tree.root->is_left_node);
  // Child status after removing
  ASSERT_EQ(tree.Find(3)->parent->data, 9);
  ASSERT_EQ(tree.Find(3)->left->data, 1);
  ASSERT_EQ(tree.Find(3)->right->data, 5);
  ASSERT_TRUE(tree.Find(3)->is_left_node);
  ASSERT_EQ(tree.Find(11)->parent->data, 9);
  ASSERT_EQ(tree.Find(11)->right->data, 13);
  ASSERT_FALSE(tree.Find(11)->left);
  ASSERT_FALSE(tree.Find(11)->is_left_node);
}
TEST_F(BSTNodeRemoval,
       CheckNodeHeightAfterRemovingNodeWithTwoChildrenNodeIsTheRoot)
{
  //        ________[7]X______
  //       /                  \
    //     _[3]__            __[11]_
  //    /      \          /       \
    //  [1]      [5]      [9]       [13]

  tree.Remove(7);
  //        ________[9]_______
  //       /                  \
    //     _[3]__              [11]_
  //    /      \                  \
    //  [1]      [5]                [13]
  ASSERT_EQ(tree.root->height, 2);
  ASSERT_EQ(tree.Find(3)->height, 1);
  ASSERT_EQ(tree.Find(11)->height, 1);
  ASSERT_EQ(tree.Find(1)->height, 0);
  ASSERT_EQ(tree.Find(5)->height, 0);
  ASSERT_EQ(tree.Find(13)->height, 0);
}
TEST_F(BSTNodeRemoval, RemoveNodeWithTwoChildrenHasRecursaiveCallToRemove)
{
  //        ________[7]_______
  //       /                  \
    //     _[3]__            __[11]_
  //    /      \          /       \
    //  [1]      [5]      [9]       [13]
  ASSERT_TRUE(tree.Add(2));
  ASSERT_TRUE(tree.Find(2));
  ASSERT_TRUE(tree.Add(4));
  ASSERT_TRUE(tree.Find(4));
  ASSERT_TRUE(tree.Add(6));
  ASSERT_TRUE(tree.Find(6));
  ASSERT_TRUE(tree.Add(8));
  ASSERT_TRUE(tree.Find(8));
  ASSERT_TRUE(tree.Add(10));
  ASSERT_TRUE(tree.Find(10));
  ASSERT_TRUE(tree.Add(14));
  ASSERT_TRUE(tree.Find(14));
  //        ________[7]_______
  //       /                  \
    //     _[3]X_            __[11]X
  //    /      \          /       \
    //  [1]     _[5]_     [9]       [13]
  //    \    /     \    /  \         \
    //    [2] [4]   [6]  [8] [10]     [14]
  ASSERT_TRUE(tree.Remove(3));
  ASSERT_FALSE(tree.Find(3));
  /*        ________[7]_______
  //       /                  \
  //     _[4]_             _[11]_
  //    /      \          /       \
  //  [1]      [5]_     [9]       [13]
  //    \          \    /  \         \
  //    [2]       [6]  [8] [10]     [14]
  */
  // Checks the tree status after removing the node
  // parent status after removing 3
  ASSERT_FALSE(tree.Find(7)->parent);
  ASSERT_EQ(tree.Find(7)->left->data, 4);
  ASSERT_EQ(tree.Find(7)->right->data, 11);
  ASSERT_FALSE(tree.Find(7)->is_left_node);
  // Sibling status after removing 3
  ASSERT_EQ(tree.Find(11)->parent->data, 7);
  ASSERT_FALSE(tree.Find(11)->is_left_node);
  // Check the new node instead of 3
  ASSERT_EQ(tree.Find(4)->parent->data, 7);
  ASSERT_EQ(tree.Find(4)->left->data, 1);
  ASSERT_EQ(tree.Find(4)->right->data, 5);
  ASSERT_TRUE(tree.Find(4)->is_left_node);

  /*        ________[7]_______
  //       /                  \
  //     _[4]_             _[11]X
  //    /      \          /       \
  //  [1]      [5]_     [9]       [13]
  //    \          \    /  \         \
  //    [2]       [6]  [8] [10]     [14]
  */
  ASSERT_TRUE(tree.Remove(11));
  ASSERT_FALSE(tree.Find(11));
  /*        ________[7]_______
  //       /                  \
  //     _[4]_             _[13]_
  //    /      \          /       \
  //  [1]      [5]_     [9]       [14]
  //    \          \    /  \
  //    [2]       [6]  [8] [10]
  */
  // parent status after removing 11
  ASSERT_FALSE(tree.Find(7)->parent);
  ASSERT_EQ(tree.Find(7)->left->data, 4);
  ASSERT_EQ(tree.Find(7)->right->data, 13);
  ASSERT_FALSE(tree.Find(7)->is_left_node);
  // Sibling status after removing 11
  ASSERT_EQ(tree.Find(4)->parent->data, 7);
  ASSERT_TRUE(tree.Find(4)->is_left_node);
  // check the new node instead of 11
  ASSERT_EQ(tree.Find(13)->parent->data, 7);
  ASSERT_EQ(tree.Find(13)->left->data, 9);
  ASSERT_EQ(tree.Find(13)->right->data, 14);
  ASSERT_FALSE(tree.Find(13)->is_left_node);
}
TEST_F(
    BSTNodeRemoval,
    CheckNodeHeightAfterRemovingANodeWithTwoChildrenHasRecursaiveCallToRemove)
{
  /*        ________[7]_______
  //       /                  \
  //     _[3]__            __[11]_
  //    /      \          /       \
  //  [1]      [5]      [9]       [13]
  */
  tree.Add(2);
  tree.Add(4);
  tree.Add(6);
  tree.Add(8);
  tree.Add(10);
  tree.Add(14);
  /*        ________[7]_______
  //       /                  \
  //     _[3]X_            __[11]X
  //    /      \          /       \
  //  [1]     _[5]_     [9]       [13]
  //    \    /     \    /  \         \
  //    [2] [4]   [6]  [8] [10]     [14]
  */
  tree.Remove(3);
  /*        ________[7]_______
  //       /                  \
  //     _[4]_             _[11]_
  //    /      \          /       \
  //  [1]      [5]_     [9]       [13]
  //    \          \    /  \         \
  //    [2]       [6]  [8] [10]     [14]
  */
  ASSERT_EQ(tree.root->height, 3);
  ASSERT_EQ(tree.Find(4)->height, 2);
  ASSERT_EQ(tree.Find(11)->height, 2);
  ASSERT_EQ(tree.Find(1)->height, 1);
  ASSERT_EQ(tree.Find(5)->height, 1);
  ASSERT_EQ(tree.Find(9)->height, 1);
  ASSERT_EQ(tree.Find(13)->height, 1);
  ASSERT_EQ(tree.Find(2)->height, 0);
  ASSERT_EQ(tree.Find(6)->height, 0);
  ASSERT_EQ(tree.Find(8)->height, 0);
  ASSERT_EQ(tree.Find(10)->height, 0);
  ASSERT_EQ(tree.Find(14)->height, 0);

  /*        ________[7]_______
  //       /                  \
  //     _[4]_             _[11]X
  //    /      \          /       \
  //  [1]      [5]_     [9]       [13]
  //    \          \    /  \         \
  //    [2]       [6]  [8] [10]     [14]
  */
  tree.Remove(11);
  /*        ________[7]_______
  //       /                  \
  //     _[4]_             _[13]_
  //    /      \          /       \
  //  [1]      [5]_     [9]       [14]
  //    \          \    /  \
  //    [2]       [6]  [8] [10]
  */
  ASSERT_EQ(tree.root->height, 3);
  ASSERT_EQ(tree.Find(4)->height, 2);
  ASSERT_EQ(tree.Find(13)->height, 2);
  ASSERT_EQ(tree.Find(1)->height, 1);
  ASSERT_EQ(tree.Find(5)->height, 1);
  ASSERT_EQ(tree.Find(9)->height, 1);
  ASSERT_EQ(tree.Find(14)->height, 0);
  ASSERT_EQ(tree.Find(2)->height, 0);
  ASSERT_EQ(tree.Find(6)->height, 0);
  ASSERT_EQ(tree.Find(8)->height, 0);
  ASSERT_EQ(tree.Find(10)->height, 0);
}

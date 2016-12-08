//
//  node_remover_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-19.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include <vector>
#include "bst.hpp"
#include "gtest/gtest.h"
namespace BSTNS{
class NodeRemoverFunctionsCollection : public ::testing::Test {
 public:
  virtual void SetUp() {
    entries = {7, 3, 11, 1, 5, 9, 13};
    tree.Insert(entries);
    /*        ________[7]_______
     //       /                  \
     //     _[3]__            __[11]_
     //    /      \          /        \
     //  [1]      [5]      [9]        [13]
     */
  }
  virtual void TearDown(){};
  std::vector<Data> entries;
  Tree tree;
};

TEST_F(NodeRemoverFunctionsCollection,
       RemoveNodeWithNoChildrenUsingPrivateHelper) {
  /*        ________[7]_______
  //       /                  \
  //     _[3]__            __[11]_
  //    /      \          /       \
  //  [1]X     [5]      [9]        [13]
  */
  ASSERT_EQ(tree.RemoveNodeWithNoChildren_(tree.root, tree.Find(1)), tree.Find(3));
  /*        ________[7]_______
  //       /                  \
  //      [3]_             __[11]_
  //          \           /       \
  //           [5]      [9]       [13]
  */
  // parent status after removing
  ASSERT_FALSE(tree.Find(3)->left.get());
  ASSERT_EQ(tree.Find(3)->right->data, 5);
  ASSERT_EQ(tree.Find(3)->parent->data, 7);
  // Sibling status after removing
  ASSERT_EQ(tree.Find(5)->parent->data, 3);

  //--------------------------------------------------------------------------

  /*        ________[7]_______
  //       /                  \
  //      [3]__            __[11]_
  //           \          /       \
  //          [5]      [9]       [13]X
  */
  ASSERT_EQ(tree.RemoveNodeWithNoChildren_(tree.root, tree.Find(13)), tree.Find(11));
  /*        ________[7]_______
  //       /                  \
  //      [3]__            __[11]
  //           \          /
  //           [5]      [9]
  */
  // parent status after removing
  ASSERT_FALSE(tree.Find(11)->right.get());
  ASSERT_EQ(tree.Find(11)->left->data, 9);
  ASSERT_EQ(tree.Find(11)->parent->data, 7);
  // Sibling status after removing
  ASSERT_EQ(tree.Find(9)->parent->data, 11);

  //--------------------------------------------------------------------------

  /*        ________[7]_______
  //       /                  \
  //
  */
  Tree tree_with_root_node_only(7);
  ASSERT_FALSE(tree.RemoveNodeWithNoChildren_(tree_with_root_node_only.root,
                                         tree_with_root_node_only.Find(7)));
  ASSERT_FALSE(tree_with_root_node_only.Find(7));
  ASSERT_FALSE(tree_with_root_node_only.root);
}
TEST_F(NodeRemoverFunctionsCollection,
       RemoveNodeWithNoChildrenUsingRemoveNode) {
  /*        ________[7]_______
  //       /                  \
  //     _[3]__            __[11]_
  //    /      \          /       \
  //  [1]X     [5]      [9]        [13]
  */
  ASSERT_EQ(tree.RemoveNode(tree.root, tree.Find(1)), tree.Find(3));
  /*        ________[7]_______
  //       /                  \
  //      [3]_             __[11]_
  //          \           /       \
  //           [5]      [9]       [13]
  */
  // parent status after removing
  ASSERT_FALSE(tree.Find(3)->left.get());
  ASSERT_EQ(tree.Find(3)->right->data, 5);
  ASSERT_EQ(tree.Find(3)->parent->data, 7);
  // Sibling status after removing
  ASSERT_EQ(tree.Find(5)->parent->data, 3);

  //--------------------------------------------------------------------------

  /*        ________[7]_______
  //       /                  \
  //      [3]__            __[11]_
  //           \          /       \
  //          [5]      [9]       [13]X
  */
  ASSERT_EQ(tree.RemoveNode(tree.root, tree.Find(13)), tree.Find(11));
  /*        ________[7]_______
  //       /                  \
  //      [3]__            __[11]
  //           \          /
  //           [5]      [9]
  */
  // parent status after removing
  ASSERT_FALSE(tree.Find(11)->right.get());
  ASSERT_EQ(tree.Find(11)->left->data, 9);
  ASSERT_EQ(tree.Find(11)->parent->data, 7);
  // Sibling status after removing
  ASSERT_EQ(tree.Find(9)->parent->data, 11);

  //--------------------------------------------------------------------------

  /*        ________[7]_______
  //       /                  \
  */
  Tree tree_with_root_node_only(7);
  ASSERT_FALSE(tree.RemoveNode(tree_with_root_node_only.root,
                          tree_with_root_node_only.Find(7)));
  ASSERT_FALSE(tree_with_root_node_only.Find(7));
  ASSERT_FALSE(tree_with_root_node_only.root);
}

TEST_F(NodeRemoverFunctionsCollection,
       RemoveNodeWithOnlyRightChildUsingPrivateHelper) {
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
  // remove a node with only left child
  ASSERT_EQ(tree.RemoveNodeWithOnlyRightChild_(tree.root, tree.Find(3)),
            tree.Find(7));
  /*        ________[7]______
  //       /                 \
  //      [5]             __[11]_
  //                     /       \
  //                   [9]       [13]
  */
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
  Tree tree_with_root_that_has_only_right_child({7, 11});
  ASSERT_FALSE(tree.RemoveNodeWithOnlyRightChild_(
      tree_with_root_that_has_only_right_child.root, tree.Find(7)));
  ASSERT_FALSE(tree_with_root_that_has_only_right_child.Find(7));
  /*        ________[11]
  //       /
  */
  ASSERT_EQ(tree_with_root_that_has_only_right_child.root->data, 11);
  ASSERT_FALSE(tree_with_root_that_has_only_right_child.root->parent);
  ASSERT_FALSE(tree_with_root_that_has_only_right_child.root->is_left_node);
}
TEST_F(NodeRemoverFunctionsCollection,
       RemoveNodeWithOnlyRightChildUsingRemoveNode) {
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
  // remove a node with only left child
  ASSERT_EQ(tree.RemoveNode(tree.root, tree.Find(3)), tree.Find(7));
  /*        ________[7]______
  //       /                 \
  //      [5]             __[11]_
  //                     /       \
  //                   [9]       [13]
  */
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
  Tree tree_with_root_that_has_only_right_child({7, 11});
  ASSERT_FALSE(tree.RemoveNode(tree_with_root_that_has_only_right_child.root,
                          tree_with_root_that_has_only_right_child.Find(7)));
  ASSERT_FALSE(tree_with_root_that_has_only_right_child.Find(7));
  /*        ________[11]
  //       /
  */
  ASSERT_EQ(tree_with_root_that_has_only_right_child.root->data, 11);
  ASSERT_FALSE(tree_with_root_that_has_only_right_child.root->parent);
  ASSERT_FALSE(tree_with_root_that_has_only_right_child.root->is_left_node);
}

TEST_F(NodeRemoverFunctionsCollection,
       RemoveNodeWithOnlyLeftChildUsingPrivateHelper) {
  /*        ________[7]_______
  //       /                  \
  //     _[3]__            __[11]_
  //    /      \          /       \
  //  [1]      [5]X      [9]       [13]
  // prepare to have a Node with only left child
  */
  tree.Remove(5);
  /*        ________[7]_______
  //       /                  \
  //     _[3]X             __[11]_
  //    /                 /       \
  //  [1]               [9]       [13]
  */
  // remove a node with onlu left child
  ASSERT_EQ(tree.RemoveNodeWithOnlyLeftChild_(tree.root, tree.Find(3)),
            tree.Find(7));
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
  Tree tree_with_root_that_has_only_left_child({7, 1});
  ASSERT_FALSE(tree.RemoveNodeWithOnlyLeftChild_(
      tree_with_root_that_has_only_left_child.root,
      tree_with_root_that_has_only_left_child.Find(7)));
  ASSERT_FALSE(tree_with_root_that_has_only_left_child.Find(7));
  /*        ________[1]
  //       /
  */
  ASSERT_EQ(tree_with_root_that_has_only_left_child.root->data, 1);
  ASSERT_FALSE(tree_with_root_that_has_only_left_child.root->parent);
  ASSERT_FALSE(tree_with_root_that_has_only_left_child.root->is_left_node);
}
TEST_F(NodeRemoverFunctionsCollection,
       RemoveNodeWithOnlyLeftChildUsingRemoveNode) {
  /*        ________[7]_______
  //       /                  \
  //     _[3]__            __[11]_
  //    /      \          /       \
  //  [1]      [5]X      [9]       [13]
  // prepare to have a Node with only left child
  */
  tree.Remove(5);
  /*        ________[7]_______
  //       /                  \
  //     _[3]X             __[11]_
  //    /                 /       \
  //  [1]               [9]       [13]
  */
  // remove a node with onlu left child
  ASSERT_EQ(tree.RemoveNode(tree.root, tree.Find(3)), tree.Find(7));
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
  Tree tree_with_root_that_has_only_left_child({7, 1});
  ASSERT_FALSE(tree.RemoveNode(tree_with_root_that_has_only_left_child.root,
                          tree_with_root_that_has_only_left_child.Find(7)));
  /*        ________[1]
  //       /
  */
  ASSERT_EQ(tree_with_root_that_has_only_left_child.root->data, 1);
  ASSERT_FALSE(tree_with_root_that_has_only_left_child.root->parent);
  ASSERT_FALSE(tree_with_root_that_has_only_left_child.root->is_left_node);
}

TEST_F(NodeRemoverFunctionsCollection,
       RemoveNodeWithTwoChildrenNodeIsALeftChildUsingPrivateHelper) {
  /*        ________[7]_______
  //       /                  \
  //     _[3]X_            __[11]_
  //    /      \          /       \
  //  [1]      [5]      [9]       [13]
  */
  ASSERT_EQ(tree.RemoveNodeWithTwoChildren_(tree.root, tree.Find(3)), tree.Find(7));
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
TEST_F(NodeRemoverFunctionsCollection,
       RemoveNodeWithTwoChildrenNodeIsALeftChildUsingRemoveNode) {
  /*        ________[7]_______
  //       /                  \
  //     _[3]X_            __[11]_
  //    /      \          /       \
  //  [1]      [5]      [9]       [13]
  */
  ASSERT_EQ(tree.RemoveNode(tree.root, tree.Find(3)), tree.Find(7));
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

TEST_F(NodeRemoverFunctionsCollection,
       RemoveNodeWithTwoChildrenNodeIsARightChildUsingPrivateHelper) {
  //        ________[7]_______
  //       /                  \
    //     _[3]__            __[11]X_
  //    /      \          /       \
    //  [1]      [5]      [9]       [13]
  ASSERT_EQ(tree.RemoveNodeWithTwoChildren_(tree.root, tree.Find(11)), tree.Find(7));
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
TEST_F(NodeRemoverFunctionsCollection,
       RemoveNodeWithTwoChildrenNodeIsARightChildUsingRemoveNode) {
  //        ________[7]_______
  //       /                  \
    //     _[3]__            __[11]X_
  //    /      \          /       \
    //  [1]      [5]      [9]       [13]
  ASSERT_EQ(tree.RemoveNode(tree.root, tree.Find(11)), tree.Find(7));
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

TEST_F(NodeRemoverFunctionsCollection,
       RemoveNodeWithTwoChildrenNodeIsTheRootUsingPrivateHelper) {
  //        ________[7]X______
  //       /                  \
    //     _[3]__            __[11]_
  //    /      \          /       \
    //  [1]      [5]      [9]       [13]

  ASSERT_FALSE(tree.RemoveNodeWithTwoChildren_(tree.root, tree.Find(7)));
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
TEST_F(NodeRemoverFunctionsCollection,
       RemoveNodeWithTwoChildrenNodeIsTheRootUsingRemoveNode) {
  //        ________[7]X______
  //       /                  \
    //     _[3]__            __[11]_
  //    /      \          /       \
    //  [1]      [5]      [9]       [13]

  ASSERT_FALSE(tree.RemoveNode(tree.root, tree.Find(7)));
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

TEST_F(
    NodeRemoverFunctionsCollection,
    RemoveNodeWithTwoChildrenHasRecursaiveCallToOtherRemoveFunctionsUsingPrivateHelper) {
  /*        ________[7]_______
  //       /                  \
  //     _[3]__            __[11]_
  //    /      \          /       \
  //  [1]      [5]      [9]       [13]
  */
  tree.Insert({2, 4, 6, 8, 10, 14});

  /*        ________[7]_______
  //       /                  \
  //     _[3]X_            __[11]_
  //    /      \          /       \
  //  [1]     _[5]_     [9]       [13]
  //    \    /     \    /  \         \
  //    [2] [4]   [6]  [8] [10]     [14]
  */

  ASSERT_EQ(tree.RemoveNodeWithTwoChildren_(tree.root, tree.Find(3)), tree.Find(7));
  ASSERT_FALSE(tree.Find(3));
  /*        ________[7]_______
  //       /                  \
  //     _[4]_             _[11]_
  //    /      \          /      \
  //  [1]      [5]_     [9]      [13]
  //    \          \    /  \       \
  //    [2]       [6]  [8] [10]    [14]
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
  //     _[4]_             _[11]X_
  //    /     \           /       \
  //  [1]      [5]_     [9]       [13]
  //    \          \    /  \         \
  //    [2]       [6]  [8] [10]     [14]
  */
  ASSERT_EQ(tree.RemoveNodeWithTwoChildren_(tree.root, tree.Find(11)), tree.Find(7));
  ASSERT_FALSE(tree.Find(11));
  /*        ________[7]______
  //       /                 \
  //     _[4]_            _[13]__
  //    /     \          /       \
  //  [1]      [5]_    [9]       [14]
  //    \          \   /  \
  //    [2]       [6] [8] [10]
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
    NodeRemoverFunctionsCollection,
    RemoveNodeWithTwoChildrenHasRecursaiveCallToOtherRemoveFunctionsUsingRemoveNode) {
  /*        ________[7]_______
  //       /                  \
  //     _[3]__            __[11]_
  //    /      \          /       \
  //  [1]      [5]      [9]       [13]
  */
  tree.Insert({2, 4, 6, 8, 10, 14});

  /*        ________[7]_______
  //       /                  \
  //     _[3]X_            __[11]_
  //    /      \          /       \
  //  [1]     _[5]_     [9]       [13]
  //    \    /     \    /  \         \
  //    [2] [4]   [6]  [8] [10]     [14]
  */

  ASSERT_EQ(tree.RemoveNode(tree.root, tree.Find(3)), tree.Find(7));
  ASSERT_FALSE(tree.Find(3));
  /*        ________[7]_______
  //       /                  \
  //     _[4]_             _[11]_
  //    /      \          /      \
  //  [1]      [5]_     [9]      [13]
  //    \          \    /  \       \
  //    [2]       [6]  [8] [10]    [14]
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
  //     _[4]_             _[11]X_
  //    /     \           /       \
  //  [1]      [5]_     [9]       [13]
  //    \          \    /  \         \
  //    [2]       [6]  [8] [10]     [14]
  */
  ASSERT_EQ(tree.RemoveNode(tree.root, tree.Find(11)), tree.Find(7));
  ASSERT_FALSE(tree.Find(11));
  /*        ________[7]______
  //       /                 \
  //     _[4]_            _[13]__
  //    /     \          /       \
  //  [1]      [5]_    [9]       [14]
  //    \          \   /  \
  //    [2]       [6] [8] [10]
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
}

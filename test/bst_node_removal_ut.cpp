//
//  bst_node_removal_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-10-26.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

//#include "bst.cpp"
#include "bst.hpp"
#include "gtest/gtest.h"

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
        //        ________[7]_______
        //       /                  \
        //     _[3]__            __[11]_
        //    /      \          /       \
        //  [1]      [5]      [9]       [13]
    }
    virtual void TearDown(){};
    Tree tree;
};

TEST_F(BSTNodeRemoval, RemoveNodeWithNoChildren)
{
    //--------------------------------------------------------------
    //        ________[7]_______
    //       /                  \
    //     _[3]__            __[11]_
    //    /      \          /       \
    //  [1]X      [5]      [9]       [13]
    ASSERT_TRUE(tree.Find(1));
    ASSERT_TRUE(tree.Remove(1));
    ASSERT_FALSE(tree.Find(1));
    //        ________[7]_______
    //       /                  \
    //      [3]__            __[11]_
    //           \          /       \
    //           [5]      [9]       [13]
    //parent status after removing
    ASSERT_FALSE(tree.Find(3)->left.get());
    ASSERT_EQ(tree.Find(3)->right->data, 5);
    ASSERT_EQ(tree.Find(3)->parent->data, 7);
    //Sibling status after removing
    ASSERT_EQ(tree.Find(5)->parent->data, 3);

    //--------------------------------------------------------------
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
    //parent status after removing
    ASSERT_FALSE(tree.Find(11)->right.get());
    ASSERT_EQ(tree.Find(11)->left->data, 9);
    ASSERT_EQ(tree.Find(11)->parent->data, 7);
    //Sibling status after removing
    ASSERT_EQ(tree.Find(9)->parent->data, 11);

    //-------------------------------------------------------------- (root case)
    //        ________[7]_______
    //       /                  \
    //
    Tree tree_with_root_node_only(7);
    ASSERT_TRUE(tree_with_root_node_only.Remove(7));
    ASSERT_FALSE(tree_with_root_node_only.Find(7));
    ASSERT_FALSE(tree_with_root_node_only.root);

}

TEST_F(BSTNodeRemoval, RemoveNodeWithOnlyLeftChild)
{

    //        ________[7]_______
    //       /                  \
    //     _[3]__            __[11]_
    //    /      \          /       \
    //  [1]      [5]X      [9]       [13]
    //prepare to have a Node with only left child
    ASSERT_TRUE(tree.Find(5));
    ASSERT_TRUE(tree.Remove(5));
    ASSERT_FALSE(tree.Find(5));
    //        ________[7]_______
    //       /                  \
    //     _[3]X             __[11]_
    //    /                 /       \
    //  [1]               [9]       [13]
    //remove a node with onlu left child
    ASSERT_TRUE(tree.Find(3));
    ASSERT_TRUE(tree.Remove(3));
    ASSERT_FALSE(tree.Find(3));
    //        ________[7]______
    //       /                 \
    //      [1]             __[11]_
    //                     /       \
    //                   [9]       [13]
    //Checks the tree status after removing the node
    //parent status after removing
    ASSERT_EQ(tree.Find(7)->left->data, 1);
    ASSERT_FALSE(tree.Find(7)->parent);
    //Sibling status after removing
    ASSERT_EQ(tree.Find(11)->parent->data, 7);
    ASSERT_EQ(tree.Find(11)->parent->left->data, 1);
    // check the new node
    ASSERT_EQ(tree.Find(1)->parent->data, 7);

    //NODE CASE //-----------------------------------------------------
}

TEST_F(BSTNodeRemoval, RemoveNodeWithOnlyRightChild)
{
    //--------------------------------------------------------------
    //        ________[7]_______
    //       /                  \
    //     _[3]__            __[11]_
    //    /      \          /       \
    //  [1]X      [5]      [9]       [13]
    //prepare to have a Node with only left child
    ASSERT_TRUE(tree.Find(1));
    ASSERT_TRUE(tree.Remove(1));
    ASSERT_FALSE(tree.Find(1));
    //        ________[7]_______
    //       /                  \
    //      [3]X             __[11]_
    //         \            /       \
    //         [5]       [9]       [13]
    //remove a node with onlu left child
    ASSERT_TRUE(tree.Find(3));
    ASSERT_TRUE(tree.Remove(3));
    ASSERT_FALSE(tree.Find(3));

    //--------------------------------------------------------------
    //        ________[7]______
    //       /                 \
    //      [5]             __[11]_
    //                     /       \
    //                   [9]       [13]
    //Checks the tree status after removing the node
    //parent status after removing
    ASSERT_EQ(tree.Find(7)->left->data, 5);
    ASSERT_FALSE(tree.Find(7)->parent);
    //Sibling status after removing
    ASSERT_EQ(tree.Find(11)->parent->data, 7);
    ASSERT_EQ(tree.Find(11)->parent->left->data, 5);
    // check the new node
    ASSERT_EQ(tree.Find(5)->parent->data, 7);
    //NODE CASE //-----------------------------------------------------
}

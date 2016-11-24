//
//  rotator_ut.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-14.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "gtest/gtest.h"

#include "bst.hpp"
#include "rotator.hpp"


//TODO : test a one node tree and a node with only two nodes 


using namespace BSTNS;
using namespace BSTNS::Rotator;

class RotatorFunctionsCollections : public ::testing::Test {
public:
    virtual void SetUp() {};
    virtual void TearDown(){};
    Data x;
    Data y;
    Data x_left;
    Data x_right;
    Data y_left;
    Data y_right;
};

TEST_F(RotatorFunctionsCollections, RotateLeftAboutTheTreeRoot) {
    x = 2;
    x_left = 1;
    y = 4;
    y_left = 3;
    y_right = 5;
    Tree tree({x,x_left,y,y_left,y_right});
    /*        __[x=2]__
    //       /         \
    //   [xLeft=1]  _[y=4]_
    //             /       \
    //       [yLeft=3]  [yRight=5]
    */
    ASSERT_TRUE(RotateLeftAround(tree.root));
    /*             __[y=4]__
    //            /         \
    //        __[x=2]__  [yRight=5]
    //       /         \
    //   [xLeft=1]  [yLeft=3]
    */
    
    // tree connections after
    // |-Data
    ASSERT_EQ(tree.root->data, y);
    ASSERT_EQ(tree.root->left->data, x);
    ASSERT_EQ(tree.root->left->left->data, x_left);
    ASSERT_EQ(tree.root->left->right->data, y_left);
    ASSERT_EQ(tree.root->right->data, y_right);
    // |-Parents
    ASSERT_FALSE(tree.Find(y)->parent);
    ASSERT_EQ(tree.Find(x)->parent->data, y);
    ASSERT_EQ(tree.Find(y_right)->parent->data, y);
    ASSERT_EQ(tree.Find(x_left)->parent->data, x);
    ASSERT_EQ(tree.Find(y_left)->parent->data, x);
    // |-Left flag testing
    ASSERT_FALSE(tree.Find(y)->is_left_node);
    ASSERT_FALSE(tree.Find(y_left)->is_left_node);
    ASSERT_FALSE(tree.Find(y_right)->is_left_node);
    ASSERT_TRUE(tree.Find(x)->is_left_node);
    ASSERT_TRUE(tree.Find(x_left)->is_left_node);
}

TEST_F(RotatorFunctionsCollections, RotateLeftAboutLeftChild) {
    x = 2;
    x_left = 1;
    y = 4;
    y_left = 3;
    y_right = 5;
    Tree tree({6,7,x,x_left,y,y_left,y_right});
    /*
     //             __[6]__
     //            /       \
     //        __[x=2]__   [7]
     //       /         \
     //   [xLeft=1]  _[y=4]_
     //             /       \
     //       [yLeft=3]  [yRight=5]
     */
    ASSERT_TRUE(RotateLeftAround(tree.root->left));
    /*
     //                  __[6]__
     //                 /       \
     //             __[y=4]__   [7]
     //            /         \
     //        __[x=2]__  [yRight=5]
     //       /         \
     //   [xLeft=1]  [yLeft=3]
     */
    
    // tree connections after
    // |-Data
    ASSERT_EQ(tree.root->data, 6);
    ASSERT_EQ(tree.root->right->data, 7);
    ASSERT_EQ(tree.root->left->data, y);
    ASSERT_EQ(tree.root->left->left->data, x);
    ASSERT_EQ(tree.root->left->left->left->data, x_left);
    ASSERT_EQ(tree.root->left->left->right->data, y_left);
    ASSERT_EQ(tree.root->left->right->data, y_right);
    // |-Parents
    ASSERT_FALSE(tree.Find(6)->parent);
    ASSERT_EQ(tree.Find(7)->parent->data, 6);
    ASSERT_EQ(tree.Find(y)->parent->data, 6);
    ASSERT_EQ(tree.Find(x)->parent->data, y);
    ASSERT_EQ(tree.Find(y_right)->parent->data, y);
    ASSERT_EQ(tree.Find(x_left)->parent->data, x);
    ASSERT_EQ(tree.Find(y_left)->parent->data, x);
    // |-Left flag testing
    ASSERT_FALSE(tree.Find(6)->is_left_node);
    ASSERT_FALSE(tree.Find(7)->is_left_node);
    ASSERT_FALSE(tree.Find(y_left)->is_left_node);
    ASSERT_FALSE(tree.Find(y_right)->is_left_node);
    ASSERT_TRUE(tree.Find(y)->is_left_node);
    ASSERT_TRUE(tree.Find(x)->is_left_node);
    ASSERT_TRUE(tree.Find(x_left)->is_left_node);

}

TEST_F(RotatorFunctionsCollections, RotateLeftAboutTheRightChild) {
    x = 2;
    x_left = 1;
    y = 4;
    y_left = 3;
    y_right = 5;
    Tree tree({-1,-2,x,x_left,y,y_left,y_right});
    /*
     //     _[-1]__
     //    /       \
     //  [-2]  __[x=2]__
     //       /         \
     //   [xLeft=1]  _[y=4]_
     //             /       \
     //       [yLeft=3]  [yRight=5]
     */
    ASSERT_TRUE(RotateLeftAround(tree.root->right));
    /*
     //      ____[-1]__
     //     /          \
     //  [-2]       __[y=4]__
     //            /         \
     //        __[x=2]__  [yRight=5]
     //       /         \
     //   [xLeft=1]  [yLeft=3]
     */
    // tree connections after
    // |-Data
    ASSERT_EQ(tree.root->data, -1);
    ASSERT_EQ(tree.root->left->data, -2);
    ASSERT_EQ(tree.root->right->data, y);
    ASSERT_EQ(tree.root->right->left->data, x);
    ASSERT_EQ(tree.root->right->left->left->data, x_left);
    ASSERT_EQ(tree.root->right->left->right->data, y_left);
    ASSERT_EQ(tree.root->right->right->data, y_right);
    // |-Parents
    ASSERT_FALSE(tree.Find(-1)->parent);
    ASSERT_EQ(tree.Find(y)->parent->data, -1);
    ASSERT_EQ(tree.Find(x)->parent->data, y);
    ASSERT_EQ(tree.Find(y_right)->parent->data, y);
    ASSERT_EQ(tree.Find(x_left)->parent->data, x);
    ASSERT_EQ(tree.Find(y_left)->parent->data, x);
    // |-Left flag testing
    ASSERT_FALSE(tree.Find(-1)->is_left_node);
    ASSERT_FALSE(tree.Find(y_left)->is_left_node);
    ASSERT_FALSE(tree.Find(y_right)->is_left_node);
    ASSERT_FALSE(tree.Find(y)->is_left_node);
    ASSERT_TRUE(tree.Find(x)->is_left_node);
    ASSERT_TRUE(tree.Find(x_left)->is_left_node);
}


TEST_F(RotatorFunctionsCollections, RotateRightAboutTheTreeRoot) {
    y = 4;
    y_right = 5;
    x = 2;
    x_left = 1;
    x_right = 3;
    Tree tree({y,y_right,x,x_left,x_right});
    
    /*             __[y=4]__
    //            /         \
    //        __[x=2]__  [yRight=5]
    //       /         \
    //   [xLeft=1]  [xRight=3]
    */
    ASSERT_TRUE(RotateRightAround(tree.root));
    /*        __[x=2]__
    //       /         \
    //   [xLeft=1]   _[y=4]_
    //              /       \
    //         [xRight=3] [yRight=5]
    */
    
    // tree connections after
    // |-Data
    ASSERT_EQ(tree.root->data, x);
    ASSERT_EQ(tree.root->left->data, x_left);
    ASSERT_EQ(tree.root->right->data, y);
    ASSERT_EQ(tree.root->right->left->data, x_right);
    ASSERT_EQ(tree.root->right->right->data, y_right);
    // |-Parents
    ASSERT_FALSE(tree.Find(x)->parent);
    ASSERT_EQ(tree.Find(x_left)->parent->data, x);
    ASSERT_EQ(tree.Find(y)->parent->data, x);
    ASSERT_EQ(tree.Find(x_right)->parent->data, y);
    ASSERT_EQ(tree.Find(y_right)->parent->data, y);
    
    // |-Left flag testing
    ASSERT_FALSE(tree.Find(x)->is_left_node);
    ASSERT_FALSE(tree.Find(y)->is_left_node);
    ASSERT_FALSE(tree.Find(y_right)->is_left_node);
    ASSERT_TRUE(tree.Find(x_left)->is_left_node);
    ASSERT_TRUE(tree.Find(x_right)->is_left_node);
}

TEST_F(RotatorFunctionsCollections, RotateRightAboutLeftChild)
{
    y = 4;
    y_right = 5;
    x = 2;
    x_left = 1;
    x_right = 3;
    Tree tree({6,7,y,y_right,x,x_left,x_right});
    
    /* 
    //                   __[6]__
    //                  /       \
    //             __[y=4]__   [7]
    //            /         \
    //        __[x=2]__  [yRight=5]
    //       /         \
    //   [xLeft=1]  [xRight=3]
    */
    ASSERT_TRUE(RotateRightAround(tree.root->left));
    /*
    //              __[6]__
    //             /       \
    //        __[x=2]__   [7]
    //       /         \
    //   [xLeft=1]   _[y=4]_
    //              /       \
    //          [xRight=3] [yRight=5]
    */
    
    // tree connections after
    // |-Data
    ASSERT_EQ(tree.root->data, 6);
    ASSERT_EQ(tree.root->right->data, 7);
    ASSERT_EQ(tree.root->left->data, x);
    ASSERT_EQ(tree.root->left->left->data, x_left);
    ASSERT_EQ(tree.root->left->right->data, y);
    ASSERT_EQ(tree.root->left->right->left->data, x_right);
    ASSERT_EQ(tree.root->left->right->right->data, y_right);
    // |-Parents
    ASSERT_FALSE(tree.Find(6)->parent);
    ASSERT_EQ(tree.Find(7)->parent->data, 6);
    ASSERT_EQ(tree.Find(x)->parent->data ,6);
    ASSERT_EQ(tree.Find(x_left)->parent->data, x);
    ASSERT_EQ(tree.Find(y)->parent->data, x);
    ASSERT_EQ(tree.Find(x_right)->parent->data, y);
    ASSERT_EQ(tree.Find(y_right)->parent->data, y);
    // |-Left flag testing
    ASSERT_FALSE(tree.Find(6)->is_left_node);
    ASSERT_FALSE(tree.Find(7)->is_left_node);
    ASSERT_TRUE(tree.Find(x)->is_left_node);
    ASSERT_FALSE(tree.Find(y)->is_left_node);
    ASSERT_FALSE(tree.Find(y_right)->is_left_node);
    ASSERT_TRUE(tree.Find(x_left)->is_left_node);
    ASSERT_TRUE(tree.Find(x_right)->is_left_node);
}

TEST_F(RotatorFunctionsCollections, RotateRightAboutTheRightChild){
    y = 4;
    y_right = 5;
    x = 2;
    x_left = 1;
    x_right = 3;
    Tree tree({-1,-2,y,y_right,x,x_left,x_right});
    /*
    //       __[-1]__
    //      /        \
    //    [-2]   __[y=4]__
    //          /         \
    //      __[x=2]__  [yRight=5]
    //     /         \
    // [xLeft=1]  [xRight=3]
    */
    ASSERT_TRUE(RotateRightAround(tree.root->right));
    /*
    //       __[-1]__
    //      /        \
    //   [-2]    __[x=2]__
    //          /         \
    //     [xLeft=1]    _[y=4]_
    //                 /       \
    //            [xRight=3] [yRight=5]
    */

    // tree connections after
    // |-Data
    ASSERT_EQ(tree.root->data, -1);
    ASSERT_EQ(tree.root->left->data, -2);
    ASSERT_EQ(tree.root->right->data, x);
    ASSERT_EQ(tree.root->right->left->data, x_left);
    ASSERT_EQ(tree.root->right->right->data, y);
    ASSERT_EQ(tree.root->right->right->left->data, x_right);
    ASSERT_EQ(tree.root->right->right->right->data, y_right);
    // |-Parents
    ASSERT_FALSE(tree.Find(-1)->parent);
    ASSERT_EQ(tree.Find(-2)->parent->data, -1);
    ASSERT_EQ(tree.Find(x)->parent->data ,-1);
    ASSERT_EQ(tree.Find(x_left)->parent->data, x);
    ASSERT_EQ(tree.Find(y)->parent->data, x);
    ASSERT_EQ(tree.Find(x_right)->parent->data, y);
    ASSERT_EQ(tree.Find(y_right)->parent->data, y);
    // |-Left flag testing
    ASSERT_FALSE(tree.Find(-1)->is_left_node);
    ASSERT_TRUE(tree.Find(-2)->is_left_node);
    ASSERT_FALSE(tree.Find(x)->is_left_node);
    ASSERT_FALSE(tree.Find(y)->is_left_node);
    ASSERT_FALSE(tree.Find(y_right)->is_left_node);
    ASSERT_TRUE(tree.Find(x_left)->is_left_node);
    ASSERT_TRUE(tree.Find(x_right)->is_left_node);
}

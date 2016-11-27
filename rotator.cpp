//
//  rotator.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-14.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "rotator.hpp"

namespace BSTNS {
namespace Rotator {
Node* RotateLeftAround(NodeUPtr &pivot_node) {
  /*        __[x]__
  //       /       \
  //   [xLeft]    _[y]_
  //             /     \
  //         [yLeft]  [yRight]
  */

  /*        __[y]__
  //       /       \
  //    _[x]_    [yRight]
  //   /     \
  //[xLeft]  [yLeft]
  */

  if (pivot_node and pivot_node->right) {
    Node *pivot_node_parent = pivot_node->parent;

    // Get all tree info before moving things around
    NodeUPtr x;
    bool old_pivot_is_left_node_status = pivot_node->is_left_node;
    // TODO : change to lamda
    if (pivot_node->is_left_node) {
      x = std::move(pivot_node_parent->left);
    } else if (!pivot_node->is_left_node && pivot_node_parent) {
      x = std::move(pivot_node_parent->right);
    } else {
      x = std::move(pivot_node);
    }
    
    //Rotating
    //y
    auto y = std::move(x->right);
    y->parent= pivot_node_parent;
    y->is_left_node = old_pivot_is_left_node_status;
    // y_left
    if(y->left){
        x->right = std::move(y->left);
        x->right->parent = x.get(); //potintial Error if x_right null
        x->right->is_left_node = false;
    }
    // x
    y->left = std::move(x);
    y->left->parent = y.get();
    y->left->is_left_node = true;

    
    pivot_node = std::move(y);
      return pivot_node->left.get();// retrun the old pivot node since it is the lower node to that require a height update

  } else {
    return nullptr;
  }
}

Node* RotateRightAround(NodeUPtr &pivot_node) {
   /*        __[y]__
   //       /       \
   //    _[x]_    [yRight]
   //   /     \
   //[xLeft]  [xRight]
   */
   
   //After Right Rotation
  
   /*        __[x]__
   //       /       \
   //   [xLeft]    _[y]_
   //             /     \
   //         [xRight]  [yRight]
   */

  if (pivot_node and pivot_node->left) {
    Node *pivot_node_parent = pivot_node->parent;

    // Get all tree info before moving things around
    NodeUPtr y;
    bool old_pivot_is_left_node_status = pivot_node->is_left_node;
    // TODO : change to lamda
    if (pivot_node->is_left_node) {
      y = std::move(pivot_node_parent->left);
    } else if (!pivot_node->is_left_node && pivot_node_parent) {
      y = std::move(pivot_node_parent->right);
    } else {
      y = std::move(pivot_node);
    }
    
    //Rotating
    //x
    auto x = std::move(y->left);
    x->parent = pivot_node_parent;
    x->is_left_node = old_pivot_is_left_node_status;
    //xRight
     if(x->right){
    y->left = std::move(x->right);
    y->left->parent = y.get();
    y->left->is_left_node = true;
    }
      //y
    x->right = std::move(y);
    x->right->parent = x.get();
    x->right->is_left_node = false;
    
      pivot_node = std::move(x);
    return pivot_node->right.get(); // retrun the old pivot node since it is the lower node to that require a height update
  } else {
    return nullptr;
  }
}
}  // End of Rotator::
}  // End of Rotator::













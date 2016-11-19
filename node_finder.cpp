//
//  node_finder.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "node_finder.hpp"

namespace BSTNS {
namespace NodeFinder {
Node *Find(Node *const current_root, const Data &target)
// if the node is not found it returns a nullptr , no error massage
{
  if (!current_root) {
    return nullptr;
  } else if (target > current_root->data) {
    return Find(current_root->right.get(), target);
  } else if (target < current_root->data) {
    return Find(current_root->left.get(), target);
  } else if (target == current_root->data) {
    return current_root;
  } else {
    // TODO :  impliment an error MSG
    assert(0);
  }
}

Node *FindMin(Node *const current_node) {
  if (!current_node->left) {
    return current_node;
  } else {
    return FindMin(current_node->left.get());
  }
}

Node *FindMax(Node *const current_node) {
  if (!current_node->right) {
    return current_node;
  } else {
    return FindMax(current_node->right.get());
  }
}
}  // End NodeFinder::
}  // End BSTNS::

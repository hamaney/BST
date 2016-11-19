//
//  node_connections_checker_class.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "node_connections_checker.hpp"

namespace BSTNS {
namespace NodeConnectionsChecker {
bool HasNoChildren(const Node *const node) {
  if (node) {
    return (!node->left and !node->right);
  } else {
    return false;
  }
}

bool HasTwoChildren(const Node *const node) {
  if (node) {
    return (node->left and node->right);
  } else {
    return false;
  }
}

bool HasOnlyLeftChild(const Node *const node) {
  if (node) {
    return (node->left and !node->right);
  } else {
    return false;
  }
}

bool HasOnlyRightChild(const Node *const node) {
  if (node) {
    return (!node->left and node->right);
  } else {
    return false;
  }
}
}  // End NodeConnectionsChecker::
}  // End BSTNS::

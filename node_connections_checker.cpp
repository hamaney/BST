//
//  node_connections_checker_class.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "node_connections_checker.hpp"

// does not check if the key exist
bool NodeConnectionsChecker::HasNoChildren(const Node *const node) const {
  if (node) {
    return (!node->left and !node->right);
  } else {
    return false;
  }
}

bool NodeConnectionsChecker::HasTwoChildren(const Node *const node) const {
  if (node) {
    return (node->left and node->right);
  } else {
    return false;
  }
}

bool NodeConnectionsChecker::HasOnlyLeftChild(const Node *const node) const {
  if (node) {
    return (node->left and !node->right);
  } else {
    return false;
  }
}

bool NodeConnectionsChecker::HasOnlyRightChild(const Node *const node) const {
  if (node) {
    return (!node->left and node->right);
  } else {
    return false;
  }
}

//
//  node_inserter.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-21.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "node_inserter.hpp"
/*
using namespace BSTNS::NodeInserter::PrivateHelper;
namespace BSTNS {
namespace NodeInserter {

Node* InsertValue(NodeUPtr& current_root, const Data& entry) {
  if (!current_root) {
    current_root = NodeFactory_(entry);
    return current_root->parent;
    // OR return nullptr;
  }

  else if (entry > current_root->data) {
    if (!current_root->right) {
      current_root->right = NodeFactory_(entry);
      current_root->right->parent = current_root.get();
      return current_root.get();
    } else {
      return InsertValue(current_root->right, entry);
    }

  } else if (entry < current_root->data) {
    if (!current_root->left) {
      current_root->left = NodeFactory_(entry);
      current_root->left->parent = current_root.get();
      current_root->left->is_left_node = true;
      return current_root.get();
    } else {
      return InsertValue(current_root->left, entry);
    }

  } else {
    return nullptr;
  }
}

namespace PrivateHelper {
NodeUPtr NodeFactory_(const Data& entry) {
  return std::make_unique<Node>(entry);
}
}  // End PrivateHelper::
}  // End NodeInserter::
}  // End BSTNS::
*/

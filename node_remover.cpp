//
//  node_remover.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "node_remover.hpp"

// Full path fo clearty
using namespace BSTNS::NodeConnectionsChecker;
using namespace BSTNS::NodeFinder;
using namespace BSTNS::NodeRemover::PrivateHelper;

namespace BSTNS {
namespace NodeRemover {

Node *RemoveNode(NodeUPtr &tree_root, Node *node_to_remove) {
  if (node_to_remove && tree_root) {
    if (HasNoChildren(node_to_remove)) {
      return RemoveNodeWithNoChildren_(tree_root, node_to_remove);
    } else if (HasTwoChildren(node_to_remove)) {
      return RemoveNodeWithTwoChildren_(tree_root, node_to_remove);
    } else if (HasOnlyLeftChild(node_to_remove)) {
      return RemoveNodeWithOnlyLeftChild_(tree_root, node_to_remove);
    } else if (HasOnlyRightChild(node_to_remove)) {
      return RemoveNodeWithOnlyRightChild_(tree_root, node_to_remove);
    } else {
      assert(0);
    }
  } else {
    return nullptr;
  }
}

namespace PrivateHelper {

Node *RemoveNodeWithNoChildren_(NodeUPtr &tree_root, Node *node_to_remove) {
  auto parent = node_to_remove->parent;
  if (!parent) {
    tree_root.reset();
  } else {
    if (node_to_remove->is_left_node) {
      parent->left.reset();
    } else {
      parent->right.reset();
    }
  }
  return parent;
}
// TODO: make a choise based on leftheavey or right heavy node
Node *RemoveNodeWithTwoChildren_(NodeUPtr &tree_root, Node *node_to_remove) {
  auto node_to_remove_parent = node_to_remove->parent;
  auto right_branch_min_value_node = FindMin(node_to_remove->right.get());
  node_to_remove->data = right_branch_min_value_node->data;
  // calling a remove on a leaf or one with no left node
  // might call recursivly until it remove a leaf
  // height will be updated when the node leaf is removed
  RemoveNode(tree_root, right_branch_min_value_node);
  return node_to_remove_parent;  // only for the fist node this function is
                                 // called with
}
Node *RemoveNodeWithOnlyLeftChild_(NodeUPtr &tree_root, Node *node_to_remove) {
  auto parent = node_to_remove->parent;

  if (!parent) {
    tree_root = std::move(tree_root->left);
    tree_root->parent = nullptr;
    tree_root->is_left_node = false;
    // no need to update the hight in this case
  } else {
    if (node_to_remove->is_left_node) {
      parent->left = std::move(node_to_remove->left);
      parent->left->parent = parent;

    } else {
      parent->right = std::move(node_to_remove->left);
      parent->right->parent = parent;
      parent->right->is_left_node = false;
    }
  }

  return parent;
}
Node *RemoveNodeWithOnlyRightChild_(NodeUPtr &tree_root, Node *node_to_remove) {
  auto parent = node_to_remove->parent;
  if (!parent) {
    tree_root = std::move(tree_root->right);
    tree_root->parent = nullptr;
    // no need to update the hight in this case nor the position of the node
    // since root and right node are both have is_left_node = false
  } else {
    if (node_to_remove->is_left_node) {
      parent->left = std::move(node_to_remove->right);
      parent->left->parent = parent;
      parent->left->is_left_node = true;
    } else {
      parent->right = std::move(node_to_remove->right);
      parent->right->parent = parent;
    }
  }

  return parent;
}
}  // End of PrivateHelper::
}  // End of NodeRemover::
}  // End of BSTNS:

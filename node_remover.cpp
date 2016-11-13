//
//  node_remover.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "node_remover.hpp"
bool NodeRemover::Remove(NodeUPtr &tree_root, Node *node_to_remove) {
  if (node_to_remove) {
    if (connection_checker_.HasNoChildren(node_to_remove)) {
      return RemoveNodeWithNoChildren_(tree_root, node_to_remove);
    } else if (connection_checker_.HasTwoChildren(node_to_remove)) {
      return RemoveNodeWithTwoChildren_(tree_root, node_to_remove);
    } else if (connection_checker_.HasOnlyLeftChild(node_to_remove)) {
      return RemoveNodeWithOnlyLeftChild_(tree_root, node_to_remove);
    } else if (connection_checker_.HasOnlyRightChild(node_to_remove)) {
      return RemoveNodeWithOnlyRightChild_(tree_root, node_to_remove);
    } else {
      assert(0);
      return false;
    }
  } else {
    return false;
  }
}
bool NodeRemover::RemoveNodeWithNoChildren_(NodeUPtr &tree_root,
                                            Node *node_to_remove) {
  auto parent = node_to_remove->parent;
  if (!parent) {
    tree_root.reset();
    height_updater_.UpdateHeightOfNodeRecursively(tree_root.get());
    return true;
  } else {
    if (node_to_remove->is_left_node) {
      parent->left.reset();
      height_updater_.UpdateHeightOfNodeRecursively(parent);
      height_updater_.UpdateParentsHeightAfterRemovingANode(parent);
      return true;
    } else {
      parent->right.reset();
      height_updater_.UpdateHeightOfNodeRecursively(parent);
      height_updater_.UpdateParentsHeightAfterRemovingANode(parent);
      return true;
    }
  }
}
// TODO: make a choise based on leftheavey or right heavy node
bool NodeRemover::RemoveNodeWithTwoChildren_(NodeUPtr &tree_root,
                                             Node *node_to_remove) {
  Node *right_branch_min_value_node =
      node_finder_.FindMin(node_to_remove->right.get());
  node_to_remove->data = right_branch_min_value_node->data;
  return Remove(tree_root,
                right_branch_min_value_node);  // calling a remove on a leaf
  // node will update the height of the branch where the leaf is
}

bool NodeRemover::RemoveNodeWithOnlyLeftChild_(NodeUPtr &tree_root,
                                               Node *node_to_remove) {
  Node *parent = node_to_remove->parent;

  if (!parent) {
    tree_root = std::move(tree_root->left);
    tree_root->parent = nullptr;
    tree_root->is_left_node = false;  // Extra just to be sure
    // no need to update the hight in this case
    return true;
  } else {
    if (node_to_remove->is_left_node) {
      parent->left = std::move(node_to_remove->left);
      parent->left->parent = parent;
      // height_updater_.UpdateParentsHeightAfterRemovingANode(parent->left.get());
      return true;
    } else {
      parent->right = std::move(node_to_remove->left);
      parent->right->parent = parent;
      parent->right->is_left_node = false;
      // height_updater_.UpdateParentsHeightAfterRemovingANode(parent->right.get());
      return true;
    }
  }
}
bool NodeRemover::RemoveNodeWithOnlyRightChild_(NodeUPtr &tree_root,
                                                Node *node_to_remove) {
  Node *parent = node_to_remove->parent;
  if (!parent) {
    tree_root = std::move(tree_root->right);
    tree_root->parent = nullptr;
    tree_root->is_left_node = false;  // Extra just to be sure
    // no need to update the hight in this case
    return true;
  } else {
    if (node_to_remove->is_left_node) {
      parent->left = std::move(node_to_remove->right);
      parent->left->parent = parent;
      parent->left->is_left_node = true;
      // height_updater_.UpdateParentsHeightAfterRemovingANode(parent->left.get());
      return true;
    } else {
      parent->right = std::move(node_to_remove->right);
      parent->right->parent = parent;
      // height_updater_.UpdateParentsHeightAfterRemovingANode(parent->right.get());
      return true;
    }
  }
}

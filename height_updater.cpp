//
//  tree_nodes_height_updater.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "height_updater.hpp"

// Node Height Updater
Height HeightUpdater::UpdateHeightOfNodeRecursively(Node *node) {
  if (!node) {
    return -1;
  } else {
    Height left_child_node_height =
        UpdateHeightOfNodeRecursively(node->left.get());
    Height right_child_node_height =
        UpdateHeightOfNodeRecursively(node->right.get());
    node->height =
        std::max(left_child_node_height, right_child_node_height) + 1;
    return node->height;
  }
}

Height HeightUpdater::UpdateHeightOfNodeNonRecursively(Node *node) {
  if (!node) {
    assert(0);
  } else {
    Height left_child_node_height, right_child_node_height;
    if (!node->left) {
      left_child_node_height = -1;
    } else {
      left_child_node_height = node->left->height;
    }
    if (!node->right) {
      right_child_node_height = -1;
    } else {
      right_child_node_height = node->right->height;
    }
    node->height =
        std::max(left_child_node_height, right_child_node_height) + 1;
    return node->height;
  }
}
// Upper Parents Hight Updateder
// After Adding a node
void HeightUpdater::UpdateParentsHeightAfterAddingANode(Node *node) {
  if (node->parent) {
    if (node->parent->height < (node->height + 1)) {
      node->parent->height = node->height + 1;
      UpdateParentsHeightAfterAddingANode(node->parent);
    }
  }
}

// After removing a node
void HeightUpdater::UpdateParentsHeightAfterRemovingANode(Node *node) {
  if (node and node->parent) {
    Node *parent = node->parent;
    Height node_height = node->height;
    Height node_parent_height = node->parent->height;
    if ((node_height + 2) < node_parent_height) {
      // skip updating
    } else if ((node_height + 2) == node_parent_height) {
      // sibling cases
      Height node_sibling_height;
      if (connection_checker_.HasOnlyLeftChild(parent) or
          connection_checker_.HasOnlyRightChild(parent)) {
        node_sibling_height = -1;
      } else if (node->is_left_node) {
        node_sibling_height = parent->right->height;
      } else if (!node->is_left_node) {
        node_sibling_height = parent->left->height;
      } else {  // TODO : impl an assertion
        assert(0);
      }
      // Check wheather to update the height or not
      if (node_height >= node_sibling_height) {
        parent->height = node_height + 1;
        UpdateParentsHeightAfterRemovingANode(parent);
      } else {
        // skip the update
      }
    } else {
    }
  }
}

//
//  tree_nodes_height_updater.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "height_updater.hpp"
#include <iostream>

using namespace BSTNS::NodeConnectionsChecker;
using namespace BSTNS::HeightUpdater::PrivateHelper;
namespace BSTNS {
namespace HeightUpdater {

void UpdateHeight(Node *node_parent) {
  Node *node = node_parent;  // jsut for clearfication

  if (node) {
    // read the update from down up
    UpdateHeightOfNodeNonRecursively_(node);
    // push updates upwared to parents
    UpdateTheParentsStartingFromParent_(node->parent);
  }
}

// TODO : change name to updateHeightOfNodeAndItsChildernRecursiveCall
// OR Update ChildTreesHeights
// OR UpdateNodeAndChildrenHieghtsRecussive
Height UpdateHeightOfNodeRecursively(Node *node) {
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
namespace PrivateHelper {
void UpdateHeightOfNodeNonRecursively_(Node *node) {
  if (node) {
    Height left_child_node_height(-1), right_child_node_height(-1);
    if (node->left) {
      left_child_node_height = node->left->height;
    }
    if (node->right) {
      right_child_node_height = node->right->height;
    }
    node->height =
        std::max(left_child_node_height, right_child_node_height) + 1;
  }
}
void UpdateTheParentsStartingFromParent_(Node *unupdated_parent_to_start_with) {
  auto node = unupdated_parent_to_start_with;  // for clearity
  if (node) {
    Height correct_height =
        CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(node);
    //      std::cout << "[ " << node->data << "] (" << node->height <<") -> ("
    //      << correct_height <<")" << std::endl;
    if (node->height != correct_height) {
      node->height = correct_height;
      UpdateTheParentsStartingFromParent_(
          unupdated_parent_to_start_with->parent);
    }
  }
}

Height CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(
    const Node *const node) {
  if (!node) {
    assert(0);
  } else {
    Height left_child_node_height = -1, right_child_node_height = -1;
    if (node->left) {
      left_child_node_height = node->left->height;
    }
    if (node->right) {
      right_child_node_height = node->right->height;
    }
    return std::max(left_child_node_height, right_child_node_height) + 1;
  }
}
}  // End PrivateHelper::
}  // End HeightUpdater::
}  // End of BSTNS::

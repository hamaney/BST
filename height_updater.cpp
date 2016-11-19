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

namespace BSTNS
{
namespace HeightUpdater
{

void UpdateHeight(Node *node_parent)
{
  Node *node = node_parent; // jsut for clearfication

  if (node)
  {
    // read the update from down up
    UpdateHeightOfNodeNonRecursively(node);
    //push updates upwared to parents
    UpdateTheParentsStartingFromParent(node->parent);
  }
}

//TODO : change name to updateHeightOfNodeAndItsChildernRecursiveCall
//OR Update ChildTreesHeights
//OR UpdateNodeAndChildrenHieghtsRecussive
Height UpdateHeightOfNodeRecursively(Node *node)
{
  if (!node)
  {
    return -1;
  }
  else
  {
    Height left_child_node_height =
        UpdateHeightOfNodeRecursively(node->left.get());
    Height right_child_node_height =
        UpdateHeightOfNodeRecursively(node->right.get());
    node->height =
        std::max(left_child_node_height, right_child_node_height) + 1;
    return node->height;
  }
}
void UpdateHeightOfNodeNonRecursively(Node *node)
{
  if (node)
  {
    Height left_child_node_height(-1), right_child_node_height(-1);
    if (node->left)
    {
      left_child_node_height = node->left->height;
    }
    if (node->right)
    {
      right_child_node_height = node->right->height;
    }
    node->height =
        std::max(left_child_node_height, right_child_node_height) + 1;
  }
}
// Upper Parents Hight Updateder
// After Adding a node
void UpdateParentsHeightAfterAddingANode(Node *node)
{
  if (node->parent)
  {
    if (node->parent->height < (node->height + 1))
    {
      node->parent->height = node->height + 1;
      UpdateParentsHeightAfterAddingANode(node->parent);
    }
  }
}
// After removing a node
void UpdateParentsHeightAfterRemovingANode(Node *node)
{
  if (node and node->parent)
  {
    Node *parent = node->parent;
    Height node_height = node->height;
    Height node_parent_height = node->parent->height;
    if ((node_height + 2) < node_parent_height)
    {
      // skip updating
    }
    else if ((node_height + 2) == node_parent_height)
    {
      // sibling cases
      Height node_sibling_height;
      if (HasOnlyLeftChild(parent) or
          HasOnlyRightChild(parent))
      {
        node_sibling_height = -1;
      }
      else if (node->is_left_node)
      {
        node_sibling_height = parent->right->height;
      }
      else if (!node->is_left_node)
      {
        node_sibling_height = parent->left->height;
      }
      else
      { // TODO : impl an assertion
        assert(0);
      }
      // Check wheather to update the height or not
      if (node_height >= node_sibling_height)
      {
        parent->height = node_height + 1;
        UpdateParentsHeightAfterRemovingANode(parent);
      }
      else
      {
        // skip the update
      }
    }
    else
    {
    }
  }
}
void UpdateTheParentsStartingFromParent(Node *unupdated_parent_to_start_with)
{
    auto node = unupdated_parent_to_start_with; // for clearity
  if (node)
  {
    Height correct_height =
        ReadNodeHeightFromitsChildrenNonRecursively(node);
//      std::cout << "[ " << node->data << "] (" << node->height <<") -> (" << correct_height <<")" << std::endl;
    if (node->height != correct_height)
    {
        node->height = correct_height;
      UpdateTheParentsStartingFromParent(unupdated_parent_to_start_with->parent);
    }
  }
}


Height ReadNodeHeightFromitsChildrenNonRecursively(const Node *const node)
{
  if (!node)
  {
    assert(0);
  }
  else
  {
    Height left_child_node_height = -1, right_child_node_height = -1;
    if (node->left)
    {
      left_child_node_height = node->left->height;
    }
    if (node->right)
    {
      right_child_node_height = node->right->height;
    }
    return std::max(left_child_node_height, right_child_node_height) + 1;
  }
}

} // End HeightUpdater::
} // End of BSTNS::

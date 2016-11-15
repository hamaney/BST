//
//  node_remover.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "node_remover.hpp"

//Full path fo clearty
using namespace BSTNS::NodeConnectionsChecker;
using namespace BSTNS::HeightUpdater;

using namespace BSTNS::NodeRemover::PrivateHelper;

namespace BSTNS
{
namespace NodeRemover
{
bool Remove(NodeUPtr &tree_root, Node *node_to_remove)
{
    
    
  if (node_to_remove)
  {
    if (HasNoChildren(node_to_remove))
    {
      return RemoveNodeWithNoChildren_(tree_root, node_to_remove);
    }
    else if (HasTwoChildren(node_to_remove))
    {
      return RemoveNodeWithTwoChildren_(tree_root, node_to_remove);
    }
    else if (HasOnlyLeftChild(node_to_remove))
    {
      return RemoveNodeWithOnlyLeftChild_(tree_root, node_to_remove);
    }
    else if (HasOnlyRightChild(node_to_remove))
    {
      return RemoveNodeWithOnlyRightChild_(tree_root, node_to_remove);
    }
    else
    {
      assert(0);
    }
  }
  else
  {
    return false;
  }
}
namespace PrivateHelper
{
bool RemoveNodeWithNoChildren_(NodeUPtr &tree_root,
                               Node *node_to_remove)
{
  auto parent = node_to_remove->parent;
  if (!parent)
  {
    tree_root.reset();
    UpdateHeightOfNodeRecursively(tree_root.get());
    return true;
  }
  else
  {
    if (node_to_remove->is_left_node)
    {
      parent->left.reset();
      UpdateHeightOfNodeRecursively(parent);
      UpdateParentsHeightAfterRemovingANode(parent);
      return true;
    }
    else
    {
      parent->right.reset();
      UpdateHeightOfNodeRecursively(parent);
      UpdateParentsHeightAfterRemovingANode(parent);
      return true;
    }
  }
}
// TODO: make a choise based on leftheavey or right heavy node
bool RemoveNodeWithTwoChildren_(NodeUPtr &tree_root, Node *node_to_remove)
{
  Node *right_branch_min_value_node =
      NodeFinder::FindMin(node_to_remove->right.get());
  node_to_remove->data = right_branch_min_value_node->data;
  return Remove(tree_root,
                right_branch_min_value_node); // calling a remove on a leaf
  // node will update the height of the branch where the leaf is
}
bool RemoveNodeWithOnlyLeftChild_(NodeUPtr &tree_root, Node *node_to_remove)
{
  Node *parent = node_to_remove->parent;

  if (!parent)
  {
    tree_root = std::move(tree_root->left);
    tree_root->parent = nullptr;
    tree_root->is_left_node = false; // Extra just to be sure
    // no need to update the hight in this case
    return true;
  }
  else
  {
    if (node_to_remove->is_left_node)
    {
      parent->left = std::move(node_to_remove->left);
      parent->left->parent = parent;
      // HeightUpdater::UpdateParentsHeightAfterRemovingANode(parent->left.get());
      return true;
    }
    else
    {
      parent->right = std::move(node_to_remove->left);
      parent->right->parent = parent;
      parent->right->is_left_node = false;
      // HeightUpdater::UpdateParentsHeightAfterRemovingANode(parent->right.get());
      return true;
    }
  }
}
bool RemoveNodeWithOnlyRightChild_(NodeUPtr &tree_root, Node *node_to_remove)
{
  Node *parent = node_to_remove->parent;
  if (!parent)
  {
    tree_root = std::move(tree_root->right);
    tree_root->parent = nullptr;
    tree_root->is_left_node = false; // Extra just to be sure
    // no need to update the hight in this case
    return true;
  }
  else
  {
    if (node_to_remove->is_left_node)
    {
      parent->left = std::move(node_to_remove->right);
      parent->left->parent = parent;
      parent->left->is_left_node = true;
      // HeightUpdater::UpdateParentsHeightAfterRemovingANode(parent->left.get());
      return true;
    }
    else
    {
      parent->right = std::move(node_to_remove->right);
      parent->right->parent = parent;
      // HeightUpdater::UpdateParentsHeightAfterRemovingANode(parent->right.get());
      return true;
    }
  }
}
} //End of PrivateHelper::
} //End of NodeRemover::
} //End of BSTNS:

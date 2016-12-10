//
//  bst.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "bst.hpp"

namespace BSTNS
{
BST::BST(void) {}
BST::BST(const Data &entry) { Insert(entry); }
BST::BST(const std::vector<Data> &entries_container)
{
  Insert(entries_container);
}
BST::~BST() {}

// ==== INSERT =================================================================
bool BST::Insert(const Data &entry)
{
  auto parent_of_insrted_node = Insert_(root, entry);
  UpdateHeight_(parent_of_insrted_node);
  return parent_of_insrted_node; // if value exist this will return
                                 // nullptr and convert it to a bool
}
bool BST::Insert(const std::vector<Data> &entries)
{
  std::vector<Data>::iterator iter;
  for (auto i = entries.begin(); i != entries.end(); i++)
  {
    Insert(*i);
  }
  return true;
}
// ==== INSERT_ ================================================================
Node *BST::Insert_(NodeUPtr &current_root, const Data &entry)
{
  if (!current_root)
  {
    current_root = Node::CreateNode(entry);
    return current_root->parent;
    // OR return nullptr;
  }

  else if (entry > current_root->data)
  {
    if (!current_root->right)
    {
      current_root->right = Node::CreateNode(entry);
      current_root->right->parent = current_root.get();
      return current_root.get();
    }
    else
    {
      return Insert_(current_root->right, entry);
    }
  }
  else if (entry < current_root->data)
  {
    if (!current_root->left)
    {
      current_root->left = Node::CreateNode(entry);
      current_root->left->parent = current_root.get();
      current_root->left->is_left_node = true;
      return current_root.get();
    }
    else
    {
      return Insert_(current_root->left, entry);
    }
  }
  else
  {
    return nullptr;
  }
}
// ==== REMOVE =================================================================
bool BST::Remove(const Data &target)
{
  Node *node_found = Find_(root.get(), target);
  if (node_found)
  {
    auto removed_node_parent = Remove_(root, node_found);
    UpdateHeight_(removed_node_parent);
    return true;
  }
  // non-existing target will return false
  // failing to remove a node will return false
  else
  {
    return false;
  }
}
bool BST::Remove(const std::vector<Data> &entries)
{
  std::vector<Data>::iterator iter;
  for (auto i = entries.begin(); i != entries.end(); i++)
  {
    Remove(*i);
  }
  return true;
}
bool BST::EmptyTheTree()
{
  root.reset();
  return !root.get();
}
// ==== REMOVE_ ================================================================
Node *BST::Remove_(NodeUPtr &tree_root, Node *node_to_remove)
{
  if (node_to_remove && tree_root)
  {
    if (HasNoChildren_(node_to_remove))
    {
      return RemoveNodeWithNoChildren_(tree_root, node_to_remove);
    }
    else if (HasTwoChildren_(node_to_remove))
    {
      return RemoveNodeWithTwoChildren_(tree_root, node_to_remove);
    }
    else if (HasOnlyLeftChild_(node_to_remove))
    {
      return RemoveNodeWithOnlyLeftChild_(tree_root, node_to_remove);
    }
    else if (HasOnlyRightChild_(node_to_remove))
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
    return nullptr;
  }
}
Node *BST::RemoveNodeWithNoChildren_(NodeUPtr &tree_root,
                                      Node *node_to_remove)
{
  auto parent = node_to_remove->parent;
  if (!parent)
  {
    tree_root.reset();
  }
  else
  {
    if (node_to_remove->is_left_node)
    {
      parent->left.reset();
    }
    else
    {
      parent->right.reset();
    }
  }
  return parent;
}
// TODO: make a choise based on leftheavey or right heavy node
Node *BST::RemoveNodeWithTwoChildren_(NodeUPtr &tree_root,
                                       Node *node_to_remove)
{
  auto node_to_remove_parent = node_to_remove->parent;
  auto right_branch_min_value_node = GetMin_(node_to_remove->right.get());
  node_to_remove->data = right_branch_min_value_node->data;
  // calling a remove on a leaf or one with no left node
  // might call recursivly until it remove a leaf
  // height will be updated when the node leaf is removed
  Remove_(tree_root, right_branch_min_value_node);
  return node_to_remove_parent; // only for the fist node this function is
                                // called with
}
Node *BST::RemoveNodeWithOnlyLeftChild_(NodeUPtr &tree_root,
                                         Node *node_to_remove)
{
  auto parent = node_to_remove->parent;

  if (!parent)
  {
    tree_root = std::move(tree_root->left);
    tree_root->parent = nullptr;
    tree_root->is_left_node = false;
    // no need to update the hight in this case
  }
  else
  {
    if (node_to_remove->is_left_node)
    {
      parent->left = std::move(node_to_remove->left);
      parent->left->parent = parent;
    }
    else
    {
      parent->right = std::move(node_to_remove->left);
      parent->right->parent = parent;
      parent->right->is_left_node = false;
    }
  }

  return parent;
}
Node *BST::RemoveNodeWithOnlyRightChild_(NodeUPtr &tree_root,
                                          Node *node_to_remove)
{
  auto parent = node_to_remove->parent;
  if (!parent)
  {
    tree_root = std::move(tree_root->right);
    tree_root->parent = nullptr;
    // no need to update the hight in this case nor the position of the node
    // since root and right node are both have is_left_node = false
  }
  else
  {
    if (node_to_remove->is_left_node)
    {
      parent->left = std::move(node_to_remove->right);
      parent->left->parent = parent;
      parent->left->is_left_node = true;
    }
    else
    {
      parent->right = std::move(node_to_remove->right);
      parent->right->parent = parent;
    }
  }

  return parent;
}
// ==== SEARCH =================================================================
Node *BST::Find(const Data &target) const
{
  return Find_(root.get(), target);
}
Data BST::GetMin(void) const
{
  Node *min_node = GetMin_(root.get());
  return min_node->data;
}
Data BST::GetMax(void) const
{
  Node *max_node = GetMax_(root.get());
  return max_node->data;
}
// ==== SEARCH_ ================================================================
Node *BST::Find_(Node *const current_root, const Data &target) const
// if the node is not found it returns a nullptr , no error massage
{
  if (!current_root)
  {
    return nullptr;
  }
  else if (target > current_root->data)
  {
    return Find_(current_root->right.get(), target);
  }
  else if (target < current_root->data)
  {
    return Find_(current_root->left.get(), target);
  }
  else if (target == current_root->data)
  {
    return current_root;
  }
  else
  {
    // TODO :  impliment an error MSG
    assert(0);
  }
}
Node *BST::GetMin_(Node *const current_node) const
{
  if (!current_node->left)
  {
    return current_node;
  }
  else
  {
    return GetMin_(current_node->left.get());
  }
}
Node *BST::GetMax_(Node *const current_node) const
{
  if (!current_node->right)
  {
    return current_node;
  }
  else
  {
    return GetMax_(current_node->right.get());
  }
}
// ==== TREE HEIGHT UPDATERS_ ==================================================
void BST::UpdateHeight_(Node *node_parent)
{
  Node *node = node_parent; // jsut for clearfication

  if (node)
  {
    // read the update from down up
    UpdateHeightOfNodeNonRecursively_(node);
    // push updates upwared to parents
    UpdateTheParentsStartingFromParent_(node->parent);
  }
}
Height BST::UpdateHeightOfNodeRecursively_(Node *node)
{
  if (!node)
  {
    return -1;
  }
  else
  {
    Height left_child_node_height =
        UpdateHeightOfNodeRecursively_(node->left.get());
    Height right_child_node_height =
        UpdateHeightOfNodeRecursively_(node->right.get());
    node->height =
        std::max(left_child_node_height, right_child_node_height) + 1;
    return node->height;
  }
}
void BST::UpdateHeightOfNodeNonRecursively_(Node *node)
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
void BST::UpdateTheParentsStartingFromParent_(
    Node *unupdated_parent_to_start_with)
{
  auto node = unupdated_parent_to_start_with; // for clearity

  if (node)
  {
    Height correct_height =
        CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(node);

    if (node->height != correct_height)
    {
      node->height = correct_height;
      UpdateTheParentsStartingFromParent_(
          unupdated_parent_to_start_with->parent);
    }
    // speacial chech for updating height after rotation
    else
    {
      if (node->parent)
      {
        Height parent_correct_height =
            CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(
                node->parent);

        if (node->parent->height != parent_correct_height)
        {
          UpdateTheParentsStartingFromParent_(node->parent);
        }
      }
    }
  }
}
Height BST::CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(
    const Node *const node)
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
// ==== NODE CONNECTION CHECKERS_ ==============================================
bool BST::HasNoChildren_(const Node *const node)
{
  if (node)
  {
    return (!node->left and !node->right);
  }
  else
  {
    return false;
  }
}
bool BST::HasTwoChildren_(const Node *const node)
{
  if (node)
  {
    return (node->left and node->right);
  }
  else
  {
    return false;
  }
}
bool BST::HasOnlyLeftChild_(const Node *const node)
{
  if (node)
  {
    return (node->left and !node->right);
  }
  else
  {
    return false;
  }
}
bool BST::HasOnlyRightChild_(const Node *const node)
{
  if (node)
  {
    return (!node->left and node->right);
  }
  else
  {
    return false;
  }
}
// ==== ROTATE_ ================================================================
Node *BST::RotateLeftAround_(NodeUPtr &pivot_node)
{
  /*        __[x]__
   //       /       \
   //   [xLeft]    _[y]_
   //             /     \
   //         [yLeft]  [yRight]
   */

  /*        __[y]__
   //       /       \
   //    _[x]_    [yRight]
   //   /     \
   //[xLeft]  [yLeft]
   */

  if (pivot_node and pivot_node->right)
  {
    Node *pivot_node_parent = pivot_node->parent;

    // Get all tree info before moving things around
    NodeUPtr x;
    bool old_pivot_is_left_node_status = pivot_node->is_left_node;
    // TODO : change to lamda
    if (pivot_node->is_left_node)
    {
      x = std::move(pivot_node_parent->left);
    }
    else if (!pivot_node->is_left_node && pivot_node_parent)
    {
      x = std::move(pivot_node_parent->right);
    }
    else
    {
      x = std::move(pivot_node);
    }

    // Rotating
    // y
    auto y = std::move(x->right);
    y->parent = pivot_node_parent;
    y->is_left_node = old_pivot_is_left_node_status;
    // y_left
    if (y->left)
    {
      x->right = std::move(y->left);
      x->right->parent = x.get(); // potintial Error if x_right null
      x->right->is_left_node = false;
    }
    // x
    y->left = std::move(x);
    y->left->parent = y.get();
    y->left->is_left_node = true;

    pivot_node = std::move(y);
    return pivot_node->left.get(); // retrun the old pivot node since it is the
                                   // lower node to that require a height
                                   // update
  }
  else
  {
    return nullptr;
  }
}
Node *BST::RotateRightAround_(NodeUPtr &pivot_node)
{
  /*        __[y]__
   //       /       \
   //    _[x]_    [yRight]
   //   /     \
   //[xLeft]  [xRight]
   */

  // After Right Rotation

  /*        __[x]__
   //       /       \
   //   [xLeft]    _[y]_
   //             /     \
   //         [xRight]  [yRight]
   */

  if (pivot_node and pivot_node->left)
  {
    Node *pivot_node_parent = pivot_node->parent;

    // Get all tree info before moving things around
    NodeUPtr y;
    bool old_pivot_is_left_node_status = pivot_node->is_left_node;
    // TODO : change to lamda
    if (pivot_node->is_left_node)
    {
      y = std::move(pivot_node_parent->left);
    }
    else if (!pivot_node->is_left_node && pivot_node_parent)
    {
      y = std::move(pivot_node_parent->right);
    }
    else
    {
      y = std::move(pivot_node);
    }

    // Rotating
    // x
    auto x = std::move(y->left);
    x->parent = pivot_node_parent;
    x->is_left_node = old_pivot_is_left_node_status;
    // xRight
    if (x->right)
    {
      y->left = std::move(x->right);
      y->left->parent = y.get();
      y->left->is_left_node = true;
    }
    // y
    x->right = std::move(y);
    x->right->parent = x.get();
    x->right->is_left_node = false;

    pivot_node = std::move(x);
    return pivot_node->right.get(); // retrun the old pivot node since it is
                                    // the lower node to that require a height
                                    // update
  }
  else
  {
    return nullptr;
  }
}
// ==== BALANCING ==============================================================
bool BST::Balance()
{
  while (!IsBalanced_(root.get())) // check all nodes balancing factor
  {

    Balance_(root);
  }
  return true;
}
bool BST::IsBalanced() { return IsBalanced_(root.get()); }
// ==== BALANCING_ =============================================================
void BST::Balance_(NodeUPtr &current_root)
{
  if (!current_root)
  {
    return;
  }

  if (!IsBalancedNode_(current_root.get()))
  {
    Node *node_with_most_updated_height = current_root.get();

    if (IsLeftLeft_(current_root.get()))
    {
      node_with_most_updated_height = RotateRightAround_(current_root);
    }
    else if (IsLeftRight_(current_root.get()))
    {
      node_with_most_updated_height = RotateLeftAround_(current_root->left);
      UpdateHeight_(node_with_most_updated_height);
      node_with_most_updated_height = RotateRightAround_(current_root);
    }
    else if (IsRightLeft_(current_root.get()))
    {
      node_with_most_updated_height = RotateRightAround_(current_root->right);
      UpdateHeight_(node_with_most_updated_height);
      node_with_most_updated_height = RotateLeftAround_(current_root);
    }
    else if (IsRightRight_(current_root.get()))
    {
      node_with_most_updated_height = RotateLeftAround_(current_root);
      UpdateHeight_(node_with_most_updated_height);
    }
    else
    {
      // TODO : should here be an error or an implementation ??
      assert(0);
    }

    UpdateHeight_(node_with_most_updated_height);
  }
  Balance_(current_root->left);
  Balance_(current_root->right);
}
bool BST::IsBalanced_(const Node *const current_root) // +
{
  if (!current_root)
  {
    return true;
  }

  if (IsBalanced_(current_root->left.get()) and
      IsBalanced_(current_root->right.get()))
  {
    return IsBalancedNode_(current_root);
  }
  else
  {
    return false;
  }
}
bool BST::IsBalancedNode_(const Node *const node) //O(1) //+
{
  auto bf = BalanceFactorOfNode_(node);
  return (bf < 2) and (bf > -2);
}
int BST::BalanceFactorOfNode_(const Node *const node) //O(1) //+
{
  if (!node)
  {
    assert(0);
  }
  else
  {
    int left_child_balance_factor, right_child_balance_factor;
    if (!node->left)
    {
      left_child_balance_factor = -1;
    }
    else
    {
      left_child_balance_factor = node->left->height;
    }
    if (!node->right)
    {
      right_child_balance_factor = -1;
    }
    else
    {
      right_child_balance_factor = node->right->height;
    }
    return left_child_balance_factor - right_child_balance_factor;
  }
}
bool BST::IsLeftLeft_(const Node *const node)
{
  return (IsLeftHeavy_(node)) ? (BalanceFactorOfNode_(node->left.get()) >= 1)
                              : false;
  // return IsLeftHeavy_(node) and IsLeftHeavy_(node->left.get()) ;
}
bool BST::IsLeftRight_(const Node *const node)
{
  return (IsLeftHeavy_(node)) ? (BalanceFactorOfNode_(node->left.get()) <= -1)
                              : false;
  // return IsLeftHeavy_(node) and IsRightHeavy_(node->left.get()) ;
}
bool BST::IsRightLeft_(const Node *const node)
{
  return (IsRightHeavy_(node)) ? (BalanceFactorOfNode_(node->right.get()) >= 1)
                               : false;
  // return IsRightHeavy_(node) and IsLeftHeavy_(node->right.get()) ;
}
bool BST::IsRightRight_(const Node *const node)
{
  return (IsRightHeavy_(node)) ? (BalanceFactorOfNode_(node->right.get()) <= -1)
                               : false;
  // return IsRightHeavy_(node) and IsRightHeavy_(node->right.get()) ;
}
bool BST::IsLeftHeavy_(const Node *const node)
{
  return BalanceFactorOfNode_(node) >= 2;
}
bool BST::IsRightHeavy_(const Node *const node)
{
  return BalanceFactorOfNode_(node) <= -2;
}
} // End BSTNS::

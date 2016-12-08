//
//  bst.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "bst.hpp"

using namespace BSTNS::TreePrinter;

using namespace BSTNS::NodeBalanceChecker;
using namespace BSTNS::Rotator;

namespace BSTNS {
Tree::Tree(void) {}
Tree::Tree(const Data &entry) { Insert(entry); }
Tree::Tree(const std::vector<Data> &entries_container) {
  Insert(entries_container);
}
Tree::~Tree() {}

bool Tree::Insert(const Data &entry) {
  auto parent_of_insrted_node = Insert_(root, entry);
  UpdateHeight_(parent_of_insrted_node);
  return parent_of_insrted_node;  // if value exist this will return
                                  // nullptr and convert it to a bool
}
bool Tree::Insert(const std::vector<Data> &entries) {
  std::vector<Data>::iterator iter;
  for (auto i = entries.begin(); i != entries.end(); i++) {
    Insert(*i);
  }
  return true;
}

bool Tree::Remove(const Data &target) {
  Node *node_found = FindNode(root.get(), target);
  if (node_found) {
    auto removed_node_parent = RemoveNode(root, node_found);
    UpdateHeight_(removed_node_parent);
    return true;
  }
  // non-existing target will return false
  // failing to remove a node will return false
  else {
    return false;
  }
}
bool Tree::Remove(const std::vector<Data> &entries) {
  std::vector<Data>::iterator iter;
  for (auto i = entries.begin(); i != entries.end(); i++) {
    Remove(*i);
  }
  return true;
}
bool Tree::EmptyTheTree() {
  root.reset();
  return !root.get();
}
bool Tree::IsBalanced() {
  return NodeBalanceChecker::IsBalancedTree(root.get());
}

bool Tree::Balance() {
  while (!NodeBalanceChecker::IsBalancedTree(root.get())) {
    BalanceNodes_(root);
  }
  return true;
}
Node *Tree::Find(const Data &target) const {
  return FindNode(root.get(), target);
}
Data Tree::GetMin(void) const {
  Node *min_node = FindMinNode(root.get());
  return min_node->data;
}
Data Tree::GetMax(void) const {
  Node *max_node = FindMaxNode(root.get());
  return max_node->data;
}

void Tree::Print() { PrintTree(root.get(), 1, 0, std::cout); }
void Tree::PrintHeights() { PrintTreeHeights(root.get(), 1, 0, std::cout); }

void Tree::BalanceNodes_(NodeUPtr &current_root) {
  if (!current_root) {
    return;
  }
  BalanceNodes_(current_root->left);

  //  std::cout << "Checking if Node " << current_root->data << " is balanced "
  //            << std::endl;

  if (!NodeBalanceChecker::IsBalancedNode(current_root.get())) {
    Node *node_with_most_updated_height = nullptr;

    if (IsLeftLeft(current_root.get())) {
      node_with_most_updated_height = RotateRightAround(current_root);

    } else if (IsLeftRight(current_root.get())) {
      node_with_most_updated_height = RotateLeftAround(current_root->left);
      UpdateHeight_(node_with_most_updated_height);
      node_with_most_updated_height = RotateRightAround(current_root);

    } else if (IsRightLeft(current_root.get())) {
      node_with_most_updated_height = RotateRightAround(current_root->right);
      UpdateHeight_(node_with_most_updated_height);
      node_with_most_updated_height = RotateLeftAround(current_root);

    } else if (IsRightRight(current_root.get())) {
      node_with_most_updated_height = RotateLeftAround(current_root);
      UpdateHeight_(node_with_most_updated_height);

    } else {
      std::cout << "Node " << current_root->data
                << " needs to be Balanced But nothing is Implimented "
                   "*******************"
                << std::endl;
    }

    UpdateHeight_(node_with_most_updated_height);

    BalanceNodes_(current_root->right);
  }
}

Node *Tree::Insert_(NodeUPtr &current_root, const Data &entry) {
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
      return Insert_(current_root->right, entry);
    }

  } else if (entry < current_root->data) {
    if (!current_root->left) {
      current_root->left = NodeFactory_(entry);
      current_root->left->parent = current_root.get();
      current_root->left->is_left_node = true;
      return current_root.get();
    } else {
      return Insert_(current_root->left, entry);
    }

  } else {
    return nullptr;
  }
}

NodeUPtr Tree::NodeFactory_(const Data &entry) {
  return std::make_unique<Node>(entry);
}

void Tree::UpdateHeight_(Node *node_parent) {
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
Height Tree::UpdateHeightOfNodeRecursively_(Node *node) {
  if (!node) {
    return -1;
  } else {
    Height left_child_node_height =
        UpdateHeightOfNodeRecursively_(node->left.get());
    Height right_child_node_height =
        UpdateHeightOfNodeRecursively_(node->right.get());
    node->height =
        std::max(left_child_node_height, right_child_node_height) + 1;
    return node->height;
  }
}

void Tree::UpdateHeightOfNodeNonRecursively_(Node *node) {
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
void Tree::UpdateTheParentsStartingFromParent_(
    Node *unupdated_parent_to_start_with) {
  auto node = unupdated_parent_to_start_with;  // for clearity

  if (node) {
    Height correct_height =
        CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(node);

    if (node->height != correct_height) {
      node->height = correct_height;
      UpdateTheParentsStartingFromParent_(
          unupdated_parent_to_start_with->parent);
    }
    // speacial chech for updating height after rotation
    else {
      if (node->parent) {
        Height parent_correct_height =
            CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(
                node->parent);

        if (node->parent->height != parent_correct_height) {
          UpdateTheParentsStartingFromParent_(node->parent);
        }
      }
    }
  }
}

Height Tree::CalculateNodeHeightNonRecursivelyAndWithoutUpdatingTheNode_(
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
bool Tree::HasNoChildren_(const Node *const node) {
  if (node) {
    return (!node->left and !node->right);
  } else {
    return false;
  }
}
bool Tree::HasTwoChildren_(const Node *const node) {
  if (node) {
    return (node->left and node->right);
  } else {
    return false;
  }
}
bool Tree::HasOnlyLeftChild_(const Node *const node) {
  if (node) {
    return (node->left and !node->right);
  } else {
    return false;
  }
}
bool Tree::HasOnlyRightChild_(const Node *const node) {
  if (node) {
    return (!node->left and node->right);
  } else {
    return false;
  }
}

Node *Tree::RemoveNode(NodeUPtr &tree_root, Node *node_to_remove) {
  if (node_to_remove && tree_root) {
    if (HasNoChildren_(node_to_remove)) {
      return RemoveNodeWithNoChildren_(tree_root, node_to_remove);
    } else if (HasTwoChildren_(node_to_remove)) {
      return RemoveNodeWithTwoChildren_(tree_root, node_to_remove);
    } else if (HasOnlyLeftChild_(node_to_remove)) {
      return RemoveNodeWithOnlyLeftChild_(tree_root, node_to_remove);
    } else if (HasOnlyRightChild_(node_to_remove)) {
      return RemoveNodeWithOnlyRightChild_(tree_root, node_to_remove);
    } else {
      assert(0);
    }
  } else {
    return nullptr;
  }
}

Node *Tree::RemoveNodeWithNoChildren_(NodeUPtr &tree_root,
                                      Node *node_to_remove) {
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
Node *Tree::RemoveNodeWithTwoChildren_(NodeUPtr &tree_root,
                                       Node *node_to_remove) {
  auto node_to_remove_parent = node_to_remove->parent;
  auto right_branch_min_value_node = FindMinNode(node_to_remove->right.get());
  node_to_remove->data = right_branch_min_value_node->data;
  // calling a remove on a leaf or one with no left node
  // might call recursivly until it remove a leaf
  // height will be updated when the node leaf is removed
  RemoveNode(tree_root, right_branch_min_value_node);
  return node_to_remove_parent;  // only for the fist node this function is
                                 // called with
}
Node *Tree::RemoveNodeWithOnlyLeftChild_(NodeUPtr &tree_root,
                                         Node *node_to_remove) {
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
Node *Tree::RemoveNodeWithOnlyRightChild_(NodeUPtr &tree_root,
                                          Node *node_to_remove) {
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
Node *Tree::FindNode(Node *const current_root, const Data &target)const
// if the node is not found it returns a nullptr , no error massage
{
  if (!current_root) {
    return nullptr;
  } else if (target > current_root->data) {
    return FindNode(current_root->right.get(), target);
  } else if (target < current_root->data) {
    return FindNode(current_root->left.get(), target);
  } else if (target == current_root->data) {
    return current_root;
  } else {
    // TODO :  impliment an error MSG
    assert(0);
  }
}

Node *Tree::FindMinNode(Node *const current_node)const {
  if (!current_node->left) {
    return current_node;
  } else {
    return FindMinNode(current_node->left.get());
  }
}

Node *Tree::FindMaxNode(Node *const current_node) const{
  if (!current_node->right) {
    return current_node;
  } else {
    return FindMaxNode(current_node->right.get());
  }
}
}  // End BSTNS::

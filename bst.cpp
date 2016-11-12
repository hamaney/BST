//
//  bst.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "bst.hpp"

// PUBLIC   ====================================================================
// Creation --------------------------------------------------------------------

void print(std::string msg) { std::cout << msg << std::endl; }

Tree::Tree(const Data &entry) { InitiateTree_(entry); }
Tree::~Tree() {}
// Modify   --------------------------------------------------------------------
bool Tree::Add(const Data &entry) {
  if (!Exist(entry)) {
    return Add_(root, entry);
  } else {
    ////TODO: Print ERROR MSG;
    return false;
  }
}

bool Tree::Remove(const Data &target) {
  Node *node_found = Find_(root.get(), target);
  if (node_found) {
    return Remove_(node_found);
  }
  // nonexisting target will return false
  // faling to remove a node will return flase
  else {
    return false;
  }
}

Data Tree::Min(void) const {
  Node *min_node = FindMin_(root.get());
  return min_node->data;
}

Data Tree::Max(void) const {
  Node *max_node = FindMax_(root.get());
  return max_node->data;
}

// Others ----------------------------------------------------------------------
Node *Tree::Find(const Data &target) const { return Find_(root.get(), target); }
// Checks ----------------------------------------------------------------------
bool Tree::Exist(const Data &key) const { return Find_(root.get(), key); }
bool Tree::hasNoChildren(const Data &key) const {
  const Node *const node_found = Find_(root.get(), key);
  if (node_found) {
    return hasNoChildren_(node_found);
  } else {
    return false;
  }
}
bool Tree::hasTwoChildren(const Data &key) const {
  const Node *const node_found = Find_(root.get(), key);
  if (node_found) {
    return hasTwoChildren_(node_found);
  } else {
    return false;
  }
}
bool Tree::hasOnlyLeftChild(const Data &key) const {
  const Node *const node_found = Find(key);
  if (node_found) {
    return hasOnlyLeftChild_(node_found);
  } else {
    return false;
  }
}
bool Tree::hasOnlyRightChild(const Data &key) const {
  const Node *const node_found = Find(key);
  if (node_found) {
    return hasOnlyRightChild_(node_found);
  } else {
    return false;
  }
}
// Prints ----------------------------------------------------------------------
void Tree::Print() { Print_(root); }
// PIRVATE ====================================================================
// Creation --------------------------------------------------------------------
void Tree::InitiateTree_(const Data &entry) { Add_(root, entry); }
NodeUPtr Tree::AddNode_(const Data &entry) const {
  return std::make_unique<Node>(entry);
}
// Modify ----------------------------------------------------------------------
bool Tree::Add_(NodeUPtr &current_root, const Data &entry) {
  ////TODO: add a test case
  if (!root) {
    root = AddNode_(entry);
    return true;
  }

  else if (entry > current_root->data) {
    if (!current_root->right) {
      current_root->right = AddNode_(entry);
      current_root->right->parent = current_root.get();
      IncreaseParentHeightOf_(current_root->right.get());
      return true;
    } else {
      return Add_(current_root->right, entry);
    }
  } else if (entry < current_root->data) {
    if (!current_root->left) {
      current_root->left = AddNode_(entry);
      current_root->left->parent = current_root.get();
      current_root->left->is_left_node = true;
      IncreaseParentHeightOf_(current_root->left.get());
      return true;
    } else {
      return Add_(current_root->left, entry);
    }
  } else {
    return false;
  }  // implemnt an error
}

bool Tree::Remove_(Node *node_to_remove) {
  if (node_to_remove) {
    if (hasNoChildren_(node_to_remove))

    {
      return RemoveNodeWithNoChildren_(node_to_remove);
    } else if (hasTwoChildren_(node_to_remove)) {
      return RemoveNodeWithTwoChildren_(node_to_remove);
    } else if (hasOnlyLeftChild_(node_to_remove)) {
      return RemoveNodeWithOnlyLeftChild_(node_to_remove);
    } else if (hasOnlyRightChild_(node_to_remove)) {
      return RemoveNodeWithOnlyRightChild_(node_to_remove);
    } else {
      assert(0);
      return false;
    }  //// TODO: implemint error msg
  } else {
    return false;
  }
}
// Other -----------------------------------------------------------------------
bool Tree::RemoveNodeWithNoChildren_(Node *node_to_remove) {
  auto parent = node_to_remove->parent;
  if (!parent) {
    root.reset();
    UpdateHeightOf_(root.get());
    return true;
  } else {
    if (node_to_remove->is_left_node) {
      parent->left.reset();
      UpdateHeightOf_(parent);
      DecreaseParentHeightOf_(parent);
      return true;
    } else {
      parent->right.reset();
      UpdateHeightOf_(parent);
      DecreaseParentHeightOf_(parent);
      return true;
    }
  }
}
// TODO: make a choise based on leftheavey or right heavy node
bool Tree::RemoveNodeWithTwoChildren_(Node *node_to_remove) {
  Node *right_branch_min_value_node = FindMin_(node_to_remove->right.get());
  node_to_remove->data = right_branch_min_value_node->data;
  return Remove_(right_branch_min_value_node);
}

bool Tree::RemoveNodeWithOnlyLeftChild_(Node *node_to_remove) {
  Node *parent = node_to_remove->parent;

  if (!parent) {
    root = std::move(root->left);
    root->parent = nullptr;
    root->is_left_node = false;  // Extra just to be sure
    // no need to update the hight in this case
    return true;
  } else {
    if (node_to_remove->is_left_node) {
      parent->left = std::move(node_to_remove->left);
      parent->left->parent = parent;
      DecreaseParentHeightOf_(parent->left.get());
      return true;
    } else {
      parent->right = std::move(node_to_remove->left);
      parent->right->parent = parent;
      parent->right->is_left_node = false;
      DecreaseParentHeightOf_(parent->right.get());
      return true;
    }
  }
}
bool Tree::RemoveNodeWithOnlyRightChild_(Node *node_to_remove) {
  Node *parent = node_to_remove->parent;
  if (!parent) {
    root = std::move(root->right);
    root->parent = nullptr;
    root->is_left_node = false;  // Extra just to be sure
    // no need to update the hight in this case
    return true;
  } else {
    if (node_to_remove->is_left_node) {
      parent->left = std::move(node_to_remove->right);
      parent->left->parent = parent;
      parent->left->is_left_node = true;
      DecreaseParentHeightOf_(parent->left.get());
      return true;
    } else {
      parent->right = std::move(node_to_remove->right);
      parent->right->parent = parent;
      DecreaseParentHeightOf_(parent->right.get());
      return true;
    }
  }
}
// Other -----------------------------------------------------------------------
Node *Tree::Find_(Node *const current_root, const Data &target) const
// if the node is not found it returns a nullptr , no error massage
{
  if (!current_root) {
    return nullptr;
  } else if (target > current_root->data) {
    return Find_(current_root->right.get(), target);
  } else if (target < current_root->data) {
    return Find_(current_root->left.get(), target);
  } else if (target == current_root->data) {
    return current_root;
  } else {
    ////TODO :  impliment an error MSG
    assert(0);
    return nullptr;
  }
}

Node *Tree::FindMin_(Node *const current_node) const {
  if (!current_node->left) {
    return current_node;
  } else {
    return FindMin_(current_node->left.get());
  }
}

Node *Tree::FindMax_(Node *const current_node) const {
  if (!current_node->right) {
    return current_node;
  } else {
    return FindMax_(current_node->right.get());
  }
}

// Checks --------------------------------------------------------------------
// does not check if the key exist
bool Tree::hasNoChildren_(const Node *const node) const {
  return (!node->left and !node->right);
}

bool Tree::hasTwoChildren_(const Node *const node) const {
  return (node->left and node->right);
}

bool Tree::hasOnlyLeftChild_(const Node *const node) const {
  return (node->left and !node->right);
}

bool Tree::hasOnlyRightChild_(const Node *const node) const {
  return (!node->left and node->right);
}
// Helpers
// Node Height Updater
Height Tree::UpdateHeightOf_(Node *node) {
  if (!node) {
    return -1;
  } else {
    Height left_child_node_height = UpdateHeightOf_(node->left.get());
    Height right_child_node_height = UpdateHeightOf_(node->right.get());
    node->height =
        std::max(left_child_node_height, right_child_node_height) + 1;
    return node->height;
  }
}
// Upper Parents Hight Updateder
// After Adding a node
void Tree::IncreaseParentHeightOf_(Node *node) {
  if (node->parent) {
    if (node->parent->height < (node->height + 1)) {
      node->parent->height = node->height + 1;
      IncreaseParentHeightOf_(node->parent);
    }
  }
}
// After removing a node
void Tree::DecreaseParentHeightOf_(Node *node) {
  if (node and node->parent) {
    Node *parent = node->parent;
    Height node_height = node->height;
    Height node_parent_height = node->parent->height;
    if ((node_height + 2) < node_parent_height) {
      // skip updating
    } else if ((node_height + 2) == node_parent_height) {
      // sibling cases
      Height node_sibling_height;
      if (hasOnlyLeftChild_(parent) or hasOnlyRightChild_(parent)) {
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
        DecreaseParentHeightOf_(parent);
      } else {
        // skip the update
      }
    } else {
    }
  }
}
// Prints
// ----------------------------------------------------------------------
void Tree::Print_(NodeUPtr &root) { printPretty(root.get(), 1, 0, std::cout); }

// Print Error Function

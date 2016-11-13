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
  Node *node_found = node_finder_.Find(root.get(), target);
  if (node_found) {
    return node_remover_.Remove(root, node_found);
  }
  // nonexisting target will return false
  // faling to remove a node will return flase
  else {
    return false;
  }
}

Data Tree::Min(void) const {
  Node *min_node = node_finder_.FindMin(root.get());
  return min_node->data;
}

Data Tree::Max(void) const {
  Node *max_node = node_finder_.FindMax(root.get());
  return max_node->data;
}

// Others ----------------------------------------------------------------------
Node *Tree::Find(const Data &target) const {
  return node_finder_.Find(root.get(), target);
}
// Checks ----------------------------------------------------------------------
bool Tree::Exist(const Data &key) const {
  return node_finder_.Find(root.get(), key);
}

bool Tree::IsLeaf(const Data &key) const {
  const Node *const node_found = node_finder_.Find(root.get(), key);
  if (node_found) {
    return connection_checker_.HasNoChildren(node_found);
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
      height_updater_.UpdateParentsHeightAfterAddingANode(
          current_root->right.get());
      return true;
    } else {
      return Add_(current_root->right, entry);
    }
  } else if (entry < current_root->data) {
    if (!current_root->left) {
      current_root->left = AddNode_(entry);
      current_root->left->parent = current_root.get();
      current_root->left->is_left_node = true;
      height_updater_.UpdateParentsHeightAfterAddingANode(
          current_root->left.get());
      return true;
    } else {
      return Add_(current_root->left, entry);
    }
  } else {
    return false;
  }  // implemnt an error
}

// Other -----------------------------------------------------------------------

// Checks --------------------------------------------------------------------

/*bool Tree::isLeftHeavy(const Node *const node) const {
  if (node) {
    Height node_weight;
    Height node_left_weight = -1;
    Height node_right_weight = -1;
    if (node->left) {
      node_left_weight = node->left->height;
    }
    if (node->right) {
      node_right_weight = node->right->height;
    }
    node_weight = node_left_weight - node_right_weight;

    if ()
  }
}
}*/
// Helpers

// Rotation

bool Tree::RotateLeftAround_(NodeUPtr &pivot_node) {
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

  if (pivot_node) {
    Node *pivot_node_parent = pivot_node->parent;

    // Get all tree info before moving things around
    NodeUPtr x;
    // TODO : change to lamda
    if (pivot_node->is_left_node) {
      x = std::move(pivot_node_parent->left);
    } else {
      x = std::move(pivot_node_parent->right);
    }
    Height x_old_height = x->height;
    auto y = std::move(x->right);
    auto y_left = std::move(y->left);
    // y_left
    x->right = std::move(y_left);
    y_left->parent = x.get();
    y_left->is_left_node = false;
    // x
    y->left = std::move(x);
    x->parent = y.get();
    // height_updater_.UpdateHeightOfNodeNonRecursively(x.get());
    x->is_left_node = true;
    // y
    if (pivot_node->is_left_node) {
      pivot_node_parent->left = std::move(y);
      y->is_left_node = true;

    } else {
      pivot_node_parent->right = std::move(y);
    }
    // height_updater_.UpdateHeightOfNodeNonRecursively(y.get());
    if (y->height > x_old_height) {
      // TODO : add a wrapper so it is easiar to t that there is no added node
      // but just mear parents updating
      // height_updater_.UpdateParentsHeightAfterAddingANode(y.get());
      return true;
    } else if (y->height < x_old_height) {
      // TODO : add a wrapper so it is easiar to t that there is no added node
      // but just mear parents updating

      // height_updater_.UpdateParentsHeightAfterRemovingANode(y.get());
      return true;

    } else {  // no update required
      return false;
    }
  } else {
    return false;
  }
}

// bool Tree::RotateRightAround_(NodeUPtr &pivot_node) { return 1; }

// Prints
// ----------------------------------------------------------------------
void Tree::Print_(NodeUPtr &root) { printPretty(root.get(), 1, 0, std::cout); }

// Print Error Function

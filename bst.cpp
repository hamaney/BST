//
//  bst.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "bst.hpp"

// using std::cout;
// using std::endl;
using namespace BSTNS::HeightUpdater;
using namespace BSTNS::NodeConnectionsChecker;
using namespace BSTNS::TreePrinter;
using namespace BSTNS::NodeInserter;
using namespace BSTNS::NodeRemover;
using namespace BSTNS::NodeBalanceChecker;
using namespace BSTNS::Rotator;
using namespace BSTNS::NodeFinder;

namespace BSTNS {
Tree::Tree(void) {}
Tree::Tree(const Data &entry) { Insert(entry); }
Tree::Tree(const std::vector<Data> &entries_container) {
  Insert(entries_container);
}
Tree::~Tree() {}

bool Tree::Insert(const Data &entry) {
  auto parent_of_insrted_node = InsertValue(root, entry);
  UpdateHeight(parent_of_insrted_node);
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
    UpdateHeight(removed_node_parent);
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
bool Tree::IsBalanced() { return IsBalancedTree(root.get()); }

bool Tree::Balance() {
  while (!IsBalancedTree(root.get())) {
    BalanceNodes_(root);
  }
  return true;
}
Node *Tree::Find(const Data &target) const {
  return FindNode(root.get(), target);
}
Data Tree::Min(void) const {
  Node *min_node = FindMinNode(root.get());
  return min_node->data;
}
Data Tree::Max(void) const {
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
  BalanceNodes_(current_root->right);
//  std::cout << "Checking if Node " << current_root->data << " is balanced "
//            << std::endl;

  if (!IsBalancedNode(current_root.get())) {
    Node *node_with_most_updated_height = nullptr;
//    std::cout << "Node " << current_root->data << " BF = "
//              << NodeBalanceChecker::PrivateHelper::BalanceFactorOfNode_(
//                     current_root.get())
//              << std::endl;

    if (IsLeftLeft(current_root.get())) {
//      std::cout << "Node " << current_root->data << " is LL ->>> rot aruond "
//                << current_root->data << std::endl;
//      Print();
//      PrintHeights();
      node_with_most_updated_height = RotateRightAround(current_root);
    } else if (IsLeftRight(current_root.get())) {
//      std::cout << "Node " << current_root->data << " is LR ->>> rot aruond "
//                << current_root->left->data << std::endl;
//      Print();
//      PrintHeights();
      node_with_most_updated_height = RotateLeftAround(current_root->left);
//      UpdateHeight(node_with_most_updated_height);
//      std::cout << "+ rot aruond " << current_root->data << std::endl;
//      Print();
//      PrintHeights();
//
      node_with_most_updated_height = RotateRightAround(current_root);

    } else if (IsRightLeft(current_root.get())) {
//      std::cout << "Node " << current_root->data << " is RL ->>> rot aruond "
//                << current_root->right->data << std::endl;
//      Print();
//      PrintHeights();
      node_with_most_updated_height = RotateRightAround(current_root->right);
//      UpdateHeight(node_with_most_updated_height);
//      Print();
//      PrintHeights();
//      std::cout << "+ rot aruond " << current_root->data << std::endl;

      node_with_most_updated_height = RotateLeftAround(current_root);

    } else if (IsRightRight(current_root.get())) {
        std::cout << "Node " << current_root->data << " is RR ->>> rot aruond "
        << current_root->data << std::endl;
        Print();
      PrintHeights();
        std::cout << " Rotating Left .... " << current_root->data << std::endl;

      node_with_most_updated_height = RotateLeftAround(current_root);
        PrintHeights();
        std::cout << " Udating height .... " << current_root->data << std::endl;
        UpdateHeight(node_with_most_updated_height);
    PrintHeights();
    } else {
      std::cout << "Node " << current_root->data
                << " needs to be Balanced But nothing is Implimented "
                   "*******************"
                << std::endl;
    }

    UpdateHeight(node_with_most_updated_height);
    Print();
    PrintHeights();
      std::cout << "Done with Node " << current_root->data
      << " Balancing for now  "
      "*******************"
      << std::endl;
  
  }
}

}  // End BSTNS::

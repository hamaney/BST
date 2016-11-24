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
// using namespace BSTNS::NodeFinder;
using namespace BSTNS::TreePrinter;
using namespace BSTNS::NodeInserter;
using namespace BSTNS::NodeRemover;

namespace BSTNS {
Tree::Tree(void) {}
Tree::Tree(const Data &entry) { Insert(entry); }
Tree::Tree(const std::vector<Data> &entries_container) {
  Insert(entries_container);
}
Tree::~Tree() {}

bool Tree::Insert(const Data &entry) {
  auto parent_of_insrted_node_returned = InsertValue(root, entry);
  UpdateHeight(parent_of_insrted_node_returned);
  return parent_of_insrted_node_returned;  // if value exist this will return
                                           // nullptr and converte it to a bool
}

bool Tree::Insert(const std::vector<Data> &entries_container) {
  std::vector<Data>::iterator iter;
  for (auto i = entries_container.begin(); i != entries_container.end(); i++) {
    Insert(*i);
  }
  return true;
}

bool Tree::Remove(const Data &target) {
  Node *node_found = NodeFinder::Find(root.get(), target);
  if (node_found) {
    auto removed_node_parent = RemoveNode(root, node_found);
    UpdateHeight(removed_node_parent);
    return true;
  }
  // nonexisting target will return false
  // faling to remove a node will return flase
  else {
    return false;
  }
}
bool Tree::Remove(const std::vector<Data> &entries_container) {
  std::vector<Data>::iterator iter;
  for (auto i = entries_container.begin(); i != entries_container.end(); i++) {
    Remove(*i);
  }
  return true;
}

Node *Tree::Find(const Data &target) const {
  return NodeFinder::Find(root.get(), target);
}
Data Tree::Min(void) const {
  Node *min_node = NodeFinder::FindMin(root.get());
  return min_node->data;
}
Data Tree::Max(void) const {
  Node *max_node = NodeFinder::FindMax(root.get());
  return max_node->data;
}

void Tree::Print() { TreePrinter::Print(root.get(), 1, 0, std::cout); }
void Tree::PrintHeights() {
  TreePrinter::PrintHeights(root.get(), 1, 0, std::cout);
}
}  // End BSTNS::

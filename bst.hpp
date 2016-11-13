//
//  BST.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

/*

 ////TODO
- prevent acceing root members when root is deleted
- Functions to be Added
  // Balance()
  // Balance_(root)
  // IsBalanced()
- Classes to be added
  // TreeBalancer
 //Node Remover
 // Node Finder
 //TreePrinter

 */

#ifndef bst_hpp
#define bst_hpp

#include <cassert>
#include <iostream>
#include <memory>
#include "height_updater.hpp"
#include "node.hpp"
#include "node_connections_checker.hpp"
#include "node_finder.hpp"
#include "node_remover.hpp"
#include "print_tree.hpp"

using std::cout;
using std::endl;

class Tree {
 public:
  // Creation
  Tree(const Data &entry = 0);
  ~Tree();
  NodeUPtr root;

  // Modify
  bool Add(const Data &entry);
  bool Remove(const Data &target);
  Data Min(void) const;
  Data Max(void) const;
  // Other
  Node *Find(const Data &target) const;
  // Checks
  bool Exist(const Data &key) const;
  bool IsLeaf(const Data &key) const;
  // Prints
  void Print();

 private:
  HeightUpdater height_updater_;
  NodeConnectionsChecker connection_checker_;
  NodeFinder node_finder_;
  NodeRemover node_remover_;
  // Creation
  void InitiateTree_(const Data &entry = 0);
  // Modify
  NodeUPtr AddNode_(const Data &entry = 0) const;
  bool Add_(NodeUPtr &current_root, const Data &entry);
  // Other
  // Node *Find_(Node *const current_root, const Data &target) const;
  // Node *FindMin_(Node *const current_root) const;
  // Node *FindMax_(Node *const current_root) const;
  // Checks

  // Helpers
  bool RotateLeftAround_(NodeUPtr &pivot_node);
  // bool RotateRightAround_(NodeUPtr &pivot_node);
  // Prints
  void Print_(NodeUPtr &root);
};

#endif /* BST_hpp */

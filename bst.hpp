//
//  BST.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef bst_hpp
#define bst_hpp

#include <iostream>
#include <cstdio> // jsut for the debug printing1
#include <memory>
#include <cassert>
#include "node.hpp"
#include "print_tree.hpp"

using std::cout;
using std::endl;

class Tree
{
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
  bool hasNoChildren(const Data &key) const;
  bool hasTwoChildren(const Data &key) const;
  bool hasOnlyLeftChild(const Data &key) const;
  bool hasOnlyRightChild(const Data &key) const;
  // Prints
  void Print();

private:
  // Creation
  void InitiateTree_(const Data &entry = 0);
  // Modify
  NodeUPtr AddNode_(const Data &entry = 0) const;
  bool Add_(NodeUPtr &current_root, const Data &entry);
  bool Remove_(Node *node_to_remove);
  bool RemoveNodeWithNoChildren_(Node *node_to_remove);
  bool RemoveNodeWithTwoChildren_(Node *node_to_remove);
  bool RemoveNodeWithOnlyLeftChild_(Node *node_to_remove);
  bool RemoveNodeWithOnlyRightChild_(Node *node_to_remove);

  // Other
  Node *Find_(Node *const current_root, const Data &target) const;
  Node *FindMin_(Node *const current_root) const;
  Node *FindMax_(Node *const current_root) const;
  // Checks
  bool hasNoChildren_(const Node *const) const;
  bool hasTwoChildren_(const Node *const) const;
  bool hasOnlyLeftChild_(const Node *const) const;
  bool hasOnlyRightChild_(const Node *const) const;
  // Prints
  void Print_(NodeUPtr &root);
};

#endif /* BST_hpp */

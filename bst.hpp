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
  // Leftheavey or right heavy
  //Rotation functions
 */

#ifndef bst_hpp
#define bst_hpp

#include <algorithm>
#include <memory>
#include <vector>

#include <iostream>
#include "height_updater.hpp"
#include "node.hpp"
#include "node_connections_checker.hpp"
#include "node_finder.hpp"
#include "tree_printer.hpp"
//#include "rotator.hpp"
#include "node_remover.hpp"

namespace BSTNS {
class Tree {
 public:
  // Creation
  Tree(const Data &entry = 0);
  Tree(const std::vector<Data> &entries_container);
  ~Tree();
  NodeUPtr root;
  bool Add(const Data &entry);
  bool Add(const std::vector<Data> &entries_container);
  bool Remove(const Data &target);
  Node *Find(const Data &target) const;
  bool Exist(const Data &key) const;
  bool IsLeaf(const Data &key) const;
  Data Min(void) const;
  Data Max(void) const;
  void Print();
  void PrintHeights();  // rendring heightd for testing

 private:
  void InitiateTree_(const Data &entry = 0);
  NodeUPtr AddNode_(const Data &entry = 0) const;
  bool Add_(NodeUPtr &current_root, const Data &entry);
};
}  // of BSTNamespace
#endif /* BST_hpp */

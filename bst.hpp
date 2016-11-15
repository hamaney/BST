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

#include <cassert>
#include <iostream>
#include <memory>
#include "height_updater.hpp"
#include "node.hpp"
#include "node_connections_checker.hpp"
#include "node_finder.hpp"
#include "node_remover.hpp"
#include "tree_printer.hpp"
#include "rotator.hpp"

using std::cout;
using std::endl;
namespace BSTNS
{
class Tree
{
public:
  // Creation
  Tree(const Data &entry = 0);
  ~Tree();
  NodeUPtr root;
  bool Add(const Data &entry);
  bool Remove(const Data &target);
  Node *Find(const Data &target) const;
  bool Exist(const Data &key) const;
  bool IsLeaf(const Data &key) const;
  Data Min(void) const;
  Data Max(void) const;
  void Print();

private:
  void InitiateTree_(const Data &entry = 0);
  NodeUPtr AddNode_(const Data &entry = 0) const;
  bool Add_(NodeUPtr &current_root, const Data &entry);
};
} // of BSTNamespace
#endif /* BST_hpp */

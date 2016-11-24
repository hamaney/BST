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
#include "node_inserter.hpp"

namespace BSTNS {
class Tree {
 public:
  // Creation
  Tree(void);  // Empty tree with no nodes
  Tree(const Data &entry);
  Tree(const std::vector<Data> &entries_container);
  ~Tree();
  NodeUPtr root;

  // bool Tree::InsertAtRoot(const Data &entry){}; // TODO
  bool Insert(const Data &entry);
  bool Insert(const std::vector<Data> &entries_container);

  bool Remove(const Data &target);
  bool Remove(const std::vector<Data> &entries_container); // TODO
  
    bool IsBalace();
    bool Balance();
    
  Node *Find(const Data &target) const;
  Data Min(void) const;
  Data Max(void) const;

  void Print();
  void PrintHeights();  // rendring heightd for testing
};
}  // of BSTNamespace
#endif /* BST_hpp */

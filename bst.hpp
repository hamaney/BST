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
#include "tree_printer.hpp"
#include "rotator.hpp"

using std::cout;
using std::endl;

class Tree {
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
  NodeFinder node_finder_;
    NodeConnectionsChecker connection_checker_;
    NodeRemover node_remover_;
    HeightUpdater height_updater_;
    TreePrinter tree_printer_;
    Rotator rotator_;

    //TreeRotator
    void InitiateTree_(const Data &entry = 0);
  // Modify
  NodeUPtr AddNode_(const Data &entry = 0) const;
  bool Add_(NodeUPtr &current_root, const Data &entry);
  // Helpers
  // bool RotateRightAround_(NodeUPtr &pivot_node);
  // Prints
  //void Print_(NodeUPtr &root);
};

#endif /* BST_hpp */

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
#include <memory>
#include <cassert>
#include "node.hpp"
#include "print_tree.hpp"

class Tree
{
public:
  // Creation
  Tree(const Data &entry = 0);
  ~Tree();
  NodeUPtr root;
  // Modify
  bool Add(const Data &entry);
  void Remove(const Data &target);
  // Other
  Node *Find(const Data &target) const;
  // Checks
  bool Exist(const Data &key) const;
  bool isLeaf(const Data &key) const;
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
  void Remove_(NodeUPtr &root, const Data &target);
  // Other
  Node *Find_(Node *const current_root, const Data &target) const;
  // Checks
  bool isLeaf_(const Node *const) const;
  bool hasTwoChildren_(const Node *const) const;
  bool hasOnlyLeftChild_(const Node *const) const;
  bool hasOnlyRightChild_(const Node *const) const;
  // Prints
  void Print_(NodeUPtr &root);
};

/* public:
       //#################################################################
       class Node;
       typedef std::unique_ptr<Node> NodeUPtr;
       enum ErrorType { KEntryExist };
       Tree(int entry = 0);
       ~Tree();
       NodeUPtr root;
       void Add(Data entry);
       Node* Find(Data key);
       bool Exist(Data key);
       // void Remove(Data key);
       // void PrintPreOrder();
       // void PrintInOrder();
       // void PrintPostOrder();
    
      private:
       //###############################################################
       void InitTree_(Data entry);
       void Add_(NodeUPtr& current_root, Data entry);
       NodeUPtr AddNode_(int data);
       Node* Find_(NodeUPtr& current_root, Data key);
       // void Remove_(NodeUPtr& current_root, Data key);
       // void PrintPreOrder_(NodeUPtr& current_root);
       // void PrintInOrder_(NodeUPtr& current_root);
       // void PrintPostOrder_(NodeUPtr& current_root);
       void PrintErrorMSG_(ErrorType error);
     };
     */
#endif /* BST_hpp */
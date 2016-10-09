//
//  BST.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <cassert>
#include <iostream>
#include <memory>

typedef int Data;

class Tree {
 public:
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

#endif /* BST_hpp */
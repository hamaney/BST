//
//  BST.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <iostream>
#include <memory>

class Tree {
 public:
  class Node;
  Tree(int data = 0);
  ~Tree();
  std::unique_ptr<Node> root;

 private:
  // Node ---------------------------------------------------------
  std::unique_ptr<Node> AddNode_(int data);

  // Tree ---------------------------------------------------------
  void InitTree_(int data);
};

#endif /* BST_hpp */
       //
//
//  BST.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "BST.hpp"

class Tree::Node {
 public:
  Node(int d = 0) : data(d){};
  ~Node(){};
  int data;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
};
typedef Tree::Node Node;

// Node ---------------------------------------------------------
std::unique_ptr<Node> Tree::AddNode_(int data) {
  return std::make_unique<Node>(data);
}

// Tree ---------------------------------------------------------
Tree::Tree(int data) { InitTree_(data); }
Tree::~Tree() {}
void Tree::InitTree_(int data) { root = AddNode_(data); }

//
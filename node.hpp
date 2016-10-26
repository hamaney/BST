//
//  Node.hpp
//  BST
//
// Created by Abdulrhman Mohamed on 2016-10-18.
// Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <memory>

class Node;
typedef std::unique_ptr<Node> NodeUPtr;
typedef int Data;

class Node
{
public:
  Node(Data entry = 0)
      : data(entry),
        left(nullptr),
        right(nullptr),
        parent(nullptr),
        is_left_node(false){};
  ~Node(){};
  Data data;
  NodeUPtr left, right;
  Node *parent;
  bool is_left_node;
};

#endif /* node_hpp */
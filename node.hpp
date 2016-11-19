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

namespace BSTNS
{

class Node;
typedef std::unique_ptr<Node> NodeUPtr;
typedef int Data;
typedef int Height;

class Node
{
public:
  Node(Data entry = 0)
      : data(entry),
        left(nullptr),
        right(nullptr),
        parent(nullptr),
        is_left_node(false),
        height(0){};
  ~Node(){};
  Data data;
  NodeUPtr left, right;
  Node *parent;
  bool is_left_node;
  Height height;
};
}
#endif /* node_hpp */

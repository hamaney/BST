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
  Node(Data entry = 0) : data(entry), left(nullptr), right(nullptr){};
  ~Node(){};
  Data data;
  NodeUPtr left, right;
};

//#############################################################

Tree::Tree(Data entry) { InitTree_(entry); }
Tree::~Tree() {}
void Tree::Add(Data entry) {  // To do
  if (Exist(entry)) {         // To do
  } else {
    Add_(root, entry);
  }
}
Tree::Node* Tree::Find(Data key) { return Find_(root, key); }  // To Do
bool Tree::Exist(Data entry) { return true; }                  // To do
void Tree::Remove(Data key) { Remove_(root, key); }

//#############################################################

void Tree::InitTree_(Data entry) { root = AddNode_(entry); }

void Tree::Add_(NodeUPtr& current_root, Data entry) {
  if (entry < current_root->data) {
    if (!current_root->left) {
      current_root->left = AddNode_(entry);
    } else {
      Add_(current_root->left, entry);
    }
  } else if (entry > current_root->data) {
    if (!current_root->right) {
      current_root->right = AddNode_(entry);
    } else {
      Add_(current_root->right, entry);
    }
  }
}

Tree::NodeUPtr Tree::AddNode_(Data entry) {
  return std::make_unique<Node>(entry);
}

Tree::Node* Tree::Find_(NodeUPtr& current_root, Data key) {
  if (key == current_root->data) {
    return current_root.get();  // .release ?
  } else if ((key < current_root->data) && current_root->left) {
    return Find_(current_root->left, key);
  } else if ((key > current_root->data) && current_root->right) {
    return Find_(current_root->right, key);
  } else {
    return nullptr;
  }
}

void Tree::Remove_(NodeUPtr& current_root, Data key) {  // Todo
}

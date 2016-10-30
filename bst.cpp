//
//  BST.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "bst.hpp"

// PUBLIC   ====================================================================
// Creation --------------------------------------------------------------------

void print(std::string msg) { std::cout << msg << std::endl; }

Tree::Tree(const Data &entry) { InitiateTree_(entry); }
Tree::~Tree() {}
// Modify   --------------------------------------------------------------------
bool Tree::Add(const Data &entry)
{
  if (!Exist(entry))
  {
    return Add_(root, entry);
  }
  else
  {
    ////TODO: Print ERROR MSG;
    return false;
  }
}
bool Tree::Remove(const Data &target)
{
  const Node *const node_found = Find_(root.get(), target);
  if (node_found)
  {
    return Remove_(root, target);
  }
  //nonexisting target will return false
  //faling to remove a node will return flase
  else
  {
    return false;
  }
}
// Others ----------------------------------------------------------------------
Node *Tree::Find(const Data &target) const
{
  return Find_(root.get(), target);
}
// Checks ----------------------------------------------------------------------
bool Tree::Exist(const Data &key) const { return Find_(root.get(), key); }
bool Tree::hasNoChildren(const Data &key) const
{
  const Node *const node_found = Find_(root.get(), key);
  if (node_found)
  {
    return hasNoChildren_(node_found);
  }
  else
  {
    return false;
  }
}
bool Tree::hasTwoChildren(const Data &key) const
{
  const Node *const node_found = Find_(root.get(), key);
  if (node_found)
  {
    return hasTwoChildren_(node_found);
  }
  else
  {
    return false;
  }
}
bool Tree::hasOnlyLeftChild(const Data &key) const
{
  const Node *const node_found = Find(key);
  if (node_found)
  {
    return hasOnlyLeftChild_(node_found);
  }
  else
  {
    return false;
  }
}
bool Tree::hasOnlyRightChild(const Data &key) const
{
  const Node *const node_found = Find(key);
  if (node_found)
  {
    return hasOnlyRightChild_(node_found);
  }
  else
  {
    return false;
  }
}
// Prints ----------------------------------------------------------------------
void Tree::Print()
{
  Print_(root);
}
//PIRVATE   ====================================================================
// Creation --------------------------------------------------------------------
void Tree::InitiateTree_(const Data &entry) { Add_(root, entry); }
NodeUPtr Tree::AddNode_(const Data &entry) const
{
  return std::make_unique<Node>(entry);
}
// Modify ----------------------------------------------------------------------
bool Tree::Add_(NodeUPtr &current_root, const Data &entry)
{
  ////TODO: add a test case
  if (!root)
  {
    root = AddNode_(entry);
    return true;
  }

  else if (entry > current_root->data)
  {
    if (!current_root->right)
    {
      current_root->right = AddNode_(entry);
      current_root->right->parent = current_root.get();
      return true;
    }
    else
    {
      return Add_(current_root->right, entry);
    }
  }
  else if (entry < current_root->data)
  {
    if (!current_root->left)
    {
      current_root->left = AddNode_(entry);
      current_root->left->parent = current_root.get();
      current_root->left->is_left_node = true;
      return true;
    }
    else
    {
      return Add_(current_root->left, entry);
    }
  }
  else
  {
    return false;
  } // implemnt an error
}
////TODO: Change protottpye of the function to take only a node *
bool Tree::Remove_(NodeUPtr &root, const Data &target)
{

  auto found_node = Find_(root.get(), target);
  if (found_node)
  {
    if (hasNoChildren_(found_node))
    {
      return RemoveNodeWithNoChildren_(found_node);
    }
    else if (hasTwoChildren_(found_node))
    {
      return RemoveNodeWithTwoChildren_(found_node);
    }
    else if (hasOnlyLeftChild_(found_node))
    {
      return RemoveNodeWithOnlyLeftChild_(found_node);
    }
    else if (hasOnlyRightChild_(found_node))
    {
      return RemoveNodeWithOnlyRightChild_(found_node);
    }
    else
    {
      assert(0);
      return false;
    } //// TODO: implemint error msg
  }
  else
  {
    return false;
  }
}
// Other -----------------------------------------------------------------------
bool Tree::RemoveNodeWithNoChildren_(Node *node)
{
  auto node_parent = node->parent;

  if (node->is_left_node)
  {
    node_parent->left.reset();
    return true;
  }
  else
  {
    //root node case
    if (!node_parent || (node->data == root->data))
    {
      root.reset();
      return true;
    }
    else
    {

      node_parent->right.reset();
      return true;
    }
  }
}
bool Tree::RemoveNodeWithTwoChildren_(Node *node)
{

  return false;
}
bool Tree::RemoveNodeWithOnlyLeftChild_(Node *node)
{
  Node *node_parent = node->parent;
  if (!node_parent)
  {
    root = std::move(root->left);
    return true;
  }
  else
  {
    if (node->is_left_node)
    {
      //node_parent->left = std::move(node->left);
      node_parent->left.reset(node->left.release());
      node_parent->left->parent = node_parent;
      return true;
    }
    else
    {
      //node_parent->right = std::move(node->left);
      node_parent->right.reset(node->left.release());
      node_parent->right->parent = node_parent;
      return true;
    }
  }
}
bool Tree::RemoveNodeWithOnlyRightChild_(Node *node)
{
  Node *node_parent = node->parent;
  if (!node_parent)
  {
    root = std::move(root->right);
    return true;
  }
  else
  {
    if (node->is_left_node)
    {
      node_parent->left = std::move(node->right);
      node_parent->left->parent = node_parent;
      return true;
    }
    else
    {
      node_parent->right = std::move(node->right);
      node_parent->right->parent = node_parent;
      return true;
    }
  }
}
// Other -----------------------------------------------------------------------
Node *Tree::Find_(Node *const current_root, const Data &target) const
// if the node is not found it returns a nullptr , no error massage
{

  if (!current_root)
  {
    return nullptr;
  }
  else if (target > current_root->data)
  {
    return Find_(current_root->right.get(), target);
  }
  else if (target < current_root->data)
  {
    return Find_(current_root->left.get(), target);
  }
  else if (target == current_root->data)
  {
    return current_root;
  }
  else
  {
    assert(0);
    return nullptr;
  } // impliment
}

// Checks --------------------------------------------------------------------
//does not check if the key exist
bool Tree::hasNoChildren_(const Node *const node) const
{
  return (!node->left and !node->right);
}

bool Tree::hasTwoChildren_(const Node *const node) const
{
  return (node->left and node->right);
}

bool Tree::hasOnlyLeftChild_(const Node *const node) const
{
  return (node->left and !node->right);
}

bool Tree::hasOnlyRightChild_(const Node *const node) const
{

  return (!node->left and node->right);
}

// Prints ----------------------------------------------------------------------
void Tree::Print_(NodeUPtr &root)
{
  printPretty(root.get(), 1, 0, std::cout);
}

// Print Error Function

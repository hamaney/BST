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
Node *
Tree::Find(const Data &target) const
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
void Tree::InitiateTree_(const Data &entry) { root = AddNode_(entry); }
NodeUPtr Tree::AddNode_(const Data &entry) const
{
  return std::make_unique<Node>(entry);
}
// Modify ----------------------------------------------------------------------
bool Tree::Add_(NodeUPtr &current_root, const Data &entry)
{
  assert(current_root);

  if (entry > current_root->data)
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
    } // TODO: implemint error msg
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
    node_parent->right.reset();
    return true;
  }
}
bool Tree::RemoveNodeWithTwoChildren_(Node *node)
{

  return false;
}
bool Tree::RemoveNodeWithOnlyLeftChild_(Node *node) { return false; }
bool Tree::RemoveNodeWithOnlyRightChild_(Node *node) { return false; }
// Other -----------------------------------------------------------------------
Node *
Tree::Find_(Node *const current_root, const Data &target) const // if the node is not
//found it returns a nullptr , no error massage
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
bool Tree::hasNoChildren_(const Node *const node) const //does not check if the key exist
{

  if (!node->left and !node->right)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Tree::hasTwoChildren_(const Node *const node) const
{

  if (node->left and node->right)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Tree::hasOnlyLeftChild_(const Node *const node) const
{

  if (node->left and !node->right)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool Tree::hasOnlyRightChild_(const Node *const node) const
{

  if (!node->left and node->right)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Prints ----------------------------------------------------------------------
void Tree::Print_(NodeUPtr &root)
{
  printPretty(root.get(), 1, 0, std::cout);
}

// Print Error Function
//

/*
 //#############################################################

 void Tree::Add(Data entry) {  // To do
   // if (Exist(entry)) {
   //  PrintErrorMSG_(KEntryExist);
   //} else {
   Add_(root, entry);
   //}
 }
 Tree::Node* Tree::Find(Data key) { return Find_(root, key); }  // To Do
 bool Tree::Exist(Data entry) { return Find_(root, entry); }    // To do
 // void Tree::Remove(Data key) { Remove_(root, key); }
 // void Tree::PrintPreOrder() { PrintPreOrder_(root); }
 // void Tree::PrintInOrder() { PrintInOrder_(root); }
 // void Tree::PrintPostOrder() { PrintPostOrder_(root); }

 //#############################################################

 void Tree::InitTree_(Data entry) { root = AddNode_(entry); }
 void Tree::Add_(NodeUPtr& current_root, Data entry) {
   if (entry == current_root->data) {
     PrintErrorMSG_(KEntryExist);
   } else if (entry < current_root->data) {
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
 // void Tree::Remove_(NodeUPtr& current_root, Data key) {  // Todo
 //}
 // void Tree::PrintPreOrder_(NodeUPtr& current_root) {
 //  if (current_root) {
 //    return;
 //  }
 //  std::cout << current_root->data << " " << std::endl;
 //  PrintPreOrder_(current_root->left);
 //  PrintPreOrder_(current_root->right);
 //}
 // void Tree::PrintInOrder_(NodeUPtr& current_root) {
 //  if (current_root) {
 //    return;
 //  }
 //  PrintInOrder_(current_root->left);
 //  std::cout << current_root->data << std::endl;
 //  PrintInOrder_(current_root->right);
 //}
 // void Tree::PrintPostOrder_(NodeUPtr& current_root) {
 //  if (current_root) {
 //    return;
 //  }
 //  PrintInOrder_(current_root->left);
 //
 //  PrintInOrder_(current_root->right);
 //
 //  std::cout << current_root->data << std::endl;
 //}
 void Tree::PrintErrorMSG_(ErrorType error) {
   switch (error) {
     case KEntryExist:
       std::cerr << "The entry added already exists!" << std::endl;
       exit(KEntryExist + 1);  // 1 at this time
       break;

     default:
       std::cerr << "This should be an error please add an error msg!"
                 << std::endl;
       exit(-1);
       break;
   }
 }
 */

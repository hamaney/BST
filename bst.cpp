//
//  bst.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "bst.hpp"


namespace BSTNS
{
Tree::Tree(const Data &entry) { InitiateTree_(entry); }
Tree::~Tree() {}
// Modify   --------------------------------------------------------------------
//bool Tree::AddAtRoot(const Data &entry); // TODO
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
    Node *node_found = NodeFinder::Find(root.get(), target);
  if (node_found)
  {
      return NodeRemover::Remove(root, node_found);
  }
  // nonexisting target will return false
  // faling to remove a node will return flase
  else
  {
    return false;
  }
}

Data Tree::Min(void) const
{
    Node *min_node = NodeFinder::FindMin(root.get());
  return min_node->data;
}

Data Tree::Max(void) const
{
    Node *max_node = NodeFinder::FindMax(root.get());
  return max_node->data;
}

// Others ----------------------------------------------------------------------
Node *Tree::Find(const Data &target) const
{
    return NodeFinder::Find(root.get(), target);
}
// Checks ----------------------------------------------------------------------
bool Tree::Exist(const Data &key) const
{
    return NodeFinder::Find(root.get(), key);
}

bool Tree::IsLeaf(const Data &key) const
{
    const Node *const node_found = NodeFinder::Find(root.get(), key);
  if (node_found)
  {
    return NodeConnectionsChecker::HasNoChildren(node_found);
  }
  else
  {
    return false;
  }
}
// Prints ----------------------------------------------------------------------
void Tree::Print()
{
    TreePrinter::PrintHeights(root.get(), 1, 0, std::cout);
}
// PIRVATE ====================================================================
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
        HeightUpdater::UpdateParentsHeightAfterAddingANode(
          current_root->right.get());
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
      HeightUpdater::UpdateParentsHeightAfterAddingANode(
          current_root->left.get());
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
} //End BSTNS::

//
//  tree_printer.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-13.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "tree_printer.hpp"
namespace BSTNS
{
namespace TreePrinter
{
bool print_hights_instead_of_data; // Remove later
void Print(const Node *const root, int level, int indentSpace,
           std::ostream &out)
{
  print_hights_instead_of_data = false;
  PrivateHelper::printPretty_(root, level, indentSpace, out);
}
void PrintHeights(const Node *const root, int level,
                  int indentSpace, std::ostream &out)
{
  print_hights_instead_of_data = true;
  PrivateHelper::printPretty_(root, level, indentSpace, out);
}
namespace PrivateHelper
{
// Find the maximum height of the binary tree
int maxHeight_(const Node *const p)
{
  if (!p)
    return 0;
  int leftHeight = maxHeight_(p->left.get());
  int rightHeight = maxHeight_(p->right.get());
  return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Convert an integer value to string
std::string intToString_(int val)
{
  std::ostringstream ss;
  ss << val;
  return ss.str();
}

// Print the arm branches (eg, /    \ ) on a line
void printBranches_(
    int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel,
    const std::deque<const Node *const> &nodesQueue, std::ostream &out)
{
  std::deque<const Node *const>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++)
  {
    out << ((i == 0) ? std::setw(startLen - 1) : std::setw(nodeSpaceLen - 2))
        << "" << ((*iter++) ? "/" : " ");
    out << std::setw(2 * branchLen + 2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << std::endl;
}

// Print the branches and node (eg, ___10___ )
void printNodes_(int branchLen, int nodeSpaceLen, int startLen,
                 int nodesInThisLevel,
                 const std::deque<const Node *const> &nodesQueue,
                 std::ostream &out)
{
  std::deque<const Node *const>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++)
  {
    out << ((i == 0) ? std::setw(startLen) : std::setw(nodeSpaceLen)) << ""
        << ((*iter && (*iter)->left) ? std::setfill('_') : std::setfill(' '));
    // -------------------------- TEST -----------------------------------------
    if (print_hights_instead_of_data)
    {
      out << std::setw(branchLen + 2)
          << ((*iter) ? intToString_((*iter)->height) : "");
    }
    else
    {
      out << std::setw(branchLen + 2)
          << ((*iter) ? intToString_((*iter)->data) : "");
    }
    // -------------------------------------------------------------------------
    out << ((*iter && (*iter)->right) ? std::setfill('_') : std::setfill(' '))
        << std::setw(branchLen) << "" << std::setfill(' ');
  }
  out << std::endl;
}

// Print the leaves only (just for the bottom row)
void printLeaves_(int indentSpace, int level, int nodesInThisLevel,
                  const std::deque<const Node *const> &nodesQueue,
                  std::ostream &out)
{
  std::deque<const Node *const>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++)
  {
    // ------------------------- TEST ------------------------------------------
    if (print_hights_instead_of_data)
    {
      out << ((i == 0) ? std::setw(indentSpace + 2) : std::setw(2 * level + 2))
          << ((*iter) ? intToString_((*iter)->height) : "");
    }
    else
    {
      out << ((i == 0) ? std::setw(indentSpace + 2) : std::setw(2 * level + 2))
          << ((*iter) ? intToString_((*iter)->data) : "");
    }
  }
  // -------------------------------------------------------------------------
  out << std::endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the
// minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg,
// indentSpace of 0 means the lowest level of the left node will stick to the
// left margin)
void printPretty_(const Node *const root, int level,
                  int indentSpace, std::ostream &out)
{
  int h = maxHeight_(root);
  int nodesInThisLevel = 1;

  int branchLen =
      2 * ((int)pow(2.0, h) - 1) -
      (3 - level) *
          (int)pow(
              2.0,
              h - 1); // eq of the length of branch for each node of each level
  int nodeSpaceLen =
      2 + (level + 1) * (int)pow(2.0, h); // distance between left neighbor
  // node's right arm and right
  // neighbor node's left arm
  int startLen = branchLen + (3 - level) +
                 indentSpace; // starting space to the first node to print of
  // each level (for the left most node of each
  // level only)

  std::deque<Node const *const> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++)
  {
    printBranches_(branchLen, nodeSpaceLen, startLen, nodesInThisLevel,
                   nodesQueue, out);
    branchLen = branchLen / 2 - 1;
    nodeSpaceLen = nodeSpaceLen / 2 + 1;
    startLen = branchLen + (3 - level) + indentSpace;
    printNodes_(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue,
                out);

    for (int i = 0; i < nodesInThisLevel; i++)
    {
      const Node *const currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode)
      {
        nodesQueue.push_back(currNode->left.get());
        nodesQueue.push_back(currNode->right.get());
      }
      else
      {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches_(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue,
                 out);
  printLeaves_(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}
} // End of PrivateHelper::
} // End of TreePrinter::
}  // End of BSTNS::
//
//  print_tree.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-10-18.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//
// Modified from the original code at
// http://articles.leetcode.com/printing-binary-tree-in-level-order/
#ifndef tree_printer_hpp
#define tree_printer_hpp

#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

//The tree to be printed
#include "bst.hpp"
using namespace BSTNS;
//
class TreePrinter{
public:
void PrintTree(const Node *const root, int level = 1, int indentSpace = 0,
           std::ostream &out = std::cout);
void PrintTreeHeights(const Node *const root, int level = 1, int indentSpace = 0,
                  std::ostream &out = std::cout);
private:
    bool print_heights_instead_of_data_;
int maxHeight_(const Node *const p);
std::string intToString_(int val);
void printBranches_(int branchLen, int nodeSpaceLen, int startLen,
                    int nodesInThisLevel,
                    const std::deque<const Node *const> &nodesQueue,
                    std::ostream &out);
void printNodes_(int branchLen, int nodeSpaceLen, int startLen,
                 int nodesInThisLevel,
                 const std::deque<const Node *const> &nodesQueue,
                 std::ostream &out);
void printLeaves_(int indentSpace, int level, int nodesInThisLevel,
                  const std::deque<const Node *const> &nodesQueue,
                  std::ostream &out);
void printPretty_(const Node *const root, int level, int indentSpace,
                  std::ostream &out);
};
#endif /* tree_printer_hpp */

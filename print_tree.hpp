//
//  print_tree.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-10-18.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//
// Modified from the original code at
// http://articles.leetcode.com/printing-binary-tree-in-level-order/

#ifndef print_tree_hpp
#define print_tree_hpp

#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "node.hpp"
const bool KPrintHightINsteadOfDATA(true);

int maxHeight(const Node *const p);

std::string intToString(int val);

void printBranches(int branchLen, int nodeSpaceLen, int startLen,
                   int nodesInThisLevel,
                   const std::deque<const Node *const> &nodesQueue,
                   std::ostream &out);

void printNodes(int branchLen, int nodeSpaceLen, int startLen,
                int nodesInThisLevel, const std::deque<Node *> &nodesQueue,
                std::ostream &out);

void printLeaves(int indentSpace, int level, int nodesInThisLevel,
                 const std::deque<Node *> &nodesQueue, std::ostream &out);

void printPretty(const Node *const root, int level, int indentSpace,
                 std::ostream &out);

#endif /* print_tree_hpp */

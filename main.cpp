//
//  main.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include <iostream>
#include "bst.hpp"
#include "tree_printer.hpp"

int main(int argc, const char *argv[]) {
  BSTNS::BST tree;

  tree.Insert({1, 2, 3, 4, 5});
    TreePrinter tp;
    tp.PrintTree(tree.root.get());
    
    tree.Balance();
  tp.PrintTree(tree.root.get());
    return 0;
}

//
//  main.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include <iostream>
#include "BST.hpp"

class Node;
int main(int argc, const char* argv[]) {
  Tree tree(1);

  tree.Add(5);
  tree.PrintPreOrder();
  return 0;
}

///
//
//  main.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include <iostream>
#include "bst.hpp"

int main(int argc, const char *argv[]) {
    BSTNS::Tree tree;
    
    tree.Insert({1,2,3,4,5});
    tree.Balance();
  return 0;
}

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
  BSTNS::Tree tree(7);
    tree.Insert(3);
    if(tree.Insert(3)){
  std::cout << " Repeated " << std::endl;
    }//
  //        ________[7]_______
  //       /                  \
    //     _[3]__            __[11]_
  //    /      \          /       \
        //  [1]      [5]      [9]       [13]
  //
  return 0;
}

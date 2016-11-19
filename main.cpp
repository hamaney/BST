//
//  main.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include <iostream>
#include "bst.hpp"

int main(int argc, const char *argv[])
{
    BSTNS::Tree tree(7);
  tree.Print();
  tree.Add(3);
  tree.Print();
  tree.Add(11);
  tree.Print();
  tree.Add(1);
  tree.Print();
  tree.Add(5);
  tree.Print();
  tree.Add(9);
  tree.Print();
  tree.Add(13);
  tree.Print();
  tree.Add(15);
  tree.Print();
  tree.Add(14);
  tree.Print();
    std::cout << " DONE " << std::endl;
  //
  //        ________[7]_______
  //       /                  \
    //     _[3]__            __[11]_
  //    /      \          /       \
        //  [1]      [5]      [9]       [13]
  //
  return 0;
}

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
    //while(1){
    
    
    std::cout << "===============================insert ========================" << std::endl;
    tree.Insert(3);
    tree.Print();tree.Balance();tree.Print();
    std::cout << "===============================insert ========================" << std::endl;
    tree.Insert(4);
    tree.Print();tree.Balance();tree.Print();
    std::cout << "===============================insert ========================" << std::endl;
    tree.Insert(8);
    tree.Print();tree.Balance();tree.Print();
    std::cout << "===============================insert ========================" << std::endl;
  tree.Insert(6);
  tree.Print();tree.Balance();tree.Print();
    std::cout << "===============================insert ========================" << std::endl;
  tree.Insert(7);
  tree.Print();tree.Balance();tree.Print();
    std::cout << "===============================insert ========================" << std::endl;
  tree.Insert(5);
  tree.Print();tree.Balance();tree.Print();
    std::cout << "===============================insert ========================" << std::endl;
  tree.Insert(2);
  tree.Print();tree.Balance();tree.Print();
    std::cout << "===============================insert ========================" << std::endl;
  tree.Insert(1);
    tree.Print();tree.Balance();tree.Print();tree.PrintHeights();
        //tree.EmptyTheTree();}
  return 0;
}

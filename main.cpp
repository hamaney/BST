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
    std::cout << "heloo world" << std::endl;
    
    int i = 1;
    
    while(i--){
    
    Tree tree(4);
    tree.Add(2);
    tree.Add(6);
    tree.Add(1);
    tree.Add(3);
    tree.Add(5);
    tree.Add(7);
    
        //tree.Print();
        tree.Remove(3);
        tree.Print();
        tree.Remove(2);
        tree.Print();
        tree.Remove(7);
        tree.Print();
        tree.Remove(6);
        tree.Print();
        tree.Remove(4);
        tree.Print();
        //tree.Remove(6);
        //tree.Print();
        //tree.Remove(4);
        //tree.Print();
        
        
        
        
        
        
    }
    return 0;
}

// will test this tree (final shape)
//
//        ________[4]_______
//       /                  \
//     _[2]__            __[6]_
//    /      \          /      \
//  [1]      [3]      [5]      [7]

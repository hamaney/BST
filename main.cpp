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
    //std::cout << "heloo world" << std::endl;
    
    int i = 10000000;
    Tree tree(4);
    tree.Add(2);
    
    while(i--){
        
        tree.Remove(4);
        
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

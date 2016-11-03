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
    Tree tree(7);
    tree.Add(3);
    tree.Add(11);
    tree.Add(1);
    tree.Add(5);
    tree.Add(9);
    tree.Add(13);
    tree.Print();
    tree.Remove(7);
    cout << " DONE " << endl;
    tree.Print();
    //
    //        ________[7]_______
    //       /                  \
        //     _[3]__            __[11]_
    //    /      \          /       \
        //  [1]      [5]      [9]       [13]
    //

    cout << " DONE " << endl;
    return 0;
}

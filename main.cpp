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
    
    int i = 9;
    
    while(i--){
    
    Tree tree(4);
    tree.Add(2);
    tree.Add(6);
    tree.Add(1);
    tree.Add(3);
    tree.Add(5);
    tree.Add(7);
    
    tree.Print();
    }
    return 0;
}

//

//
//  main.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-09-28.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//
/*
#include <iostream>
#include "BST.hpp"

int main(int argc, const char *argv[])
{
    //
    //        ________[4]_______
    //       /                  \
    //     _[2]__            __[6]_
    //    /      \          /      \
    //  [1]      [3]      [5]      [7]
    //

    int count = 100000000;
    while (count--)
    {
        auto tree = std::make_unique<Tree>(4);
        tree->Add(2);
        tree->Add(6);
        tree->Add(1);
        tree->Add(3);
        tree->Add(5);
        tree->Add(7);
        //tree->Print();

        // tree->Remove(1);
        tree->Remove(3);
        //tree->Remove(5);
        tree->Remove(7);
        tree->Remove(2);
        //tree->Print();
        tree->Remove(6);
        //tree->Remove(4);

        //tree->Print();
    }
    //tree->Print();

    return 0;
}
*/

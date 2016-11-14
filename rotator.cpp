//
//  rotator.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-14.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "rotator.hpp"
bool Rotator::RotateLeftAround(NodeUPtr &pivot_node) {
     /*        __[x]__
     //       /       \
     //   [xLeft]    _[y]_
     //             /     \
     //         [yLeft]  [yRight]
     */
    
     /*        __[y]__
     //       /       \
     //    _[x]_    [yRight]
     //   /     \
     //[xLeft]  [yLeft]
     */
    
    if (pivot_node) {
        Node *pivot_node_parent = pivot_node->parent;
        
        // Get all tree info before moving things around
        NodeUPtr x;
        bool was_the_old_pivot_a_left_node = pivot_node->is_left_node;
        // TODO : change to lamda
        if (pivot_node->is_left_node) {
            x = std::move(pivot_node_parent->left);
        } else if (!pivot_node->is_left_node && pivot_node_parent ) {
            x = std::move(pivot_node_parent->right);
        }
        else {x = std::move(pivot_node);}
        Height x_old_height = x->height;
        auto y = std::move(x->right);

        // y_left
        x->right = std::move(y->left);
        x->right->parent = x.get();
        x->right->is_left_node = false;
        
        // x
        y->left = std::move(x);
        y->left->parent = y.get();
        height_updater_.UpdateHeightOfNodeNonRecursively(y->left.get());
        y->left->is_left_node = true;
        
        // y
        if (was_the_old_pivot_a_left_node) {y->is_left_node = true;}
        height_updater_.UpdateHeightOfNodeNonRecursively(y.get());
        y->parent= pivot_node_parent;
        
        //TODO : Delete these liness
        if (y->height > x_old_height) {
            assert(0);//TODO : Check height_updater_.UpdateParentsHeightAfterAddingANode(y.get());
        } else if (y->height < x_old_height) {
            assert(0);
            //TODO : Check
            //height_updater_.UpdateParentsHeightAfterRemovingANode(y.get());
            
        } else {  // no update required
        }
        pivot_node = std::move(y);
        return true;
        
    } else {
        return false;
    }
}

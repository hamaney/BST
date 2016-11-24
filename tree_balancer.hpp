//
//  tree_balancer.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-23.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef tree_balancer_hpp
#define tree_balancer_hpp
#include <cassert>
#include "node.hpp"
#include <iostream>
/*
namespace BSTNS{
    namespace TreeBalancer {
        namespace PrivateHelper{}}}
*/
/*
 Cases

  []
  /L
 [] -> leftR
 /L
[]

 []
 /L
[] -> left then right rotation
 \R
 []

[]
 \R
 [] -> right r
  \R
  []

[]
 \R
 [] - >right then left rotation
 /L
[]

*/
namespace BSTNS{
namespace TreeBalancer {
bool BalanceTheTree(NodeUPtr& root);
namespace PrivateHelper{
bool isLeftHeavy_(NodeUPtr& root);
bool isRighttHeavy_(NodeUPtr& root);
bool isBalanced_(NodeUPtr& root);
int BalanceFactorOfNode_(const Node* const node);
}//End PrivateHelper::
}//End TreeBalancer::
}//End BSTNS

#endif /* tree_balancer_hpp */

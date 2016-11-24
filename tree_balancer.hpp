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
#include <iostream>
#include "node.hpp"
/*
namespace BSTNS{
    namespace TreeBalancer {
        namespace PrivateHelper{}}}
*/
/*
 Cases

      []
     /L
   []    -> leftR
  /L
[]

   []
  /L
[]       -> left then right rotation
  \R
   []

[]
  \R
   []    -> right r
     \R
      []

[]
  \R
   []    - >right then left rotation
  /L

*/
namespace BSTNS {
namespace TreeBalancer {
bool BalanceTheTree(NodeUPtr& root);
namespace PrivateHelper {
bool isLeftHeavy_(const Node* const node);
bool isRightHeavy_(const Node* const node);
bool isBalanced_(const Node* const node);
bool isPerfectlyBalanced_(const Node* const node);
int BalanceFactorOfNode_(const Node* const node);
bool isLeftHeavyWithLeftHeavyChild_(const Node* const node);
bool isLeftHeavyWithRightHeavyChild_(const Node* const node);
bool isRightHeavyWithRightHeavyChild_(const Node* const node);
bool isRightHeavyWithLeftHeavyChild_(const Node* const node);
}  // End PrivateHelper::
}  // End TreeBalancer::
}  // End BSTNS

#endif /* tree_balancer_hpp */

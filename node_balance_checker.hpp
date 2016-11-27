//
//  node_balance_checker.hpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-23.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef node_balance_checker_hpp
#define node_balance_checker_hpp
#include <cassert>
#include <iostream>
#include "node.hpp"

/*
namespace BSTNS{
    namespace NodeBalanceChecker {
        namespace PrivateHelper{}}}
*/
namespace BSTNS {
namespace NodeBalanceChecker {
bool IsBalancedNode(const Node* const node);
bool IsBalancedTree(const Node* const current_root);
/*
To chrck for
      []
     /L BF=2
   []
  /L BF=1
[]
*/
bool IsLeftLeft(const Node* const node);
/*To chrck for
   []
  /L BF=2
[]
  \R BF=-1
   []
*/
bool IsLeftRight(const Node* const node);
/*To chrck for
[]
  \R BF=-2
   []
     \R BF=-1
      []
*/
bool IsRightRight(const Node* const node);
/*To chrck for
[]
  \R BF=-2
   []
  /L BF=1
[]
*/
bool IsRightLeft(const Node* const node);
namespace PrivateHelper {
bool IsLeftHeavy_(const Node* const node);
bool IsRightHeavy_(const Node* const node);
int BalanceFactorOfNode_(const Node* const node);
}  // End PrivateHelper::
}  // End TreeBalancer::
}  // End BSTNS

#endif /* node_balance_checker_hpp */

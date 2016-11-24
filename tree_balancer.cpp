//
//  tree_balancer.cpp
//  BST
//
//  Created by Abdulrhman Mohamed on 2016-11-23.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "tree_balancer.hpp"
using namespace BSTNS::TreeBalancer::PrivateHelper;
namespace BSTNS {
namespace TreeBalancer {

// bool BalanceTheTree(NodeUPtr& node) {}

namespace PrivateHelper {

bool isLeftHeavy_(const Node* const node) {
  return BalanceFactorOfNode_(node) >= 2;
}
bool isRightHeavy_(const Node* const node) {
  return BalanceFactorOfNode_(node) <= -2;
}
bool isBalanced_(const Node* const node) {
  return ((BalanceFactorOfNode_(node) < 2) and
          (BalanceFactorOfNode_(node) > -2));
}
bool isPerfectlyBalanced_(const Node* const node) {
  return (BalanceFactorOfNode_(node) == 0);
}

int BalanceFactorOfNode_(const Node* const node) {
  if (!node) {
    assert(0);
  } else {
    int left_child_balance_factor, right_child_balance_factor;
    if (!node->left) {
      left_child_balance_factor = -1;
    } else {
      left_child_balance_factor = node->left->height;
    }
    if (!node->right) {
      right_child_balance_factor = -1;
    } else {
      right_child_balance_factor = node->right->height;
    }
    return left_child_balance_factor - right_child_balance_factor;
  }
}
bool isLeftHeavyWithLeftHeavyChild_(const Node* const node) {
  /*if(isLeftHeavy_(node)){
    return isLeftHeavy_(node->left.get());
  }else {
    return false;
    }
    */
  // return (isLeftHeavy_(node))? (BalanceFactorOfNode_(node->left.get())>=1):
  // false ;
  return (isLeftHeavy_(node)) ? (BalanceFactorOfNode_(node->left.get()) == 1)
                              : false;
}
bool isLeftHeavyWithRightHeavyChild_(const Node* const node) {
  return (isRightHeavy_(node)) ? (BalanceFactorOfNode_(node->right.get()) == -1)
                              : false;
}
// bool isRightHeavyWithRightHeavyChild_(const Node* const node) {}
// bool isRightHeavyWithLeftHeavyChild_(const Node* const node) {}
}  // End PrivateHelper::
}  // End TreeBalancer::
}  // End BSTNS::
